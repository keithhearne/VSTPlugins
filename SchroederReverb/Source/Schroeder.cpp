/*
  ==============================================================================

    Schroeder.cpp
    Created: 15 Oct 2014 9:10:40pm
    Author:  Keith Hearne
    
    The Schroeder Reverberator as proposed by M.R. Schroeder in his paper
    in 1962, Natural-sounding artificial reverberation.
    consisting of 4 parallel comb filters feeding into a series
    of 2 All-pass filters. This version sticks as rigidly as possible to 
    the designs laid out in the paper with no embellishments.

  ==============================================================================
*/

#include "Schroeder.h"


//////////////////////////////////////////////////////////
//  SCHROEDER REVERB
//////////////////////////////////////////////////////////


//helper functions
//------------------------------------------------------------------
//------------------------------------------------------------------
//  calcCombGain : Function to calculate gain from decay/RT60
//
//  RT60    :   value from plugin decay parameter
//  d_ms    :   Delay value of the comb filter
//------------------------------------------------------------------
//------------------------------------------------------------------
inline float calcCombGain(const float d_ms, const float rt60){
    return pow(10.0, ((-3.0 * d_ms) / (rt60 * 1000.0)));
}


//--------------------------------------------------------------
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
//--------------------------------------------------------------
Schroeder::Schroeder(const int sr, const float rt60,
          const float cDelay1, const float cDelay2, const float cDelay3, const float cDelay4,
          const float aDelay1, const float aDelay2, const float aGain1, const float aGain2){
    
    decayFactor = rt60;
    float d_ms, d_ms_max = 100.0f, gain;
    bypass = false;
    
    //Comb Filter 1 setup
    d_ms = cDelay1;
    gain = calcCombGain(d_ms, decayFactor);
    combs[0] = new Comb(sr, d_ms, d_ms_max, gain);
    setCombDelay(0,sr,d_ms);
    
    //Comb Filter 2 setup
    d_ms = cDelay2;
    gain = calcCombGain(d_ms, decayFactor);
    combs[1] = new Comb(sr, d_ms, d_ms_max, gain);
    setCombDelay(1,sr,d_ms);
    
    //Comb Filter 3 setup
    d_ms = cDelay3;
    gain = calcCombGain(d_ms, decayFactor);
    combs[2] = new Comb(sr, d_ms, d_ms_max, gain);
    setCombDelay(2,sr,d_ms);
    
    //Comb Filter 4 setup
    d_ms = cDelay4;
    gain = calcCombGain(d_ms, decayFactor);
    combs[3] = new Comb(sr, d_ms, d_ms_max, gain);
    setCombDelay(3,sr,d_ms);

    d_ms_max = 20.0f;
    
    //All-pass filter setup
    allpasses[0] = new Allpass(sr, aDelay1, d_ms_max, aGain1);
    allpasses[1] = new Allpass(sr, aDelay2, d_ms_max, aGain2);


}

//-------------------------------------------------------------------------
// Destructor :
// delete all combs and allpasses
//-------------------------------------------------------------------------
Schroeder::~Schroeder(){
    for(int i = 0; i < NUM_COMBS; i++){
        delete combs[i];
    }
    for(int i = 0; i < NUM_ALLPASSES; i++){
        delete allpasses[i];
    }
}

//getters
//-------------------------------------------------------------------------
// getDecayFactor :
// return the decay factor used for determining RT60 and filter gain
//-------------------------------------------------------------------------
float Schroeder::getDecayFactor(){return decayFactor;}

//-------------------------------------------------------------------------
// getCombDelay : comb id
// get the specified delay time in milliseconds of the indexed comb filter
//-------------------------------------------------------------------------
float Schroeder::getCombDelay(const int id){return combs[id]->getDelayTimeMS();}

//-------------------------------------------------------------------------
// getAllpassDelay : allpass id
// get the specified delay time in milliseconds of the indexed allpass filter
//-------------------------------------------------------------------------
float Schroeder::getAllpassDelay(const int id){return allpasses[id]->getDelayTimeMS();}

