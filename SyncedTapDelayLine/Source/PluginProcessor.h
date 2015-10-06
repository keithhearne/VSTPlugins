/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SyncedTapDelayLine.h"

//==============================================================================
/**
*/
class SyncedTapDelayAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    SyncedTapDelayAudioProcessor();
    ~SyncedTapDelayAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
    void processBlockBypassed (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);

    //Custom Methods, Params, and Public Data
    enum Parameters{
        MasterBypass = 0,
        Delay,
        Feedback,
        Mix,
        Tap1Delay,
        Tap1Level,
        Tap2Delay,
        Tap2Level,
        Tap3Delay,
        Tap3Level,
        Tap4Delay,
        Tap4Level,
        NumParams
    };
    bool NeedsUIUpdate(){return UIUpdateFlag;};
    void ClearUIUpdateFlag(){UIUpdateFlag = false;};
    void RaiseUIUpdateFlag(){UIUpdateFlag = true;};
    //function added to calculate delay tap note values
    float calculateDelayTap(int tap);
    
private:
    //Private Data, helper methods, etc
    float UserParams[NumParams];
    //added hostBPM value read from SDK
    double hostBPM;
    
    //In the plugin create a SyncedTapDelayLine with 2 delay pointer classes to do 
    //the work of the Delay
    SyncedTapDelayLine bDelay_Left;
    SyncedTapDelayLine bDelay_Right;

    
    bool UIUpdateFlag;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SyncedTapDelayAudioProcessor)
};

#endif  // PLUGINPROCESSOR_H_INCLUDED
