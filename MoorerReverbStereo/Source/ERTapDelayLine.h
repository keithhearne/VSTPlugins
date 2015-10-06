/*
  ==============================================================================

    ERTapDelayLine.h
    Tap Delay used for Early Reflection Generation as proposed by Moorers design
    In Moorers 1979 paper About This Reverberation Business he took a model of
    real room impulse responses for Early Reflection Generation from impulses
    recorded in the Boston Symphony Hall.
    
    These values are used here in a multi-tap setup to provide the summed
    output of the 18 taps (the first tap will be the input impulse, added at 
    the reverb generation stage) to provide an early reflection generator.
    
    Created: 16 Nov 2014 5:15:53pm
    Author:  Keith Hearne

  ==============================================================================
*/

#ifndef ERTAPDELAYLINE_H_INCLUDED
#define ERTAPDELAYLINE_H_INCLUDED

#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <iostream>

//////////////////////////////////////////////////////////
//  ER TAP DELAY LINE CLASS (for use with Moorer Reverb)
//  see .cpp file for comments
//////////////////////////////////////////////////////////

class ERTapDelayLine{

public:
    //constructor / destructor
    ERTapDelayLine(const int sr = 44100, const float d_ms = 0.0f, const float d_max = 0.0f);
    ~ERTapDelayLine();
    
    //getters
    float getDelayTimeMS();
    float getMaxDelayTimeMS();
    
    //setters
    void setDelayTimeMS(const int sr, const float d_ms);
    void setDelay(float d_ms);
    
    //business functions
    float readDelay(float in);
    void writeDelay(float in);
    float next(const float in);
    void resetBuffer();
    void resetDelay();

private:
    int writePos, readPosA, MAX_DELAY_SAMPLES;
    float delay_ms, delay_samples, fraction, MAX_DELAY_MS, accumulatedTaps;
    float *buffer;

    //Early Reflection TAP delay values as presented in Moorer's 1979 paper
    //values extracted from impulse measurements in Boston Symphony Hall
    //These are the delay times for each of the 18 tap readIndex
    //The first tap is unit gain for the input signal, not shown here
    const float ER_TAPS[18] = {
        0.0043, 0.0215, 0.0225, 0.0268, 0.0270, 0.0298, 0.0458, 0.0485, 0.0572, 0.0587, 0.0595, 0.0612,
        0.0707, 0.0708, 0.0726, 0.0741, 0.0753, 0.0797
    };
    //Early reflection GAIN values to apply to each of the above taps
    const float ER_GAINS[18] = {
        0.841, 0.504, 0.491, 0.379, 0.380, 0.346, 0.289, 0.272, 0.192, 0.193, 0.217, 0.181, 0.180,
        0.181, 0.176, 0.142, 0.167, 0.134
    };
    
};

#endif  // ERTAPDELAYLINE_H_INCLUDED
