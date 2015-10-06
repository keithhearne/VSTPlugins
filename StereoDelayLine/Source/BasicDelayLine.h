/*
  ==============================================================================

    BasicDelayLine.h
    New version of BasicDelayLine that also accepts an external feedback path
    as input, and which uses fractional delay
    
    Created: 14 Sep 2014 5:15:53pm
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
//////////////////////////////////////////////////////////

class BasicDelayLine{

public:
    //constructor / destructor
    BasicDelayLine(const int sr = 44100, const float d_ms = 0.0f, const float feedback = 0.0f, const float mixLevel = 0.5f);
    ~BasicDelayLine();
    
    //getters
    float getDelayTimeMS();
    float getMaxDelayTimeMS();
    float getFeedback();
    float getMix();
    bool getByPass();
    float getCurrentFeedbackOutput();
    
    //setters
    void setDelayTimeMS(const int sr, const float d_ms);
    void setDelay(float d_ms);
    void setFeedback(float f_pct);
    void setMix(float m_pct);
    void setByPass(bool bp);
    void setCurrentFeedbackInput(float fb);
    void setUseExternalFeedback(bool b);
    
    //business functions
    float next(const float in);
    void resetBuffer();
    void resetDelay();

private:
    int writePos, readPosA, MAX_DELAY_SAMPLES;
    float delay_ms, delay_samples, fraction, feedback, mixLevel, MAX_DELAY_MS, feedbackIn;
    bool delay_bypass, useExternalFeedback;
    float *buffer;
    
};

#endif  // BASICDELAYLINE_H_INCLUDED
