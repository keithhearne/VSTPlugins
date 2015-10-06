/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Moorer.h"

//==============================================================================
/**
*/
class MoorerReverbAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    MoorerReverbAudioProcessor();
    ~MoorerReverbAudioProcessor();

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
        Mix,
        Decay,
        LPF,
        NumParams
    };
    bool NeedsUIUpdate(){return UIUpdateFlag;};
    void ClearUIUpdateFlag(){UIUpdateFlag = false;};
    void RaiseUIUpdateFlag(){UIUpdateFlag = true;};
    
private:
    //Private Data, helper methods, etc
    float UserParams[NumParams];
    
    //In the plugin create a Moorer Reverb
    Moorer mRevLeft;
    Moorer mRevRight;

    
    bool UIUpdateFlag;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MoorerReverbAudioProcessor)
};

#endif  // PLUGINPROCESSOR_H_INCLUDED
