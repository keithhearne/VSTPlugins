/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_BADE644160B49A4C__
#define __JUCE_HEADER_BADE644160B49A4C__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PingPongDelayAudioProcessorEditor  : public AudioProcessorEditor,
                                           public Timer,
                                           public SliderListener,
                                           public ButtonListener
{
public:
    //==============================================================================
    PingPongDelayAudioProcessorEditor (PingPongDelayAudioProcessor* ownerFilter);
    ~PingPongDelayAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    PingPongDelayAudioProcessor* getProcessor() const{
        return static_cast<PingPongDelayAudioProcessor*>(getAudioProcessor());
    }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);
    void visibilityChanged();

    // Binary resources:
    static const char* pluginbkg_png;
    static const int pluginbkg_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> DelayLabel;
    ScopedPointer<Label> MixLabel;
    ScopedPointer<Slider> MixKnob;
    ScopedPointer<TextButton> BypassButton;
    ScopedPointer<Label> FeedbackLabel;
    ScopedPointer<Slider> FeedbackKnob;
    ScopedPointer<Slider> DelayKnob;
    ScopedPointer<Label> HeaderName;
    ScopedPointer<Label> msecLabel;
    ScopedPointer<Label> percentLabel;
    Image cachedImage_pluginbkg_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PingPongDelayAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_BADE644160B49A4C__
