/*
  ==============================================================================

    AllPass.h
    Created: 15 Oct 2014 8:55:30pm
    Author:  Keith Hearne

  ==============================================================================
*/

#ifndef ALLPASS_H_INCLUDED
#define ALLPASS_H_INCLUDED

#include "DelayLine.h"

//////////////////////////////////////////////////////////
//    ALLPASS FILTER CLASS
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
    
    //business methods
    float next(const float in);
    
private:
    float gain;
    DelayLine *delay;
    
};




#endif  // ALLPASS_H_INCLUDED
