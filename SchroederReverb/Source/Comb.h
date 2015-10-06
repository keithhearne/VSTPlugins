/*
  ==============================================================================

    Comb.h
    Created: 15 Oct 2014 8:55:11pm
    Author:  Keith Hearne
    
    A Basic Comb Filter class that sets delay and gain and allows
    access to each, while providing comb filter processing function

  ==============================================================================
*/

#ifndef COMB_H_INCLUDED
#define COMB_H_INCLUDED

#include "DelayLine.h"

//////////////////////////////////////////////////////////
//  COMB FILTER CLASS
//  see .cpp file for comments
//////////////////////////////////////////////////////////

class Comb{
    
public:
    //constructor / destructor
    Comb(const int sr, const float d_ms, const float d_ms_max, const float g);
    ~Comb();
    
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



#endif  // COMB_H_INCLUDED
