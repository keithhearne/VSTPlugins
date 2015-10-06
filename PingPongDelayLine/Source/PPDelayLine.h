/*
  ==============================================================================

    PingPongDelayLine.h
    Created: 9 Oct 2014 11:30:25pm
    Author:  Keith Hearne

    While this design is not absolutely essential to the iterative approach
    of the reverb plugin, the use of ping pong type loops is used in reverb
    design and filter design for crossing signals and feedback paths
    
    This design cycles the delay feedback between left and right channels
  ==============================================================================
*/

#ifndef PPDELAYLINE_H_INCLUDED
#define PPDELAYLINE_H_INCLUDED

#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <iostream>

//////////////////////////////////////////////////////////
//  PINGPONG DELAY LINE CLASS (feedback optional)
//  see .cpp file for comments
//////////////////////////////////////////////////////////

class PPDelayLine{

public:
    //constructor / destructor
    PPDelayLine(const int sr = 44100, const float d_ms = 0.0f, const float feedback = 0.0f, const float mixLevel = 0.5f, const bool crossFeedback = true);
    ~PPDelayLine();
    
    //getters
    float getDelayTimeMS();
    float getMaxDelayTimeMS();
    float getFeedback();
    float getMix();
    bool getByPass();
    float getCurrentFeedbackOutput();
    bool isCrossedFeedback();
    
    //setters
    void setDelayTimeMS(const int sr, const float d_ms);
    void setDelay(float d_ms);
    void setFeedback(float f_pct);
    void setMix(float m_pct);
    void setByPass(bool bp);
    void setCurrentFeedbackInput(float fb);
    void setUseExternalFeedback(bool b);
    /*void setCrossedFeedback(bool b);*/
    
    //business functions
    float next(const float in);
    void resetBuffer();
    void resetDelay();

private:
    int writePos, readPosA, MAX_DELAY_SAMPLES;
    float delay_ms, delay_samples, fraction, feedback, mixLevel, MAX_DELAY_MS, feedbackIn;
    bool delay_bypass, useExternalFeedback, crossFeedback;
    float *buffer;
    
};




#endif  // PPDELAYLINE_H_INCLUDED
