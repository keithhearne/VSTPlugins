/*
  ==============================================================================

    Schroeder.h
    Created: 15 Oct 2014 9:10:31pm
    Author:  Keith Hearne
    
    The Schroeder Reverberator as proposed by M.R. Schroeder in his paper
    in 1962, Natural-sounding artificial reverberation.
    consisting of 4 parallel comb filters feeding into a series
    of 2 All-pass filters. 
    
    This stereo version includes a built in low pass filter for accomodation
    of some of the high frequency roll off but nothing more and it is 
    not adjustable. This will be made visible and adjustable in subsequent
    Moorer version.

  ==============================================================================
*/

#ifndef SCHROEDER_H_INCLUDED
#define SCHROEDER_H_INCLUDED

#include "DelayLine.h"
#include "Comb.h"
#include "AllPass.h"
#include "LowPass.h"

//////////////////////////////////////////////////////////
//  SCHROEDER REVERB
//////////////////////////////////////////////////////////

//predefined number of comb and allpass filters for array parsing
//plus one all pass filter
#define NUM_COMBS 4
#define NUM_ALLPASSES 2
#define NUM_LOWPASSES 1

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
    //--------------------------------------------------------------
    Schroeder(const int sr = 44100, const float rt60 = 3.0,
              const float cDelay1 = 29.7, const float cDelay2 = 37.1, const float cDelay3 = 41.1, const float cDelay4 = 43.7,
              const float aDelay1 = 5.0, const float aDelay2 = 1.7, const float aGain1 = 0.07, const float aGain2 = 0.5, const float lCutoff1 = 2300.0f);    //const float lCutoff1 = 2300.0f
    ~Schroeder();
    
    //getters
    float getDecayFactor();
    float getCombDelay(const int id);
    float getAllpassDelay(const int id);
    float getAllpassGain(const int id);
    float getLowpassCutoff(const int id);
    bool getBypass();
    float getCombOutput(const float in, const int id);
    float getAllpassOutput(const float in, const int id);    
    
    //setters
    void setDecayFactor(const float df);
    void setCombDelay(const int id, const float sr, const float d_ms);
    void setAllpassGain(const int id, const float g);
    void setAllpassDelay(const int id, const int sr, const float d_ms);
    void setLowpassCutoff(const int id, const int sr, const float cf_hz);
    void setBypass(bool bp);
    
    //business methods
    float next(const float in);
    
    
    private:
    float decayFactor, ALLPASS_GAIN_LIMIT = 0.707f;//to keep the allpasses from exploding
    bool bypass;
    Comb *combs[NUM_COMBS];
    Allpass *allpasses[NUM_ALLPASSES];
    Lowpass *lowpasses[NUM_LOWPASSES];
};



#endif  // SCHROEDER_H_INCLUDED
