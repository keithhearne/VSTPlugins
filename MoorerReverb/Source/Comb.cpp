/*
  ==============================================================================

    Comb.cpp
    Created: 15 Oct 2014 8:55:20pm
    Author:  Keith Hearne
    
    Based on model that Moorer presented in his 1979 paper and 
    reverb designs, that uses a low pass comb filter
    
    
    A Low Pass Comb IIR Filter class that sets delay and gain and allows
    access to each, while passing processing of the feedback loop through
    a low pass filter to filter some high frequency content, the filtering
    of each reflection. 

  ==============================================================================
*/

#include "Comb.h"


//////////////////////////////////////////////////////////
//  BASIC COMB FILTER CLASS
//////////////////////////////////////////////////////////

//-------------------------------------------------------------------------
// Constructor :
// Predefined sample rate = 44100, delay time, max delay time and gain
// and lowpass cutoff frequency. creates a new DelayLine and sets 
// the input gain and initiates the low pass filter
//-------------------------------------------------------------------------
Comb::Comb(const int sr, const float d_ms, const float d_ms_max, const float g, const float lp_freq){
    gain = g;
    delay = new DelayLine(sr, d_ms, d_ms_max);
    lpFilter = new Lowpass(44100, lp_freq);
}

//-------------------------------------------------------------------------
// Destructor :
// deletes the delay and filter
//-------------------------------------------------------------------------
Comb::~Comb(){
    delete delay;
    delete lpFilter;
}

//getters
//-------------------------------------------------------------------------
// getGain  :
// return the gain scalar value
//-------------------------------------------------------------------------
float Comb::getGain(){return gain;}

//-------------------------------------------------------------------------
// getDelayTimeMS  :
// return the delay time in milliseconds
//-------------------------------------------------------------------------
float Comb::getDelayTimeMS(){return delay->getDelayTimeMS();}

//setters
//-------------------------------------------------------------------------
// setGain  :
// set the scalar value for the gain of the filter
//-------------------------------------------------------------------------
void Comb::setGain(const float g){gain = g;}

//--------------------------------------------------------------------------------
//  setDelayTimeMS
//  Setter function sets delay time and from milliseconds
//  and passes it to the delayline which converts to discrete time samples
//
//--------------------------------------------------------------------------------
void Comb::setDelayTimeMS(const float sr, const float d_ms){return delay->setDelayTimeMS(sr, d_ms);}

//--------------------------------------------------------------------------------
//  setLPF
//  Setter function sets the cutoff frequency of the low pass filter in the
//  feedback loop
//--------------------------------------------------------------------------------
void Comb::setLPF(const float cutoff_freq){ return lpFilter->setCutoff(44100, cutoff_freq);};

//business methods
//------------------------------------------------------------------
//------------------------------------------------------------------
//  next    : Function to process next sample input in
//          : The comb filter process involves reading the delay 
//          : at the current readindex position (delay->readDelay)
//          : scaling this delay value by the combs gain (gain*dL)
//          : passing this value through the low pass filter
//          : and writing this value back into the delay line
//          : at the appropriate write position 
//          : (delay->writeDelay(dLW))
//
//  in      :   input sample form the audio buffer
//  
//------------------------------------------------------------------
//------------------------------------------------------------------
float Comb::next(const float in){
    //read delay
    float dL = delay->readDelay();
    
    //attenuate with gain
    float dlAttn = dL * gain;
    //pass through low pass filter
    float lpOut = lpFilter->next(dlAttn);
    
    //combine output for feedback loop
    float dLW = in + lpOut;
    //write feedback loop back to delay buffer
    delay->writeDelay(dLW);
    
    //return the initially read delay
    return dL;
    
}
