/*
  ==============================================================================

    SyncedTapDelayLine.h
    New version of SyncedTapDelayLine that also accepts an external feedback path
    as input, and which uses fractional delay
    
    The multi-tap delay function is used in filter design as a Finite Impulse
    Response for the use of building an Early Reflections generator and a 
    similar function to this will be employed in the Moorer model later.
    
    Created: 14 Sep 2014 5:15:53pm
    Author:  Keith Hearne

  ==============================================================================
*/

#ifndef SYNCEDTAPDELAYLINE_H_INCLUDED
#define SYNCEDTAPDELAYLINE_H_INCLUDED

#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <iostream>

//////////////////////////////////////////////////////////
//  SyncedTap DELAY LINE CLASS (feedback optional)
//  see .cpp file for commenting
//////////////////////////////////////////////////////////

class SyncedTapDelayLine{

public:
    //constructor / destructor
    SyncedTapDelayLine(const int sr = 44100, const float d_ms = 0.0f, const float feedback = 0.0f, const float mixLevel = 0.5f);
    ~SyncedTapDelayLine();
    
    //getters
    float getDelayTimeMS();
    float getMaxDelayTimeMS();
    float getDelay();
    float getFeedback();
    float getTap1Delay();
    float getTap2Delay();
    float getTap3Delay();
    float getTap4Delay();
    float getTap1Level();
    float getTap2Level();
    float getTap3Level();
    float getTap4Level();
    float getMix();
    bool getByPass();
    float getCurrentFeedbackOutput();
    
    //setters
    void setDelayTimeMS(const int sr, const float d_ms);
    void setDelay(float d_ms);
    void setTap1Delay(float td);
    void setTap2Delay(float td);
    void setTap3Delay(float td);
    void setTap4Delay(float td);
    void setTap1Level(float tl);
    void setTap2Level(float tl);
    void setTap3Level(float tl);
    void setTap4Level(float tl);    
    void setFeedback(float f_pct);
    void setMix(float m_pct);
    void setByPass(bool bp);
    void setCurrentFeedbackInput(float fb);
    void setUseExternalFeedback(bool b);
    void setDelaySync(float quarter, float eighth, float sixtenth);
    
    //business functions
    float next(const float in);
    void resetBuffer();
    void resetDelay();

private:
    int writePos, readPosA, readTap1, readTap2, readTap3, readTap4, MAX_DELAY_SAMPLES;
    float delay_ms, delay_samples, fraction, feedback, mixLevel, MAX_DELAY_MS, feedbackIn, 
        tap1delay, tap2delay, tap3delay, tap4delay, tap1level, tap2level, tap3level, tap4level;
    bool delay_bypass, useExternalFeedback;
    float *buffer;
    
};

#endif  // SYNCEDTAPDELAYLINE_H_INCLUDED
