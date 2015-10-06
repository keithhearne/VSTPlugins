/*
  ==============================================================================

    BasicDelayLine.h
    Created: 9 Sep 2014 5:15:53pm
    Author:  Keith Hearne

  ==============================================================================
*/

#ifndef BASICDELAYLINE_H_INCLUDED
#define BASICDELAYLINE_H_INCLUDED

#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <iostream>

//////////////////////////////////////////////////////////
//  BASIC DELAY LINE CLASS (feedback optional)
//  see comments in .cpp file
//////////////////////////////////////////////////////////

class BasicDelayLine{

public:
    BasicDelayLine(const int sr = 44100, const float d_ms = 0.0f, const float feedback = 0.0f, const float mixLevel = 0.5f);
    ~BasicDelayLine();
    
    //getters
    float getDelayTimeMS();
    float getMaxDelayTimeMS();
    float getFeedback();
    float getMix();
    bool getByPass();
    
    //setters
    void setDelayTimeMS(const int sr, const float d_ms);
    void setDelay(float d_ms);
    void setFeedback(float f_pct);
    void setMix(float m_pct);
    void setByPass(bool bp);
    
    //business functions
    float next(const float in);
    void resetBuffer();
    void resetDelay();

private:
    int writePos, readPosA, MAX_DELAY_SAMPLES;
    float delay_ms, delay_samples, fraction, feedback, mixLevel, MAX_DELAY_MS;
    bool delay_bypass;
    float *buffer;
    
};

#endif  // BASICDELAYLINE_H_INCLUDED
