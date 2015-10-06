/*
  ==============================================================================

    AllPass.cpp
    Created: 15 Oct 2014 8:55:39pm
    Author:  Keith Hearne

    Based on model that Schroeder proposed in 1962 paper presenting his
    initial reverb designs, that uses a feedback delay line with feedforward
    line.
    
    A Basic All-pass IIR Filter class that sets delay and gain and allows
    access to each, while providing comb filter processing function
    
  ==============================================================================
*/

#include "AllPass.h"


//////////////////////////////////////////////////////////
//  ALLPASS FILTER CLASS
//////////////////////////////////////////////////////////

//-------------------------------------------------------------------------
// Constructor :
// Predefined sample rate = 44100, delay time, max delay time and gain
// creates a new DelayLine and sets the input gain
//-------------------------------------------------------------------------
Allpass::Allpass(const int sr, const float d_ms, const float d_ms_max, const float g){
    gain = g;
    delay = new DelayLine(sr, d_ms, d_ms_max);
}

//-------------------------------------------------------------------------
// Destructor :
// deletes the delay
//-------------------------------------------------------------------------
Allpass::~Allpass(){
    delete delay;
}

//getters
//-------------------------------------------------------------------------
// getGain  :
// return the gain scalar value
//-------------------------------------------------------------------------
float Allpass::getGain(){return gain;}

//-------------------------------------------------------------------------
// getDelayTimeMS  :
// return the delay time in milliseconds
//-------------------------------------------------------------------------
float Allpass::getDelayTimeMS(){return delay->getDelayTimeMS();}

//setters
//-------------------------------------------------------------------------
// setGain  :
// set the scalar value for the gain of the filter
//-------------------------------------------------------------------------
void Allpass::setGain(const float g){gain = g;}

//--------------------------------------------------------------------------------
//  setDelayTimeMS
//  Setter function sets delay time and from milliseconds
//  and passes it to the delayline which converts to discrete time samples
//
//--------------------------------------------------------------------------------
void Allpass::setDelayTimeMS(const float sr, const float d_ms){return delay->setDelayTimeMS(sr, d_ms);}

//-------------------------------------------------------------------------
// resetDelay  :
// calls the reset on the delayline which resets and fills the buffer
//-------------------------------------------------------------------------
void Allpass::resetDelay(){
    
    delay->resetDelay();
    
    return;
    
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//  next    : Function to process next sample input in
//          : The all-pass filter process involves reading the delay 
//          : at the current readindex position (dL)
//          : scaling this delay value by the filter gain (gain*dL)
//          : and writing this value back into the delay line
//          : at the appropriate write position (fW)
//          : and outputing the -gain*fW + dL
//
//  in      :   input sample form the audio buffer
//  
//------------------------------------------------------------------
//------------------------------------------------------------------
float Allpass::next(const float in){
    //read delay value from buffer
    float dL = delay->readDelay();
    // for the filter write or feedback input to buffer
    float fW = in + (gain*dL);
    //form the output of all-pass  (delay + in*-gain)
    float out = -gain*fW + dL;      
    // write feedback loop input back to delay buffer
    delay->writeDelay(fW);
    return out;
}