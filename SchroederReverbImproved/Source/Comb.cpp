/*
  ==============================================================================

    Comb.cpp
    Created: 15 Oct 2014 8:55:20pm
    Author:  Keith Hearne

  ==============================================================================
*/

#include "Comb.h"



//////////////////////////////////////////////////////////
//  BASIC COMB FILTER CLASS
//////////////////////////////////////////////////////////

//constructor / destructor
Comb::Comb(const int sr, const float d_ms, const float d_ms_max, const float g){
    gain = g;
    delay = new DelayLine(sr, d_ms, d_ms_max);
    lpFilter = new Lowpass(44100, 10000.0f);
}

Comb::~Comb(){
    delete delay;
    delete lpFilter;
}

//getters
float Comb::getGain(){return gain;}
float Comb::getDelayTimeMS(){return delay->getDelayTimeMS();}

//setters
void Comb::setGain(const float g){gain = g;}
void Comb::setDelayTimeMS(const float sr, const float d_ms){return delay->setDelayTimeMS(sr, d_ms);}

//business methods
float Comb::next(const float in){
    //KH***return delay->next(in, gain);
    float dL = delay->readDelay();
    
    //float lpOut = dL * gain;
    //float lpRetVal = lpFilter->next(lpOut);
    float lpRetVal = lpFilter->next(dL);
    
    //float dLW = in + lpRetVal;
    float dLW = in + lpRetVal*gain;
    delay->writeDelay(dLW);
    return dL;
    
}
