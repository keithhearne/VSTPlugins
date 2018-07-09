/*
  ==============================================================================

    ERTapDelayLine.cpp
    Tap Delay used for Early Reflection Generation as proposed by Moorers design
    In Moorers 1979 paper About This Reverberation Business he took a model of
    real room impulse responses for Early Reflection Generation from impulses
    recorded in the Boston Symphony Hall.
    
    These values are used here in a multi-tap setup to provide the summed
    output of the 18 taps (the first tap will be the input impulse, added at 
    the reverb generation stage) to provide an early reflection generator.
    
    Created: 16 Nov 2014 5:18:25pm
    Author:  Keith Hearne

  ==============================================================================
*/

#include "ERTapDelayLine.h"

//helper functions
//-------------------------------------------------------------------------
// numSamplesFromMSf :
// Determine the number of samples from the number of milliseconds delay
// passed to function
//-------------------------------------------------------------------------
inline float tapNumSamplesFromMSf(const int sr, const float d_ms){
    return sr * d_ms * 0.001;
}

//----------------------------------------------------------------------
//  Linear Interpolation Function
//  x1  :  weighting 1
//  x2  :  weighting 2
//  y1  :  output y(n) at read index in buffer
//  y2  :  output y(n-1) at read index minus 1 in buffer
//  x   :  fractional value between samples
//----------------------------------------------------------------------
inline float linInterp(float x1, float x2, float y1, float y2, float x){
   	float denom = x2 - x1;
	if(denom == 0)
		return y1; // should not ever happen

	// calculate decimal position of x
	float dx = (x - x1)/(x2 - x1);

	// use weighted sum method of interpolating
	float result = dx*y2 + (1-dx)*y1;

	return result; 
}


//////////////////////////////////////////////////////////
//  ER TAP DELAY LINE CLASS (for use with Moorer Reverb)
//////////////////////////////////////////////////////////

//-------------------------------------------------------------------------
// Constructor :
// Predefined sample rate = 44100, delay = 0, max delay
// set read and write index for delay line
// set max delay set from decay factor in reverb
// create a max delay buffer
//-------------------------------------------------------------------------
ERTapDelayLine::ERTapDelayLine(const int sr, const float d_ms, const float d_max){
    //assert(d_ms <= d_ms_max);//check bound on delay time
    
    buffer = NULL;
    readPosA = writePos = 0;
    
    delay_samples = accumulatedTaps = 0.0f;
    delay_ms = d_ms;
    
    MAX_DELAY_SAMPLES = ceil(tapNumSamplesFromMSf(sr, d_max));
    MAX_DELAY_MS = MAX_DELAY_SAMPLES * 1000.0f / sr; //make sure float version is set with to integer-rounded buffer size
    
    float delay_samplesf = tapNumSamplesFromMSf(sr, d_ms);
    delay_samples = floor(delay_samplesf);
    
    //storing fractional delay time, will be interpolated
    fraction = delay_samplesf - delay_samples;
    
    buffer = new float[MAX_DELAY_SAMPLES];
    memset(buffer, 0, MAX_DELAY_SAMPLES*sizeof(float));
}

//-------------------------------------------------------------------------
// Destructor :
// delete delay buffer
//-------------------------------------------------------------------------
ERTapDelayLine::~ERTapDelayLine(){
    delete[] buffer;
}

//getters
//-------------------------------------------------------------------------
// getDelayTimeMS :
// return the delay in milliseconds
//-------------------------------------------------------------------------
float ERTapDelayLine::getDelayTimeMS(){return delay_ms;}

//--------------------------------------------------------------------------------
//  getMaxDelayTimeMS :
//  return the Max delay time in Miliiseconds
//--------------------------------------------------------------------------------
float ERTapDelayLine::getMaxDelayTimeMS(){return MAX_DELAY_MS;}

//setters
//--------------------------------------------------------------------------------
//  Setter function that determines read position index
//  read position is determined by subtracting the number of samples to delay
//  from the write position index
//
//  readIndex = writeIndex - number of sample delay
//
//--------------------------------------------------------------------------------
void ERTapDelayLine::setDelayTimeMS(const int sr, const float d_ms){
    assert(d_ms <= MAX_DELAY_MS);//check bound on delay time
    
    float delay_samplesf = tapNumSamplesFromMSf(sr, d_ms);
    this->delay_samples = floor(delay_samplesf);
    
    //storing fractional delay time, output will be interpolated
    fraction = delay_samplesf - delay_samples;
    
    readPosA = writePos - delay_samples;
    
    //wrap index if bounds exceeded
    if(readPosA < 0)
        readPosA += MAX_DELAY_SAMPLES;
        
        
}

