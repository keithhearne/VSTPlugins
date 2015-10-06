/*
  ==============================================================================

    Schroeder.h
    Created: 15 Oct 2014 9:10:31pm
    Author:  Keith Hearne

    The Schroeder Reverberator as proposed by M.R. Schroeder in his paper
    in 1962, Natural-sounding artificial reverberation.
    consisting of 4 parallel comb filters feeding into a series
    of 2 All-pass filters. This version sticks as rigidly as possible to 
    the designs laid out in the paper with no embellishments.
    
  ==============================================================================
*/

#ifndef SCHROEDER_H_INCLUDED
#define SCHROEDER_H_INCLUDED

#include "DelayLine.h"
#include "Comb.h"
#include "AllPass.h"

//////////////////////////////////////////////////////////
//  SCHROEDER REVERB
//  see .cpp file for full comments
//////////////////////////////////////////////////////////

//predefined number of comb and allpass filters for array parsing

#define NUM_COMBS 4
#define NUM_ALLPASSES 2

class Schroeder{

public:
    //--------------------------------------------------------------
    //constructor setting initial values for comb delays and gains
    //comb delays must be mutually prime
    //
    //  Comb 1  : 29.7 msec delay
    //  Comb 2  : 37.1 msec delay
    //  Comb 3  : 41.1 msec delay
    //  Comb 4  : 43.7 msec delay
    //  APF 1   : 5.0 msec delay, gain 0.707
    //  APF 2   : 1.7 msec delay, gain 0.5
    //  sr      : defaulted to 44100KHz
    //  rt60    : defaulted to 3.0 seconds on initialisation
    //--------------------------------------------------------------
    Schroeder(const int sr = 44100, const float rt60 = 3.0,
              const float cDelay1 = 29.7, const float cDelay2 = 37.1,
              const float cDelay3 = 41.1, const float cDelay4 = 43.7,
              const float aDelay1 = 5.0, const float aDelay2 = 1.7,
              const float aGain1 = 0.707, const float aGain2 = 0.5);
    ~Schroeder();
    
    //getters
    float getDecayFactor();
    float getCombDelay(const int id);
    float getAllpassDelay(const int id);
    float getAllpassGain(const int id);
    //float getLowpassCutoff(const int id);
    bool getBypass();
    
    //setters
    void setDecayFactor(const float df);
    void setCombDelay(const int id, const float sr, const float d_ms);
    void setAllpassGain(const int id, const float g);
    void setAllpassDelay(const int id, const int sr, const float d_ms);
    void setBypass(bool bp);
    void reset();
    
    //business methods
    float next(const float in);
    
    
    private:
    float decayFactor, ALLPASS_GAIN_LIMIT = 0.707f;//to keep the allpasses from exploding
    bool bypass;
    Comb *combs[NUM_COMBS];
    Allpass *allpasses[NUM_ALLPASSES];
};



#endif  // SCHROEDER_H_INCLUDED
