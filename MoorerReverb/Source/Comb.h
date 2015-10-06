/*
  ==============================================================================

    Comb.h
    Created: 15 Oct 2014 8:55:11pm
    Author:  Keith Hearne
    
    A LowPass Comb Filter class that sets delay and gain while passing
    its output through a low pass filter to mimic the effect air has
    on the high frequency content lossand as refelctions in the feedback
    loop are processed 

  ==============================================================================
*/

#ifndef COMB_H_INCLUDED
#define COMB_H_INCLUDED

#include "DelayLine.h"
#include "LowPass.h"

//////////////////////////////////////////////////////////
//  COMB FILTER CLASS
//  see .cpp file for comments
//////////////////////////////////////////////////////////

class Comb{
    
public:
    //constructor / destructor
    Comb(const int sr, const float d_ms, const float d_ms_max, const float g, const float cutOff);
    ~Comb();
    
    //getters
    float getGain();
    float getDelayTimeMS();
    
    //setters
    void setGain(const float g);
    void setDelayTimeMS(const float sr, const float d_ms);
    void setLPF(const float cutoff);
    
    //business methods
    float next(const float in);
    
private:
    float gain;
    DelayLine *delay; 
    Lowpass *lpFilter;
    
};



#endif  // COMB_H_INCLUDED
