/*
  ==============================================================================

    Comb.h
    Created: 15 Oct 2014 8:55:11pm
    Author:  Keith Hearne

  ==============================================================================
*/

#ifndef COMB_H_INCLUDED
#define COMB_H_INCLUDED

#include "DelayLine.h"
#include "LowPass.h"

//////////////////////////////////////////////////////////
//  COMB FILTER CLASS
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
    
    //business methods
    float next(const float in);
    
private:
    float gain;
    DelayLine *delay;  
    Lowpass *lpFilter;
    
};



#endif  // COMB_H_INCLUDED
