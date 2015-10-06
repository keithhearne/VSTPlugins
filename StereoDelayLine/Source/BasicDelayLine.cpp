/*
  ==============================================================================

    BasicDelayLine.cpp
    New version of BasicDelayLine that also accepts an external feedback path
    as input, and which uses fractional delay
    
    Created: 9 Sep 2014 5:18:25pm
    Author:  Keith Hearne

  ==============================================================================
*/

#include "BasicDelayLine.h"

//helper functions
//-------------------------------------------------------------------------
// numSamplesFromMSf :
// Determine the number of samples from the number of milliseconds delay
// passed to function
//-------------------------------------------------------------------------
inline float numSamplesFromMSf(const int sr, const float d_ms){
    return sr * d_ms * .001;
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
//  BASIC VARIABLE DELAY LINE CLASS (feedback optional)
//////////////////////////////////////////////////////////

//-------------------------------------------------------------------------
// Constructor :
// Predefined sample rate = 44100, feedback level & delay = 0, mixlevel=50%
// set read and write index for delay line
// set max delay to 2 seconds
// create a max delay buffer
//-------------------------------------------------------------------------
BasicDelayLine::BasicDelayLine(const int sr, const float d_ms, const float fb, const float mix){
    //assert(d_ms <= d_ms_max);//check bound on delay time
    
    buffer = NULL;
    readPosA = writePos = feedback = mixLevel = 0;
    delay_bypass = 0;
    
    //external feedback not enabled
    useExternalFeedback = false;
    
    //max delay of 2 seconds
    float d_ms_max = 2000.0f;
    delay_samples = 0.0f;
    delay_ms = d_ms;
   
    feedback = fb;
    mixLevel = mix;
    
    MAX_DELAY_SAMPLES = ceil(numSamplesFromMSf(sr, d_ms_max));
    MAX_DELAY_MS = MAX_DELAY_SAMPLES * 1000.0f / sr; //make sure float version is set with to integer-rounded buffer size
    
    float delay_samplesf = numSamplesFromMSf(sr, d_ms);
    delay_samples = floor(delay_samplesf);
    fraction = delay_samplesf - delay_samples;//storing fractional delay time, will be interpolated
    
    buffer = new float[MAX_DELAY_SAMPLES];
    memset(buffer, 0, MAX_DELAY_SAMPLES*sizeof(float));
    
}

//-------------------------------------------------------------------------
// Destructor :
// delete delay buffer
//-------------------------------------------------------------------------
BasicDelayLine::~BasicDelayLine(){
    delete[] buffer;
}

//getters
//-------------------------------------------------------------------------
// getDelayTimeMS :
// return the delay in milliseconds
//-------------------------------------------------------------------------
float BasicDelayLine::getDelayTimeMS(){return delay_ms;}

//-------------------------------------------------------------------------
// getFeedback :
// return the feedback value
//-------------------------------------------------------------------------
float BasicDelayLine::getFeedback(){return feedback;}

//-------------------------------------------------------------------------
// getMix :
// return the mix level, set to 50% by default
//-------------------------------------------------------------------------
float BasicDelayLine::getMix(){return mixLevel;}

//-------------------------------------------------------------------------
// getByPass :
// return the boolean value indicating if plugin is bypassed or not
//-------------------------------------------------------------------------
bool BasicDelayLine::getByPass(){return delay_bypass;}

//-------------------------------------------------------------------------
// getCurrentFeedbackOutput :
// return delay from the buffer * feedback value
//-------------------------------------------------------------------------
float BasicDelayLine::getCurrentFeedbackOutput(){
        //current feedback is feedback*output
        return (feedback*buffer[readPosA]);
};

//setters
//--------------------------------------------------------------------------------
//  Setter function that determines read position index
//  read position is determined by subtracting the number of samples to delay
//  from the write position index
//
//  readIndex = writeIndex - number of sample delay
//
//--------------------------------------------------------------------------------
void BasicDelayLine::setDelayTimeMS(const int sr, const float d_ms){
    assert(d_ms <= MAX_DELAY_MS);//check bound on delay time
    
    //function returns the number of samples from a delay in millsecond value
    //  number of samples = sr * d_ms * .001
    float delay_samplesf = numSamplesFromMSf(sr, d_ms);
    delay_samples = floor(delay_samplesf);
    
    //storing fractional delay time, output will be interpolated
    fraction = delay_samplesf - delay_samples;
    
    //the read index is determined from the write index minus the number of
    //samples to delay by
    readPosA = writePos - (int)delay_samples;
    if(readPosA < 0)
        readPosA += MAX_DELAY_SAMPLES;
              
}

//-------------------------------------------------------------------------
// setDelay :
// set the delay in milliseconds by the delay value passed to function
//-------------------------------------------------------------------------
void BasicDelayLine::setDelay(float d){
    //receiving the delay value through here in milliseconds 0 to 2000
    delay_ms = d;
    setDelayTimeMS(44100,delay_ms);
};

//-------------------------------------------------------------------------
// setFeedback :
// set the feedback value passed to function -1 to 1
//-------------------------------------------------------------------------
void BasicDelayLine::setFeedback(float f){
    //receiving the feedback here as a value between -100 and +100
    feedback = f/100;
};

//-------------------------------------------------------------------------
// setMix :
// set the mix level, value from plugin is 0-100, value in function 0-1
//-------------------------------------------------------------------------
void BasicDelayLine::setMix(float m){
    // receiving the mix value through here as value between 0 and 100
    mixLevel = m/100;
};

//-------------------------------------------------------------------------
// setByPass :
// set the bypass value based on bypass value received from plugin
//-------------------------------------------------------------------------
void BasicDelayLine::setByPass(bool bp){
    // receiving the mix value through here as value between 0 and 100
    delay_bypass = bp;
};

//-------------------------------------------------------------------------
// setCurrentFeedbackInput :
// set the feedback value being passed from the feedback parameter on UI
//-------------------------------------------------------------------------
void BasicDelayLine::setCurrentFeedbackInput(float fb){
    //set the feedback sample
    feedbackIn = fb;
};
    
//-------------------------------------------------------------------------
// setUseExternalFeedback :
// set the whether feedback value should be read from an external input
// such as the other feedback channel output instead of internal
//-------------------------------------------------------------------------
void BasicDelayLine::setUseExternalFeedback(bool b){
    //enable or disable an external feedback source
    useExternalFeedback = b;
};


//business function
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//
//  The following function is the workhorse of the delay line
//  It uses terms similar to the differential equation for delay
//
//      x(n)                : the input at sample n
//      y(n)                : the output at sample n after delay processing
//      buffer              : the circular buffer used
//      readPosA            : the read index of the delay buffer
//      writePos            : the write index of the delay buffer
//      MAX_DELAY_SAMPLES   : Max size of delay buffer
//  
//      y(n) = x(n) + x(n - D)              'delay with no feedback
//
//      y(n) = x(n - D) + fb*y(n - D)       'delay with feedback
//
//      y(n) = x(n) + x(n – D) - fb*x(n-D) + fb*y(n-D)  'feedback with wet/dry mix
//
//      MAX_DELAY_SAMPLES = sr * d_ms * .001;
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

float BasicDelayLine::next(const float in){
    
    if(delay_bypass)
        return in;
        
    //input
    float xn = in;
    
    //output of delay at readPos
    float yn = buffer[readPosA];
    
    //if delay < 1 sample, interpolate between x(n) and x(n-1)
    if(readPosA == writePos && delay_samples < 1.00)
    {
            yn = xn;
    }
    
    //read location at n-1, one behind yn
    int readPos_minus1 = readPosA - 1;
    if(readPos_minus1 < 0)
        readPos_minus1 = MAX_DELAY_SAMPLES - 1;   //MAX_DELAY_SAMPLES - 1 is the last location of the buffer
        
    //get y(n-1)
    float yn_minus1 = buffer[readPos_minus1];
    
    //perform linear interpolation of : (0,yn) and (1,yn_minus1) by the ammount of fractional delay(fraction)
    float interp = linInterp(0, 1, yn, yn_minus1, fraction);
    
    //if delay value is zero just pass input out
    if(delay_samples == 0)
        yn = xn;
    else
        yn = interp;

    //write the input to the delay
    //check if External Feedback path is enabled
    if(!useExternalFeedback)
        buffer[writePos] = xn + feedback*yn;
    else
        buffer[writePos] = xn + feedbackIn;
    
    //create wet level and write to output buffer
    float out = mixLevel*yn + (1.0 - mixLevel)*xn;
    
    //wrap values if they exceed bounds
    writePos++;
    if(writePos >= MAX_DELAY_SAMPLES)
        writePos = 0;
        
    readPosA++;
    if(readPosA >= MAX_DELAY_SAMPLES)
        readPosA = 0;
        
    
    return out;
        
}

//-------------------------------------------------------------------------
// resetBuffer :
// delete contents of buffer and instantiate a new buffer
//-------------------------------------------------------------------------
void BasicDelayLine::resetBuffer(){
    
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
void BasicDelayLine::resetDelay(){
 
    if(buffer)
        memset(buffer, 0, MAX_DELAY_SAMPLES*sizeof(float));
    
    
    readPosA = writePos = 0;
    delay_bypass = 0;
    
    return;
    
}
