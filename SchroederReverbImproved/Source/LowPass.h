/*
  ==============================================================================

    LowPass.h
    Created: 27 Oct 2014 9:10:20pm
    Author:  Keith Hearne

  ==============================================================================
*/

#ifndef LOWPASS_H_INCLUDED
#define LOWPASS_H_INCLUDED

#include <cmath>


//////////////////////////////////////////////////////////
//  BASIC LOWPASS FILTER CLASS
//////////////////////////////////////////////////////////

class Lowpass{

public:
    //constructor
    Lowpass(const int sr, const float cf_hz);
    
    //getters
    float getCutoff();
    
    //setters
    void setCutoff(const int sr, const float cf_hz);
    
    //business methods
    float next(const float in);
    
private:
    float cutoff, coef, prev;
    
};


#endif  // LOWPASS_H_INCLUDED
