/*
  ==============================================================================

    LowPass.h
    Created: 27 Oct 2014 9:10:20pm
    Author:  Keith Hearne
    
    A basic Single One Pole Low Pass Filter
    Formula for coefficients taken from R. Boulanger, 2011, p.486
    Filter cutoff frequecy can be varied on the input 
    and changed via the UI of the plugin.    

  ==============================================================================
*/

#ifndef LOWPASS_H_INCLUDED
#define LOWPASS_H_INCLUDED

#include <cmath>

//////////////////////////////////////////////////////////
//  BASIC LOWPASS FILTER CLASS
//  see .cpp file for comments
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
