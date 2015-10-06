/*
  ==============================================================================

    Schroeder.h
    Created: 15 Oct 2014 9:10:31pm
    Author:  Keith Hearne

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

#define NUM_COMBS 4
#define NUM_ALLPASSES 2
#define NUM_LOWPASSES 1

class Schroeder{

public:
    //constructor / destructor
    Schroeder(const int sr = 44100, const float rt60 = 3.0,
              const float cDelay1 = 29.7, const float cDelay2 = 37.1, const float cDelay3 = 41.1, const float cDelay4 = 43.7,
              const float aDelay1 = 5.0, const float aDelay2 = 1.7, const float aGain1 = 0.707, const float aGain2 = 0.5, const float lCutoff1 = 2300.0f);    //const float lCutoff1 = 2300.0f
    ~Schroeder();
    
    //getters
    float getDecayFactor();
    float getCombDelay(const int id);
    float getAllpassDelay(const int id);
    float getAllpassGain(const int id);
    float getLowpassCutoff(const int id);
    bool getBypass();
    
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
