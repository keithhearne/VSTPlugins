/*
  ==============================================================================

    Comb.cpp
    Created: 15 Oct 2014 8:55:20pm
    Author:  Keith Hearne
    
    Based on model that Schroeder proposed in 1962 paper presenting his
    initial reverb designs, that uses a single feedback delay line
    
    A Basic Comb IIR Filter class that sets delay and gain and allows
    access to each, while providing comb filter processing function

  ==============================================================================
*/

#include "Comb.h"


//////////////////////////////////////////////////////////
//  BASIC COMB FILTER CLASS
//////////////////////////////////////////////////////////

//-------------------------------------------------------------------------
// Constructor :
// Predefined sample rate = 44100, delay time, max delay time and gain
// creates a new DelayLine and sets the input gain
//-------------------------------------------------------------------------
Comb::Comb(const int sr, const float d_ms, const float d_ms_max, const float g){
    gain = g;
    delay = new DelayLine(sr, d_ms, d_ms_max);
}

//-------------------------------------------------------------------------
// Destructor :
// deletes the delay
//-------------------------------------------------------------------------
Comb::~Comb(){
    delete delay;
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

//-------------------------------------------------------------------------
// resetDelay  :
// calls the reset on the delayline which resets and fills the buffer
//-------------------------------------------------------------------------
void Comb::resetDelay(){
 
    delay->resetDelay();
    
    return;
    
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//  next    : Function to process next sample input in
//          : The comb filter process involves reading the delay 
//          : at the current readindex position (delay->readDelay)
//          : scaling this delay value by the combs gain (gain*dL)
//          : and writing this value back into the delay line
//          : at the appropriate write position 
//          : (delay->writeDelay(dLW))
//
//  in      :   input sample form the audio buffer
//  
//------------------------------------------------------------------
//------------------------------------------------------------------
float Comb::next(const float in){
    //read the delay value
    float dL = delay->readDelay();
    
    //add the input sample plus the delay scaled by the gain
    float dLW = in + gain*dL;
    
    //write this back into the elay buffer
    delay->writeDelay(dLW);
    
    //return the delay value
    return dL;
    
}
