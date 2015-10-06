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

#ifndef __JUCE_HEADER_3EC70510ACC59FBD__
#define __JUCE_HEADER_3EC70510ACC59FBD__

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
class SyncedTapDelayAudioProcessorEditor  : public AudioProcessorEditor,
                                            public Timer,
                                            public SliderListener,
                                            public ButtonListener
{
public:
    //==============================================================================
    SyncedTapDelayAudioProcessorEditor (SyncedTapDelayAudioProcessor* ownerFilter);
    ~SyncedTapDelayAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    SyncedTapDelayAudioProcessor* getProcessor() const{
        return static_cast<SyncedTapDelayAudioProcessor*>(getAudioProcessor());
    }
    const String setSyncLabel(int sl);
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
    ScopedPointer<GroupComponent> T4groupComponent;
    ScopedPointer<GroupComponent> T3groupComponent;
    ScopedPointer<GroupComponent> T2groupComponent;
    ScopedPointer<GroupComponent> T1groupComponent;
    ScopedPointer<Label> Delay1Label;
    ScopedPointer<Label> MixLabel;
    ScopedPointer<Slider> MixKnob;
    ScopedPointer<TextButton> BypassButton;
    ScopedPointer<Label> FeedbackLabel;
    ScopedPointer<Slider> FeedbackKnob;
    ScopedPointer<Slider> Tap1Knob;
    ScopedPointer<Label> HeaderName;
    ScopedPointer<Label> Tap1SyncLabel;
    ScopedPointer<Slider> Tap2Knob;
    ScopedPointer<Slider> Tap3Knob;
    ScopedPointer<Slider> Tap4Knob;
    ScopedPointer<Label> Tap2SyncLabel;
    ScopedPointer<Label> Tap3SyncLabel;
    ScopedPointer<Label> Tap4SyncLabel;
    ScopedPointer<Label> Delay2Label;
    ScopedPointer<Label> Delay3Label;
    ScopedPointer<Label> Delay4Label;
    ScopedPointer<Label> Tap1LevelLabel3;
    ScopedPointer<Slider> Tap1LevelKnob;
    ScopedPointer<Label> Tap2LevelLabel4;
    ScopedPointer<Slider> Tap2LevelKnob;
    ScopedPointer<Label> Tap2LevelLabel3;
    ScopedPointer<Slider> Tap3LevelKnob;
    ScopedPointer<Label> Tap4LevelLabel3;
    ScopedPointer<Slider> Tap4LevelKnob;
    ScopedPointer<Label> DelayLabel;
    ScopedPointer<Slider> DelayKnob;
    ScopedPointer<Label> secsLabel;
    ScopedPointer<Label> percentLabel;
    ScopedPointer<Label> secsLabel2;
    Image cachedImage_pluginbkg_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SyncedTapDelayAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_3EC70510ACC59FBD__
