/*
  ==============================================================================

    Moorer.h
    Created: 15 Oct 2014 9:10:31pm
    Author:  Keith Hearne
    
    The Moorer Reverberator as proposed by James Moorer in his paper
    in 1979, About This Reverb Business.
    Adapted from Schroeders 1962 model, with addition of more comb
    filters, adjusting the number fo all-pass filters and including
    early reflection generation as well as low pass filtering in
    the comb feedback loops.
    
    Consists of FIR filter 19 tap delay for early reflection generation
    6 parallel low pass comb filters feeding into a single
    all-pass filter. There is also use of a delay to sync the early 
    reflections and late reflections arrival.

  ==============================================================================
*/

#ifndef Moorer_H_INCLUDED
#define Moorer_H_INCLUDED

#include "DelayLine.h"
#include "Comb.h"
#include "AllPass.h"
#include "LowPass.h"
#include "ERTapDelayLine.h"

//////////////////////////////////////////////////////////
//  Moorer REVERB
//  see .cpp file for comments
//////////////////////////////////////////////////////////

//predefined values for filter numbers
#define NUM_COMBS 6
#define NUM_ALLPASSES 1
#define NUM_LOWPASSES 6

class Moorer{

public:
    //--------------------------------------------------------------
    //constructor setting initial values for comb delays and gains
    //comb delays must be mutually prime
    //
    //  Comb 1  : 50.0 msec delay
    //  Comb 2  : 56.0 msec delay
    //  Comb 3  : 61.0 msec delay
    //  Comb 4  : 68.0 msec delay
    //  Comb 5  : 72.0 msec delay
    //  Comb 6  : 78.0 msec delay
    //  APF 1   : 6.0 msec delay, gain 0.707
    //  LPF 1-6 : low pass filter values for each comb feedback loop
    //  SR      : 44100KHz
    //  RT60    : default of 3 seconds
    //  LD      : late delay, is a delay between onset of ER and reverb tails
    //--------------------------------------------------------------
    Moorer(const int sr = 44100, const float rt60 = 3.0,
              const float cDelay1 = 50.0, const float cDelay2 = 56.0, 
              const float cDelay3 = 61.0, const float cDelay4 = 68.0,
              const float cDelay5 = 72.0, const float cDelay6 = 78.0,
              const float aDelay1 = 6.0, const float aGain1 = 0.707,
              const float lCutoff1 = 4942.0f, const float lCutoff2 = 4363.0f, 
              const float lCutoff3 = 4312.0f, const float lCutoff4 = 4574.0f, 
              const float lCutoff5 = 3981.0f, const float lCutoff6 = 4036.0f, float ld = 10.0f);
    ~Moorer();
    
    //getters
    float getDecayFactor();
    float getCombDelay(const int id);
    float getAllpassDelay(const int id);
    float getAllpassGain(const int id);
    bool getBypass();
    
    //setters
    void setDecayFactor(const float df);
    void setCombDelay(const int id, const float sr, const float d_ms);
    void setAllpassGain(const int id, const float g);
    void setAllpassDelay(const int id, const int sr, const float d_ms);
    void setBypass(bool bp);
    void setLPFreq(const float lpf);    
    
    //business methods
    float next(const float in);
    
    
    private:
    float decayFactor, ALLPASS_GAIN_LIMIT = 0.707f, lp_freq, lateDelay; //GAIN to keep the allpasses from exploding
    bool bypass;
    Comb *combs[NUM_COMBS];
    Allpass *allpasses[NUM_ALLPASSES];
    ERTapDelayLine *ergenerator[1];
    DelayLine *LRDelay; 

};



#endif  // Moorer_H_INCLUDED