//-------------------------------------------------------------------------
// getAllpassGain : comb id
// get the specified gain scalar value of the indexed comb filter
//-------------------------------------------------------------------------
float Schroeder::getAllpassGain(const int id){return allpasses[id]->getGain();}

//-------------------------------------------------------------------------
// getBypass : 
// return the status of the boolean for bypassing the plugin processing
//-------------------------------------------------------------------------
bool Schroeder::getBypass(){return bypass;}

//setters
//-------------------------------------------------------------------------
// setDecayFactor : decayfactor value in seconds
// decay time/desired RT60 is passed from UI to this function
// and the required comb filter gain values that will adhere to that RT60
// are calculated based on this factor
//-------------------------------------------------------------------------
void Schroeder::setDecayFactor(const float df){
    decayFactor = df;
    
    //cycle through each comb and reset the comb gain value according to
    //the new decayFactor
    for(int i = 0; i < NUM_COMBS; i++){
        combs[i]->setGain(calcCombGain(combs[i]->getDelayTimeMS(), decayFactor));
    }
};

//-------------------------------------------------------------------------
// setCombDelay : id of comb, sample rate, delay time in milliseconds
// sets the gain and the delaytime in milliseconds of the Comb filters
// delay buffer when a value is changed through the UI
//-------------------------------------------------------------------------
void Schroeder::setCombDelay(const int id, const float sr, const float d_ms){
    combs[id]->setGain(calcCombGain(d_ms, decayFactor));
    combs[id]->setDelayTimeMS(sr, d_ms);
}

//-------------------------------------------------------------------------
// setAllpassGain : id of comb, gain
// sets the gain for the allpass filter, scaling by the GAIN_LIMIT so as
// not to blow the filter up due to the unstable nature of IIR filters
//-------------------------------------------------------------------------
void Schroeder::setAllpassGain(const int id, const float g){allpasses[id]->setGain(g * ALLPASS_GAIN_LIMIT);}

//-------------------------------------------------------------------------
// setAllpassDelay : id of comb, sample rate, delay in milliseconds
// sets the delay time in milliseconds of the all pass delay line
//-------------------------------------------------------------------------
void Schroeder::setAllpassDelay(const int id, const int sr, const float d_ms){allpasses[id]->setDelayTimeMS(sr, d_ms);}

//-------------------------------------------------------------------------
// setBypass : boolean bypass value
// sets a boolean which determines if processing should be bypassed in the
// worker next function
//-------------------------------------------------------------------------
void Schroeder::setBypass(bool bp){bypass = bp;}

//-------------------------------------------------------------------------
// reset : 
// resets the delay lines in the combs and allpass filters
//-------------------------------------------------------------------------
void Schroeder::reset(){
    for(int i = 0; i < NUM_COMBS; i++){
        combs[i]->resetDelay();
    }
    
    for(int i = 0; i < NUM_ALLPASSES; i++){
        allpasses[i]->resetDelay();
    }
    
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//  next    : Function to process next sample input in
//          : each input sample is passed to each of the comb 
//          : filters in turn (scaling to prevent clipping)
//          : the output value is accumulated/summed
//          : the result is then passed in series through the 
//          : all-pass filters
//
//  in      :   input sample form the audio buffer
//  
//------------------------------------------------------------------
//------------------------------------------------------------------
float Schroeder::next(const float in){
    
    // if bypass is enabled on plugin then just pass back
    // the unprocessed input sample
    if(bypass)
        return in;
        
    float out = 0.0f;
    
    //step through each of the 4 comb filters and pass a scaled input
    for(int i = 0; i < NUM_COMBS; i++){
        out += combs[i]->next(in * 0.50f); //scale down to avoid clipping
    }
    
    float passOut = 0.0f;
    float passOut2 = 0.0f;
    
    passOut = allpasses[0]->next(out);          //1 stage all-pass filtering
    passOut2 = allpasses[1]->next(passOut);     //2 stage all-pass filtering
  
    return passOut2;
    
}


