/*
  ==============================================================================

    DelayLine.cpp
    New version of DelayLine which uses fractional delay
    For use with Schroeder Reverb
    
    Created: 15 Oct 2014 5:18:25pm
    Author:  Keith Hearne

  ==============================================================================
*/

#include "DelayLine.h"

//helper functions
inline float numSamplesFromMSf(const int sr, const float d_ms){
    return sr * d_ms * .001;
}

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
//  DELAY LINE CLASS (for use with Schroeder Reverb)
//////////////////////////////////////////////////////////

//constructor / destructor
DelayLine::DelayLine(const int sr, const float d_ms, const float d_max){
    //assert(d_ms <= d_ms_max);//check bound on delay time
    
    buffer = NULL;
    readPosA = writePos = 0;
    
    //float d_ms_max = 2000.0f;
    delay_samples = 0.0f;
    delay_ms = d_ms;
    
    MAX_DELAY_SAMPLES = ceil(numSamplesFromMSf(sr, d_max));
    MAX_DELAY_MS = MAX_DELAY_SAMPLES * 1000.0f / sr; //make sure float version is set with to integer-rounded buffer size
    
    float delay_samplesf = numSamplesFromMSf(sr, d_ms);
    delay_samples = floor(delay_samplesf);
    fraction = delay_samplesf - delay_samples;//storing fractional delay time, will be interpolated
    
    buffer = new float[MAX_DELAY_SAMPLES];
    memset(buffer, 0, MAX_DELAY_SAMPLES*sizeof(float));
    
    //KH***added
    //setDelayTimeMS(sr,delay_ms);
}

DelayLine::~DelayLine(){
    delete[] buffer;
}

//getters
float DelayLine::getDelayTimeMS(){return delay_ms;}
float DelayLine::getMaxDelayTimeMS(){return MAX_DELAY_MS;}

//setters
void DelayLine::setDelayTimeMS(const int sr, const float d_ms){
    assert(d_ms <= MAX_DELAY_MS);//check bound on delay time
    
    float delay_samplesf = numSamplesFromMSf(sr, d_ms);
    delay_samples = floor(delay_samplesf);
    fraction = delay_samplesf - delay_samples;//storing fractional delay time, output will be interpolated
    
    readPosA = writePos - delay_samples; //KHH***(int)delay_samples;
    if(readPosA < 0)
        readPosA += MAX_DELAY_SAMPLES;
        
        
}

void DelayLine::setDelay(float d){
    //receiving the delay value through here in milliseconds 0 to 2000
    delay_ms = d;
    setDelayTimeMS(44100,delay_ms);
};


float DelayLine::readDelay(){
       //output of delay at readPos
    float yn = buffer[readPosA];
    
    //if delay < 1 sample, interpolate between x(n) and x(n-1)
   /* if(readPosA == writePos && delay_samples < 1.00)
    {
            yn = xn;
    }
    */
    
    //read location at n-1, one behind yn
    int readPos_minus1 = readPosA - 1;
    if(readPos_minus1 < 0)
        readPos_minus1 = MAX_DELAY_SAMPLES - 1;   //MAX_DELAY_SAMPLES - 1 is the last location of the buffer
        
    //get y(n-1)
    float yn_minus1 = buffer[readPos_minus1];
    
    //perform linear interpolation of : (0,yn) and (1,yn_minus1) by the ammount of fractional delay(fraction)
    return linInterp(0, 1, yn, yn_minus1, fraction);
}

void DelayLine::writeDelay(float in){
    
    buffer[writePos] = in;
       
    writePos++;
    if(writePos >= MAX_DELAY_SAMPLES)
        writePos = 0;
        
    readPosA++;
    if(readPosA >= MAX_DELAY_SAMPLES)
        readPosA = 0;
}

//business function
//KH***float DelayLine::next(const float in, const float gain){
float DelayLine::next(const float in){
        
    //input
    float xn = in;
/** readDelay    
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
readDelay end **/ 

    //if delay value is zero just pass input out
    float yn;
    if(delay_samples == 0)
        yn = xn;
    else
        yn = readDelay();  //***interp was here before the split of functions

    writeDelay(xn);
    //****float out = buffer[writePos];
    float out = yn;

/**writeDelay

    //write the input to the delay
    buffer[writePos] = in; //KHH*****+ yn*gain;

 
    
    writePos++;
    if(writePos >= MAX_DELAY_SAMPLES)
        writePos = 0;
        
    readPosA++;
    if(readPosA >= MAX_DELAY_SAMPLES)
        readPosA = 0;
writeDelay End **/        
    
    return out;
        
}

void DelayLine::resetBuffer(){
    
    if(buffer)
        delete [] buffer;
        
    buffer = new float[MAX_DELAY_SAMPLES];
    
    resetDelay();
    setDelayTimeMS(44100,delay_ms);
    
    return;
    
}
        
void DelayLine::resetDelay(){
 
    if(buffer)
        memset(buffer, 0, MAX_DELAY_SAMPLES*sizeof(float));
    
    readPosA = writePos = 0;
    
    return;
    
}
