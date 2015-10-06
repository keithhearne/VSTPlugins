/*
  ==============================================================================

    AllPass.h
    Created: 15 Oct 2014 8:55:30pm
    Author:  Keith Hearne
    
    Based on model that Schroeder proposed in 1962 paper presenting his
    initial reverb designs, that uses a feedback delay line with feedforward
    line.
    
    A Basic All-pass IIR Filter class that sets delay and gain and allows
    access to each, while providing comb filter processing function
    
  ==============================================================================
*/

#ifndef ALLPASS_H_INCLUDED
#define ALLPASS_H_INCLUDED

#include "DelayLine.h"

//////////////////////////////////////////////////////////
//  ALLPASS FILTER CLASS
//  see .cpp file for comments
//////////////////////////////////////////////////////////

class Allpass{

public:
    //constructor
    Allpass(const int sr, const float d_ms, const float d_ms_max, const float g);
    ~Allpass();
    
    //getters
    float getGain();
    float getDelayTimeMS();
    
    //setters
    void setGain(const float g);
    void setDelayTimeMS(const float sr, const float d_ms);
    void resetDelay();
    
    //business methods
    float next(const float in);
    
private:
    float gain;
    DelayLine *delay;
    
};




#endif  // ALLPASS_H_INCLUDED
