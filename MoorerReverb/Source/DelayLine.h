/*
  ==============================================================================

    DelayLine.h
    New version of a basic DelayLine which uses fractional delay
    Operations for reading and writing from the delay have been
    separated out into new functions so that the can be read from
    and written to in the Comb and All pass filters seperately.
    
    Created: 15 Oct 2014 5:15:53pm
    Author:  Keith Hearne

  ==============================================================================
*/

#ifndef DELAYLINE_H_INCLUDED
#define DELAYLINE_H_INCLUDED

#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <iostream>

//////////////////////////////////////////////////////////
//  DELAY LINE CLASS (for use with Moorer Reverb)
//  see .cpp file for comments
//////////////////////////////////////////////////////////

class DelayLine{

public:
    //constructor / destructor
    DelayLine(const int sr = 44100, const float d_ms = 0.0f, const float d_max = 0.0f);
    ~DelayLine();
    
    //getters
    float getDelayTimeMS();
    float getMaxDelayTimeMS();
    
    //setters
    void setDelayTimeMS(const int sr, const float d_ms);
    void setDelay(float d_ms);
    
    //business functions
    float readDelay();
    void writeDelay(float in);
    float next(const float in);
    void resetBuffer();
    void resetDelay();

private:
    int writePos, readPosA, MAX_DELAY_SAMPLES;
    float delay_ms, delay_samples, fraction, MAX_DELAY_MS;
    float *buffer;
    
};

#endif  // DELAYLINE_H_INCLUDED
