/*
  ==============================================================================

    LowPass.cpp
    Created: 27 Oct 2014 9:10:34pm
    Author:  Keith Hearne

    A basic Single One Pole Low Pass Filter
    Formula for coefficients taken from R. Boulanger, 2011, p.486
    Filter cutoff frequecy can be varied on the input 
    and changed via the UI of the plugin.
    
    Filter acts on a one sample delay affected by pole coefficients
    
  ==============================================================================
*/

#include "LowPass.h"

//////////////////////////////////////////////////////////
//  BASIC LOWPASS FILTER CLASS
//////////////////////////////////////////////////////////

//-------------------------------------------------------------------------
// Constructor :
// Predefined sample rate = 44100, default cutoff frequency passed here
// from these values the coefficients for a and b are calculated 
// a = 1 + b
// b = sqrt(squared[2 - cos(2*PI*freq/sr)] - 1) -2 + cos(2*PI*freq/sr)
//-------------------------------------------------------------------------
Lowpass::Lowpass(const int sr, const float cf_hz){
    cutoff = cf_hz;
    float costh = 2.0 - cos(2.0 * M_PI * cutoff / sr);
    coef = sqrt(costh * costh - 1.0) - costh;
}

//getters
//-------------------------------------------------------------------------
// getCutoff :
// return the value of the cutoff frequency
//-------------------------------------------------------------------------
float Lowpass::getCutoff(){return cutoff;}

//setters
//-------------------------------------------------------------------------
// setCutoff :
// function to adjust and set the filter coefficients from the cutoff
// frequency parameter
//-------------------------------------------------------------------------
void Lowpass::setCutoff(const int sr, const float cf_hz){
    cutoff = cf_hz;
    float costh = 2.0 - cos(2.0 * M_PI * cutoff / sr);
    coef = sqrt(costh * costh - 1.0) - costh;
}

//business methods
//-------------------------------------------------------------------------
// next :
// the process function which takes the input discrete time sample and 
// applies the coefficient one sample delay formula to it returning the
// previous value (input * (1 + b) - (delayed sample * b)
//-------------------------------------------------------------------------
float Lowpass::next(const float in){
    prev = in * (1 + coef) - (prev * coef);
    return prev;
}