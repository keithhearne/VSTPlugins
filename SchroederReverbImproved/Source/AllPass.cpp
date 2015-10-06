/*
  ==============================================================================

    AllPass.cpp
    Created: 15 Oct 2014 8:55:39pm
    Author:  Keith Hearne

  ==============================================================================
*/

#include "AllPass.h"


//////////////////////////////////////////////////////////
//  ALLPASS FILTER CLASS
//////////////////////////////////////////////////////////

//constructor
Allpass::Allpass(const int sr, const float d_ms, const float d_ms_max, const float g){
    gain = g;
    delay = new DelayLine(sr, d_ms, d_ms_max);
}

Allpass::~Allpass(){
    delete delay;
}

//getters
float Allpass::getGain(){return gain;}
float Allpass::getDelayTimeMS(){return delay->getDelayTimeMS();}

//setters
void Allpass::setGain(const float g){gain = g;}
void Allpass::setDelayTimeMS(const float sr, const float d_ms){return delay->setDelayTimeMS(sr, d_ms);}

//business methods
float Allpass::next(const float in){
  //KH****  float out = delay->next(in, gain);
  //KH***  return out + (in * -gain);
    float dL = delay->readDelay();
    float fW = in + (gain*dL);
    float out = -gain*fW + dL;
    delay->writeDelay(fW);
    return out;
}