//-------------------------------------------------------------------------
// setDelay :
// set the delay in milliseconds by the delay value passed to function
//-------------------------------------------------------------------------
void ERTapDelayLine::setDelay(float d){
    //receiving the delay value through here in milliseconds 0 to 2000
    delay_ms = d;
    setDelayTimeMS(44100,delay_ms);
};

//----------------------------------------------------
//----------------------------------------------------
//  readDelay : this is early reflections delay line
//
//  each read of the delay line gives each of the 
//  19 taps scaled by gains for a 19 Impulse FIR 
//  as laid out in Moorerspaper. Values are 
//  all hardcoded and initialised in the .h file
//----------------------------------------------------
//----------------------------------------------------
float ERTapDelayLine::readDelay(float in){

    float interpVal = 0.0f;
    accumulatedTaps = 0.0f;
    //first tap is the input sample at gain of 1
    accumulatedTaps = in;

   //output of delay at readPos
    float yn = 0.0f;
    
    //loop through the amount of ER_TAP Values accumulate the delay*gain
    //each time through the loop    
    for(int i=0; i < (sizeof(ER_TAPS)/sizeof(ER_TAPS[0])); i++ ){
        
        //set the delay samples for this specific TAP, which aligns the read index
        setDelay(ER_TAPS[i]);
        yn = buffer[readPosA];

        //read location at n-1, one behind yn
        int readPos_minus1 = readPosA - 1;
        if(readPos_minus1 < 0)
            readPos_minus1 = MAX_DELAY_SAMPLES - 1;   //MAX_DELAY_SAMPLES - 1 is the last location of the buffer
            
        //get y(n-1)
        float yn_minus1 = buffer[readPos_minus1];
        
        //perform linear interpolation of : (0,yn) and (1,yn_minus1) by the ammount of fractional delay(fraction)
        interpVal = linInterp(0, 1, yn, yn_minus1, fraction);
        
        //This is the accumulation of tap delay values with the respective gain
        accumulatedTaps +=  interpVal * ER_GAINS[i];
    }
    
    return accumulatedTaps;

}

//--------------------------------------------------------------------------------
//  writeDelay :
//
//  The following function writes into the delay buffer at write index
//---------------------------------------------------------------------------------
void ERTapDelayLine::writeDelay(float in){
    
    //write the input sample into the write position of the buffer
    buffer[writePos] = in;
       
    //increment indexes and wrap if bounds exceeded
    writePos++;
    if(writePos >= MAX_DELAY_SAMPLES)
        writePos = 0;
        
    readPosA++;
    if(readPosA >= MAX_DELAY_SAMPLES)
        readPosA = 0;
}

//business function
//--------------------------------------------------------------------------------
//  next    :
//  The following function is the workhorse of the delay line, but the filters
//  in the reverb will call the individual read/write function so as to have
//  more control over manipulating the inputs and outputs.
//
//      x(n)                : the input at sample n
//      y(n)                : the output at sample n after delay processing
//  
//      y(n) = x(n) + x(n - D)              'delay with no feedback
//
//  read the interpolated value from the delay line and write input back to buffer
//
//---------------------------------------------------------------------------------
float ERTapDelayLine::next(const float in){
        
    //input
    float xn = in;

    //if delay value is zero just pass input out
    float yn;
    yn = readDelay(in);

    writeDelay(xn);
    float out = yn;
       
    return out;
        
}

//-------------------------------------------------------------------------
// resetBuffer :
// delete contents of buffer and instantiate a new buffer
//-------------------------------------------------------------------------
void ERTapDelayLine::resetBuffer(){
    
    if(buffer)
        delete [] buffer;
        
    buffer = new float[MAX_DELAY_SAMPLES];
    
    resetDelay();
    setDelayTimeMS(44100,delay_ms);
    
    return;
    
}

//-------------------------------------------------------------------------
// resetDelay :
// reset the delay buffer by filling with 0's, reset all indexes and bypass
//-------------------------------------------------------------------------
void ERTapDelayLine::resetDelay(){
 
    if(buffer)
        memset(buffer, 0, MAX_DELAY_SAMPLES*sizeof(float));
    
    readPosA = writePos = 0;
    
    return;
    
}
