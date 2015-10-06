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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MoorerReverbAudioProcessorEditor::MoorerReverbAudioProcessorEditor (MoorerReverbAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (DecayLabel = new Label ("Decay Label",
                                               TRANS("Decay")));
    DecayLabel->setFont (Font (Font::getDefaultMonospacedFontName(), 18.00f, Font::bold));
    DecayLabel->setJustificationType (Justification::centred);
    DecayLabel->setEditable (false, false, false);
    DecayLabel->setColour (Label::textColourId, Colours::azure);
    DecayLabel->setColour (TextEditor::textColourId, Colours::black);
    DecayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));

    addAndMakeVisible (MixLabel = new Label ("Mix Label",
                                             TRANS("Mix")));
    MixLabel->setTooltip (TRANS("Wet/Dry Mix"));
    MixLabel->setFont (Font (Font::getDefaultMonospacedFontName(), 18.00f, Font::bold));
    MixLabel->setJustificationType (Justification::centred);
    MixLabel->setEditable (false, false, false);
    MixLabel->setColour (Label::textColourId, Colours::azure);
    MixLabel->setColour (TextEditor::textColourId, Colours::black);
    MixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));

    addAndMakeVisible (MixKnob = new Slider ("Mix Knob"));
    MixKnob->setExplicitFocusOrder (1);
    MixKnob->setRange (0, 100, 1);
    MixKnob->setSliderStyle (Slider::Rotary);
    MixKnob->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    MixKnob->setColour (Slider::backgroundColourId, Colours::cadetblue);
    MixKnob->setColour (Slider::trackColourId, Colours::coral);
    MixKnob->setColour (Slider::rotarySliderFillColourId, Colours::aquamarine);
    MixKnob->setColour (Slider::rotarySliderOutlineColourId, Colours::cadetblue);
    MixKnob->setColour (Slider::textBoxTextColourId, Colours::aliceblue);
    MixKnob->setColour (Slider::textBoxBackgroundColourId, Colours::cadetblue);
    MixKnob->setColour (Slider::textBoxHighlightColourId, Colours::coral);
    MixKnob->setColour (Slider::textBoxOutlineColourId, Colours::cadetblue);
    MixKnob->addListener (this);

    addAndMakeVisible (BypassButton = new TextButton ("Bypass Button"));
    BypassButton->setButtonText (TRANS("Bypass"));
    BypassButton->addListener (this);
    BypassButton->setColour (TextButton::buttonColourId, Colours::cadetblue);
    BypassButton->setColour (TextButton::buttonOnColourId, Colours::coral);
    BypassButton->setColour (TextButton::textColourOnId, Colours::azure);
    BypassButton->setColour (TextButton::textColourOffId, Colours::azure);

    addAndMakeVisible (DecayKnob = new Slider ("Decay Knob"));
    DecayKnob->setTooltip (TRANS("Delay in milliseconds"));
    DecayKnob->setExplicitFocusOrder (1);
    DecayKnob->setRange (0.01, 20, 0.001);
    DecayKnob->setSliderStyle (Slider::Rotary);
    DecayKnob->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    DecayKnob->setColour (Slider::backgroundColourId, Colours::cadetblue);
    DecayKnob->setColour (Slider::trackColourId, Colours::coral);
    DecayKnob->setColour (Slider::rotarySliderFillColourId, Colours::aquamarine);
    DecayKnob->setColour (Slider::rotarySliderOutlineColourId, Colours::cadetblue);
    DecayKnob->setColour (Slider::textBoxTextColourId, Colours::aliceblue);
    DecayKnob->setColour (Slider::textBoxBackgroundColourId, Colours::cadetblue);
    DecayKnob->setColour (Slider::textBoxHighlightColourId, Colours::coral);
    DecayKnob->setColour (Slider::textBoxOutlineColourId, Colours::cadetblue);
    DecayKnob->addListener (this);

    addAndMakeVisible (HeaderName = new Label ("Header",
                                               TRANS("Reverb Type II\n"
                                               "Moorer")));
    HeaderName->setFont (Font (Font::getDefaultMonospacedFontName(), 22.00f, Font::bold | Font::italic));
    HeaderName->setJustificationType (Justification::centred);
    HeaderName->setEditable (false, false, false);
    HeaderName->setColour (Label::textColourId, Colours::aliceblue);
    HeaderName->setColour (TextEditor::textColourId, Colour (0x00000000));
    HeaderName->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (LowPassLabel = new Label ("LowPass Label",
                                                 TRANS("Low Pass")));
    LowPassLabel->setFont (Font (Font::getDefaultMonospacedFontName(), 18.00f, Font::bold));
    LowPassLabel->setJustificationType (Justification::centred);
    LowPassLabel->setEditable (false, false, false);
    LowPassLabel->setColour (Label::textColourId, Colours::azure);
    LowPassLabel->setColour (TextEditor::textColourId, Colours::black);
    LowPassLabel->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));

    addAndMakeVisible (LowPassKnob = new Slider ("LowPass Knob"));
    LowPassKnob->setTooltip (TRANS("Frequency in KHz"));
    LowPassKnob->setExplicitFocusOrder (1);
    LowPassKnob->setRange (1000, 12000, 1);
    LowPassKnob->setSliderStyle (Slider::Rotary);
    LowPassKnob->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    LowPassKnob->setColour (Slider::backgroundColourId, Colours::cadetblue);
    LowPassKnob->setColour (Slider::trackColourId, Colours::coral);
    LowPassKnob->setColour (Slider::rotarySliderFillColourId, Colours::aquamarine);
    LowPassKnob->setColour (Slider::rotarySliderOutlineColourId, Colours::cadetblue);
    LowPassKnob->setColour (Slider::textBoxTextColourId, Colours::aliceblue);
    LowPassKnob->setColour (Slider::textBoxBackgroundColourId, Colours::cadetblue);
    LowPassKnob->setColour (Slider::textBoxHighlightColourId, Colours::coral);
    LowPassKnob->setColour (Slider::textBoxOutlineColourId, Colours::cadetblue);
    LowPassKnob->addListener (this);

    addAndMakeVisible (PercentLabel = new Label ("Percent Label",
                                                 TRANS("%")));
    PercentLabel->setTooltip (TRANS("Wet/Dry Mix"));
    PercentLabel->setFont (Font (Font::getDefaultMonospacedFontName(), 18.00f, Font::bold));
    PercentLabel->setJustificationType (Justification::centredLeft);
    PercentLabel->setEditable (false, false, false);
    PercentLabel->setColour (Label::textColourId, Colours::azure);
    PercentLabel->setColour (TextEditor::textColourId, Colours::black);
    PercentLabel->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));

    addAndMakeVisible (KHzLabel = new Label ("KHz Label",
                                             TRANS("KHz")));
    KHzLabel->setTooltip (TRANS("Wet/Dry Mix"));
    KHzLabel->setFont (Font (Font::getDefaultMonospacedFontName(), 18.00f, Font::bold));
    KHzLabel->setJustificationType (Justification::centredLeft);
    KHzLabel->setEditable (false, false, false);
    KHzLabel->setColour (Label::textColourId, Colours::azure);
    KHzLabel->setColour (TextEditor::textColourId, Colours::black);
    KHzLabel->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));

    addAndMakeVisible (SecLabel2 = new Label ("sec Label",
                                              TRANS("sec")));
    SecLabel2->setTooltip (TRANS("Wet/Dry Mix"));
    SecLabel2->setFont (Font (Font::getDefaultMonospacedFontName(), 18.00f, Font::bold));
    SecLabel2->setJustificationType (Justification::centredLeft);
    SecLabel2->setEditable (false, false, false);
    SecLabel2->setColour (Label::textColourId, Colours::azure);
    SecLabel2->setColour (TextEditor::textColourId, Colours::black);
    SecLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("rel v1.0")));
    label->setFont (Font (6.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    cachedImage_pluginbkg_png = ImageCache::getFromMemory (pluginbkg_png, pluginbkg_pngSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (464, 296);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);
    BypassButton->setClickingTogglesState(true);
    //[/Constructor]
}

MoorerReverbAudioProcessorEditor::~MoorerReverbAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    DecayLabel = nullptr;
    MixLabel = nullptr;
    MixKnob = nullptr;
    BypassButton = nullptr;
    DecayKnob = nullptr;
    HeaderName = nullptr;
    LowPassLabel = nullptr;
    LowPassKnob = nullptr;
    PercentLabel = nullptr;
    KHzLabel = nullptr;
    SecLabel2 = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MoorerReverbAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff353131));

    g.setColour (Colours::black.withAlpha (0.850f));
    g.drawImage (cachedImage_pluginbkg_png,
                 0, 0, 464, 296,
                 0, 0, cachedImage_pluginbkg_png.getWidth(), cachedImage_pluginbkg_png.getHeight());

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MoorerReverbAudioProcessorEditor::resized()
{
    DecayLabel->setBounds (proportionOfWidth (0.1832f), proportionOfHeight (0.2939f), proportionOfWidth (0.1013f), proportionOfHeight (0.0811f));
    MixLabel->setBounds (proportionOfWidth (0.7069f), proportionOfHeight (0.2973f), proportionOfWidth (0.1013f), proportionOfHeight (0.0811f));
    MixKnob->setBounds (proportionOfWidth (0.7004f), proportionOfHeight (0.3987f), proportionOfWidth (0.1207f), proportionOfHeight (0.3311f));
    BypassButton->setBounds (proportionOfWidth (0.4160f), proportionOfHeight (0.8649f), proportionOfWidth (0.1746f), proportionOfHeight (0.0811f));
    DecayKnob->setBounds (proportionOfWidth (0.1724f), proportionOfHeight (0.3987f), proportionOfWidth (0.1207f), proportionOfHeight (0.3311f));
    HeaderName->setBounds (120, 24, 238, 40);
    LowPassLabel->setBounds (proportionOfWidth (0.4353f), proportionOfHeight (0.2973f), proportionOfWidth (0.1552f), proportionOfHeight (0.0811f));
    LowPassKnob->setBounds (proportionOfWidth (0.4504f), proportionOfHeight (0.4020f), proportionOfWidth (0.1207f), proportionOfHeight (0.3311f));
    PercentLabel->setBounds (proportionOfWidth (0.8190f), proportionOfHeight (0.6622f), proportionOfWidth (0.0517f), proportionOfHeight (0.0811f));
    KHzLabel->setBounds (proportionOfWidth (0.5690f), proportionOfHeight (0.6622f), proportionOfWidth (0.0668f), proportionOfHeight (0.0811f));
    SecLabel2->setBounds (proportionOfWidth (0.2910f), proportionOfHeight (0.6588f), proportionOfWidth (0.0668f), proportionOfHeight (0.0811f));
    label->setBounds (0, 272, 32, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MoorerReverbAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    MoorerReverbAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == MixKnob)
    {
        //[UserSliderCode_MixKnob] -- add your slider handling code here..
        ourProcessor->setParameterNotifyingHost(MoorerReverbAudioProcessor::Mix, (float)MixKnob->getValue());
        //[/UserSliderCode_MixKnob]
    }
    else if (sliderThatWasMoved == DecayKnob)
    {
        //[UserSliderCode_DecayKnob] -- add your slider handling code here..
        ourProcessor->setParameterNotifyingHost(MoorerReverbAudioProcessor::Decay, (float)DecayKnob->getValue());
        //[/UserSliderCode_DecayKnob]
    }
    else if (sliderThatWasMoved == LowPassKnob)
    {
        //[UserSliderCode_LowPassKnob] -- add your slider handling code here..
        ourProcessor->setParameterNotifyingHost(MoorerReverbAudioProcessor::LPF, (float)LowPassKnob->getValue());
        //[/UserSliderCode_LowPassKnob]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MoorerReverbAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    MoorerReverbAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == BypassButton)
    {
        //[UserButtonCode_BypassButton] -- add your button handler code here..
        ourProcessor->setParameterNotifyingHost(MoorerReverbAudioProcessor::MasterBypass, (float)BypassButton->getToggleState());
        //[/UserButtonCode_BypassButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MoorerReverbAudioProcessorEditor::visibilityChanged()
{
    //[UserCode_visibilityChanged] -- Add your code here...
    MoorerReverbAudioProcessor* ourProcessor = getProcessor();
    ourProcessor->RaiseUIUpdateFlag();
    //[/UserCode_visibilityChanged]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MoorerReverbAudioProcessorEditor::timerCallback(){
    MoorerReverbAudioProcessor* ourProcessor = getProcessor();
    //exchange any data you want between UI elements and the plugin "ourProcessor"
    if(ourProcessor->NeedsUIUpdate()){
        BypassButton->setToggleState(1.0f == ourProcessor->getParameter(MoorerReverbAudioProcessor::MasterBypass), juce::dontSendNotification);
        MixKnob->setValue(ourProcessor->getParameter(MoorerReverbAudioProcessor::Mix), juce::dontSendNotification);
        DecayKnob->setValue(ourProcessor->getParameter(MoorerReverbAudioProcessor::Decay), juce::dontSendNotification);
        LowPassKnob->setValue(ourProcessor->getParameter(MoorerReverbAudioProcessor::LPF), juce::dontSendNotification);
        ourProcessor->ClearUIUpdateFlag();
        //std::cout << "UIUpdated" << std::endl;
    }

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MoorerReverbAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="MoorerReverbAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="464" initialHeight="296">
  <METHODS>
    <METHOD name="visibilityChanged()"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff353131">
    <IMAGE pos="0 0 464 296" resource="pluginbkg_png" opacity="0.8499999999999999778"
           mode="0"/>
  </BACKGROUND>
  <LABEL name="Decay Label" id="a23f674e6696d274" memberName="DecayLabel"
         virtualName="" explicitFocusOrder="0" pos="18.319% 29.392% 10.129% 8.108%"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="ffffff" labelText="Decay"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="18" bold="1" italic="0"
         justification="36"/>
  <LABEL name="Mix Label" id="20f48f39f2927cb8" memberName="MixLabel"
         virtualName="" explicitFocusOrder="0" pos="70.69% 29.73% 10.129% 8.108%"
         tooltip="Wet/Dry Mix" textCol="fff0ffff" edTextCol="ff000000"
         edBkgCol="ffffff" labelText="Mix" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="18"
         bold="1" italic="0" justification="36"/>
  <SLIDER name="Mix Knob" id="a6e532f29a4cf942" memberName="MixKnob" virtualName=""
          explicitFocusOrder="1" pos="70.043% 39.865% 12.069% 33.108%"
          bkgcol="ff5f9ea0" trackcol="ffff7f50" rotarysliderfill="ff7fffd4"
          rotaryslideroutline="ff5f9ea0" textboxtext="fff0f8ff" textboxbkgd="ff5f9ea0"
          textboxhighlight="ffff7f50" textboxoutline="ff5f9ea0" min="0"
          max="100" int="1" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Bypass Button" id="8aa6c522d03341a2" memberName="BypassButton"
              virtualName="" explicitFocusOrder="0" pos="41.595% 86.486% 17.457% 8.108%"
              bgColOff="ff5f9ea0" bgColOn="ffff7f50" textCol="fff0ffff" textColOn="fff0ffff"
              buttonText="Bypass" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="Decay Knob" id="3915f5df8ccf2427" memberName="DecayKnob"
          virtualName="" explicitFocusOrder="1" pos="17.241% 39.865% 12.069% 33.108%"
          tooltip="Delay in milliseconds" bkgcol="ff5f9ea0" trackcol="ffff7f50"
          rotarysliderfill="ff7fffd4" rotaryslideroutline="ff5f9ea0" textboxtext="fff0f8ff"
          textboxbkgd="ff5f9ea0" textboxhighlight="ffff7f50" textboxoutline="ff5f9ea0"
          min="0.010000000000000000208" max="20" int="0.0010000000000000000208"
          style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Header" id="3f1695af01c1c947" memberName="HeaderName" virtualName=""
         explicitFocusOrder="0" pos="120 24 238 40" textCol="fff0f8ff"
         edTextCol="0" edBkgCol="0" labelText="Reverb Type II&#10;Moorer"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="22" bold="1" italic="1"
         justification="36"/>
  <LABEL name="LowPass Label" id="11c4343c7d7514b9" memberName="LowPassLabel"
         virtualName="" explicitFocusOrder="0" pos="43.534% 29.73% 15.517% 8.108%"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="ffffff" labelText="Low Pass"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="18" bold="1" italic="0"
         justification="36"/>
  <SLIDER name="LowPass Knob" id="12954a0884c33087" memberName="LowPassKnob"
          virtualName="" explicitFocusOrder="1" pos="45.043% 40.203% 12.069% 33.108%"
          tooltip="Frequency in KHz" bkgcol="ff5f9ea0" trackcol="ffff7f50"
          rotarysliderfill="ff7fffd4" rotaryslideroutline="ff5f9ea0" textboxtext="fff0f8ff"
          textboxbkgd="ff5f9ea0" textboxhighlight="ffff7f50" textboxoutline="ff5f9ea0"
          min="1000" max="12000" int="1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Percent Label" id="561e65aca138550e" memberName="PercentLabel"
         virtualName="" explicitFocusOrder="0" pos="81.897% 66.216% 5.172% 8.108%"
         tooltip="Wet/Dry Mix" textCol="fff0ffff" edTextCol="ff000000"
         edBkgCol="ffffff" labelText="%" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="18"
         bold="1" italic="0" justification="33"/>
  <LABEL name="KHz Label" id="bc97548b47a33b2a" memberName="KHzLabel"
         virtualName="" explicitFocusOrder="0" pos="56.897% 66.216% 6.681% 8.108%"
         tooltip="Wet/Dry Mix" textCol="fff0ffff" edTextCol="ff000000"
         edBkgCol="ffffff" labelText="KHz" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="18"
         bold="1" italic="0" justification="33"/>
  <LABEL name="sec Label" id="164ceeba83c7c7bf" memberName="SecLabel2"
         virtualName="" explicitFocusOrder="0" pos="29.095% 65.878% 6.681% 8.108%"
         tooltip="Wet/Dry Mix" textCol="fff0ffff" edTextCol="ff000000"
         edBkgCol="ffffff" labelText="sec" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="18"
         bold="1" italic="0" justification="33"/>
  <LABEL name="new label" id="cb079391a65e5832" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 272 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="rel v1.0" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="6"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: pluginbkg_png, 36205, "../../pluginbkg.png"
static const unsigned char resource_MoorerReverbAudioProcessorEditor_pluginbkg_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,208,0,0,1,40,8,6,0,0,0,232,156,160,116,0,0,0,6,98,75,71,68,
0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,9,11,20,47,2,217,204,96,98,0,0,0,29,105,84,88,116,67,111,109,109,101,110,116,0,0,0,
0,0,67,114,101,97,116,101,100,32,119,105,116,104,32,71,73,77,80,100,46,101,7,0,0,32,0,73,68,65,84,120,218,237,189,219,211,173,87,121,229,55,215,218,107,111,29,144,16,146,0,1,45,11,105,3,91,156,26,48,70,
96,16,1,53,9,93,118,23,134,182,83,101,187,226,38,185,207,31,192,133,255,6,255,13,190,240,13,23,169,50,149,196,137,203,78,92,157,118,130,148,78,219,110,27,220,54,13,22,225,96,130,57,52,72,128,78,251,180,
114,161,254,182,215,126,247,124,158,241,27,207,156,107,125,223,222,250,86,21,133,246,183,222,245,190,243,252,206,103,204,241,140,177,218,108,54,219,214,90,219,110,183,109,181,90,181,163,255,110,173,181,
213,106,117,237,239,187,255,127,244,233,125,127,244,81,247,136,158,149,221,119,249,140,229,39,42,75,244,253,178,46,203,178,239,254,125,249,155,94,249,123,207,89,214,109,247,147,213,69,213,49,43,171,219,
7,234,62,164,237,162,127,71,237,226,244,109,214,159,203,246,84,99,168,119,207,94,89,73,25,84,153,123,243,100,164,79,123,237,213,251,45,249,77,175,92,106,222,208,122,103,101,36,207,174,244,155,90,27,162,
103,168,245,67,205,155,145,241,90,89,15,102,244,145,187,222,68,235,32,41,71,165,31,220,251,85,126,55,82,254,221,235,86,71,47,208,153,133,155,209,8,179,6,192,161,158,121,28,229,61,244,39,218,8,220,140,
207,140,54,3,228,249,135,108,7,181,89,57,233,253,119,200,190,114,234,236,254,125,228,247,149,62,204,174,137,158,65,94,210,163,109,71,159,83,169,35,9,58,232,253,212,166,50,43,131,179,233,217,168,1,26,21,
42,170,108,111,167,178,94,175,187,59,224,172,17,143,238,83,29,24,106,7,217,123,230,122,189,14,119,166,217,14,177,247,219,232,55,116,177,142,234,157,213,69,69,36,42,226,86,8,3,45,71,117,33,234,253,38,171,
99,54,49,232,132,205,162,128,8,137,112,163,126,53,30,20,202,145,109,204,40,186,16,221,43,154,183,78,100,150,181,133,234,223,168,125,118,127,187,44,147,66,127,232,98,156,69,191,4,125,233,93,151,109,164,
179,223,246,158,93,137,130,105,61,212,122,214,91,235,163,245,63,155,35,42,42,238,253,91,205,49,130,64,186,239,7,181,94,70,107,242,106,179,217,108,221,2,18,72,110,36,116,119,96,138,202,203,178,10,205,101,
144,19,217,245,144,193,93,141,124,29,168,142,64,49,21,56,99,86,196,94,221,196,84,235,81,133,191,70,97,160,89,229,63,73,8,200,73,69,98,94,9,8,209,41,114,53,247,249,228,119,235,213,106,213,221,245,244,110,
118,20,73,46,175,141,118,183,189,127,247,174,93,254,61,42,79,239,121,235,245,250,134,223,246,254,221,43,127,86,70,21,157,236,94,163,202,144,213,35,251,222,137,180,119,127,115,84,79,210,174,189,54,81,253,
77,219,171,90,223,232,57,189,122,101,207,32,227,174,87,135,221,122,103,227,35,186,87,175,221,178,241,164,230,96,86,223,101,159,59,109,75,198,153,154,227,217,120,34,125,68,218,133,142,45,82,143,104,252,
146,251,185,109,169,230,75,239,217,217,250,232,246,171,90,147,178,62,201,238,145,173,207,189,235,163,0,70,245,109,246,92,53,175,40,2,163,218,90,182,203,185,115,231,182,17,46,172,8,18,4,214,168,238,2,179,
40,36,131,64,40,140,65,127,71,160,55,21,41,17,178,132,130,18,21,212,93,137,222,9,161,196,33,116,208,104,44,171,135,34,24,145,255,166,81,184,59,70,40,73,142,180,7,133,184,28,4,134,206,171,108,12,101,144,
191,59,191,40,202,225,156,89,209,250,146,163,11,23,165,136,208,46,178,238,101,80,243,73,137,154,247,197,85,33,243,244,56,202,71,137,120,233,11,254,232,5,122,146,67,240,91,1,110,24,33,163,168,243,78,135,
108,112,28,237,230,150,163,114,175,209,231,71,59,101,90,110,231,156,120,132,20,115,18,250,109,132,128,67,231,65,116,134,92,157,59,51,218,34,218,136,100,243,52,123,113,82,86,238,40,111,162,247,29,205,168,
160,229,157,49,150,179,57,72,179,52,156,117,147,180,135,218,228,111,72,68,151,117,66,84,8,21,157,169,93,37,33,225,16,66,13,29,156,75,194,130,90,232,40,105,134,16,10,212,223,143,254,221,43,203,200,194,
66,163,35,138,78,100,131,78,213,151,76,130,172,15,71,94,126,209,56,80,209,22,137,14,123,80,89,70,210,24,77,141,161,115,209,141,212,233,203,65,241,2,40,201,102,57,230,21,108,75,73,123,228,69,17,253,158,
46,198,217,216,136,234,146,181,191,234,235,229,115,50,114,19,133,126,123,215,147,190,174,242,2,122,227,54,42,115,111,93,84,40,33,33,93,101,237,29,182,201,185,115,231,182,78,126,218,8,9,136,134,208,179,
225,140,155,37,141,102,102,221,142,187,252,206,24,136,118,156,238,139,239,36,66,92,55,195,125,94,41,168,146,203,20,63,68,212,53,19,189,26,45,207,172,223,207,138,250,71,218,35,59,94,36,236,108,90,166,117,
68,34,57,186,145,34,167,100,187,170,44,234,81,68,130,172,28,106,7,181,220,77,169,221,31,57,164,175,68,116,217,129,57,33,42,245,202,166,200,5,170,127,232,253,170,100,147,163,255,222,29,43,89,153,122,207,
116,8,33,235,245,186,101,99,56,26,111,21,130,10,29,135,209,181,132,132,145,245,69,52,31,201,120,34,100,11,213,246,85,114,138,26,95,170,172,106,14,171,239,136,96,74,175,61,150,17,71,70,78,161,235,14,37,
90,70,209,245,114,147,169,198,49,153,119,238,56,86,125,21,245,183,90,15,233,216,140,218,35,139,62,179,20,57,183,253,174,251,223,109,183,221,182,117,20,64,50,88,151,252,150,146,70,92,120,43,27,212,52,167,
200,73,159,112,72,68,78,4,229,42,214,184,234,56,21,130,24,137,22,29,5,28,250,98,158,69,48,168,18,160,84,191,186,105,85,179,35,202,17,18,89,5,85,202,230,1,37,85,237,19,49,216,39,26,83,129,32,79,42,58,112,
146,144,139,125,162,49,135,232,247,213,237,183,223,190,37,187,253,17,210,195,12,104,32,218,49,86,136,4,163,74,32,251,132,102,142,3,14,218,71,251,87,84,70,70,212,84,102,66,90,142,56,131,59,71,220,182,164,
60,131,81,2,151,34,108,84,202,234,180,111,38,204,66,88,234,35,227,131,156,251,171,62,35,2,49,170,172,180,222,14,52,73,21,120,178,114,86,235,70,100,24,213,51,41,204,74,174,163,130,9,189,0,34,10,44,54,209,
128,84,130,9,234,33,213,137,164,118,2,209,238,142,164,65,84,136,26,52,250,114,38,164,130,117,28,162,84,37,202,85,233,58,217,129,62,85,116,25,125,145,103,125,167,22,29,181,128,184,81,155,67,154,201,162,
235,136,244,64,216,127,68,69,169,26,253,246,238,27,169,0,209,180,32,7,45,82,4,46,213,158,36,50,142,198,105,70,154,82,40,90,246,50,161,71,89,42,202,39,144,250,18,106,86,107,100,86,71,250,219,232,154,108,
76,100,132,164,222,239,35,178,152,34,186,85,142,215,178,53,170,87,158,107,117,186,253,246,219,183,251,14,115,79,97,139,147,91,174,91,157,136,242,74,212,142,29,137,66,103,146,80,70,181,77,247,209,31,135,
238,83,146,26,227,164,79,140,214,109,166,214,239,190,250,99,132,236,69,81,177,89,196,172,245,168,242,198,82,121,37,59,48,38,187,41,247,223,17,49,132,40,104,68,215,101,229,35,74,67,89,155,17,146,144,67,
50,81,223,245,218,133,144,57,8,97,132,16,127,42,4,179,172,159,233,238,50,139,218,136,106,75,244,44,170,28,67,250,137,160,51,217,184,166,207,237,33,16,189,251,169,8,200,237,255,44,149,135,16,250,148,30,
182,234,187,136,144,67,230,1,85,246,169,172,115,148,12,179,139,88,168,114,103,99,157,148,147,146,217,150,136,136,171,78,68,214,188,222,125,179,254,202,198,109,143,120,21,141,161,76,239,55,172,195,157,
119,222,185,205,96,10,21,62,187,2,197,142,253,89,37,122,26,209,156,117,245,97,171,240,88,53,82,116,161,246,106,189,92,88,147,214,109,70,110,229,140,84,166,125,164,68,85,239,63,154,98,53,154,2,54,218,22,
149,113,61,138,122,84,211,235,110,150,207,105,122,210,205,131,48,172,103,237,122,221,148,128,44,205,97,249,93,52,73,149,182,45,77,29,89,254,118,87,219,54,122,166,147,134,146,221,143,82,196,143,238,81,
209,183,117,232,244,75,221,224,44,61,37,186,182,18,193,141,94,175,158,25,165,127,144,118,113,35,205,172,191,163,177,238,142,133,8,253,81,243,178,162,251,235,244,15,105,87,130,202,100,255,189,236,191,165,
22,117,246,255,234,133,239,232,244,58,72,137,211,62,187,115,125,164,204,42,98,85,99,164,210,231,170,15,20,138,81,77,123,81,72,135,163,71,237,156,255,94,139,64,29,60,190,162,237,232,106,100,70,48,80,116,
126,64,217,99,42,138,80,13,71,152,100,14,213,159,68,102,84,210,204,209,223,85,145,165,163,243,75,251,157,254,59,234,103,66,252,90,182,75,213,225,38,122,182,107,100,61,35,74,115,208,26,226,202,227,32,69,
20,237,217,87,4,236,154,175,87,163,61,55,229,200,105,147,125,70,148,35,142,75,251,78,179,170,254,214,69,237,42,58,220,174,219,83,248,178,126,213,171,94,181,247,120,247,86,133,36,142,219,108,249,180,237,
14,3,249,56,132,138,153,186,191,135,128,174,8,163,212,105,159,147,70,218,114,53,93,179,141,216,62,84,137,156,49,164,12,37,92,3,110,87,151,185,170,67,221,219,204,141,140,75,39,56,170,18,138,104,251,109,
148,25,182,35,120,16,189,60,119,13,181,123,215,147,116,10,181,123,36,141,228,238,76,42,162,204,213,9,66,22,175,74,62,26,105,19,71,27,52,219,37,210,124,189,138,89,58,213,3,37,200,129,59,177,162,246,142,
8,31,51,54,17,174,246,172,26,107,89,234,82,180,24,19,215,156,108,254,102,209,124,239,55,149,115,120,117,30,159,245,165,163,221,170,132,197,163,177,231,34,115,170,29,178,212,13,58,215,200,189,171,158,202,
82,120,96,18,15,166,178,254,68,207,81,117,74,97,223,187,238,186,107,235,194,108,35,81,167,75,226,113,95,216,10,134,171,168,189,144,23,176,3,65,85,158,185,111,68,96,134,46,241,73,37,115,28,162,44,251,34,
234,204,168,215,41,41,229,244,115,51,32,80,135,190,199,12,199,165,117,180,171,81,111,241,229,223,41,157,59,59,108,87,228,161,35,221,211,138,49,182,34,68,101,212,235,30,113,38,251,109,86,14,213,153,71,
245,204,232,223,78,123,47,127,151,149,81,213,69,221,43,35,115,100,247,115,55,11,21,221,202,236,186,145,242,236,18,169,8,105,70,61,223,157,99,209,53,202,224,91,181,153,42,143,155,190,161,250,106,121,31,
53,214,201,152,138,202,166,12,209,179,242,100,107,128,155,102,68,214,86,66,130,169,106,140,147,190,112,223,11,52,93,46,210,25,38,41,66,203,52,154,110,100,8,245,147,157,245,181,91,207,187,238,186,107,235,
146,33,156,8,100,134,105,169,130,108,171,250,157,170,220,20,14,116,163,184,42,52,70,188,236,40,116,71,108,159,28,248,132,68,97,170,61,169,241,46,49,150,174,144,125,28,195,236,106,164,56,67,151,183,130,
94,184,41,67,149,57,185,207,40,119,31,206,77,163,72,207,204,186,207,24,91,46,218,116,82,16,151,125,35,90,149,180,68,188,38,221,125,247,221,40,126,157,97,152,60,170,254,64,165,228,110,22,181,146,81,59,
29,122,110,186,79,243,230,138,126,231,44,11,35,26,185,209,54,34,245,162,191,207,234,48,91,183,119,70,255,206,208,183,165,68,146,104,243,71,199,183,218,140,146,62,116,96,187,108,67,53,227,119,206,186,166,
234,84,169,51,157,159,202,96,66,245,157,203,89,169,206,21,183,141,162,13,21,25,243,27,58,192,179,142,32,187,117,98,216,75,34,156,172,81,162,74,187,68,4,210,241,138,160,164,58,202,157,208,196,56,89,117,
186,83,46,178,41,81,187,239,76,87,151,148,135,180,65,212,183,174,59,144,218,144,244,116,129,157,136,156,140,87,58,198,150,247,86,168,16,65,58,72,132,175,230,43,73,79,234,105,251,58,78,77,42,2,172,8,44,
84,56,17,149,128,192,81,125,27,125,193,16,196,46,211,64,166,136,92,54,255,8,132,93,53,195,118,142,196,50,211,112,186,121,10,199,206,171,95,253,234,45,133,40,170,70,217,135,130,121,70,194,250,89,208,208,
172,124,178,227,130,124,78,26,116,119,250,57,253,28,242,227,166,52,28,74,103,216,69,33,246,105,106,189,79,84,107,164,220,51,82,178,156,113,208,218,127,214,194,85,59,179,35,18,194,146,36,226,232,211,238,
222,199,33,170,16,253,196,138,249,53,213,178,221,253,244,202,31,213,39,83,44,202,140,202,213,78,139,104,144,102,109,69,204,167,201,46,239,104,44,168,122,46,203,227,24,156,211,114,85,136,29,84,243,152,
182,17,237,23,53,110,168,62,43,41,115,181,14,100,46,59,237,230,168,198,40,98,145,42,51,33,9,18,200,85,189,56,40,169,167,247,59,53,94,40,217,206,33,146,17,114,86,117,141,84,100,71,50,166,34,237,234,172,
45,50,237,223,222,243,50,61,225,172,236,169,106,211,61,247,220,179,117,148,77,8,100,68,115,10,103,40,200,184,122,176,78,68,230,16,50,102,71,98,78,14,92,69,183,183,98,137,70,115,68,93,40,140,64,237,78,
189,28,85,164,145,122,204,80,58,154,81,151,125,17,132,102,161,49,206,239,102,165,112,237,67,173,104,244,25,51,181,157,79,63,39,4,177,184,231,158,123,246,110,168,237,236,244,102,133,240,179,160,8,66,142,
152,85,31,245,123,199,100,119,4,34,113,21,81,200,119,228,44,121,6,188,179,207,49,90,21,169,24,141,124,162,113,224,248,206,186,230,195,217,134,182,66,230,82,226,37,35,4,19,7,194,116,198,33,189,47,237,247,
42,9,210,237,219,168,191,93,22,123,244,91,186,54,81,238,4,49,37,167,144,106,180,73,119,148,139,8,119,226,186,23,168,123,190,217,107,108,87,3,55,234,112,66,136,80,141,162,202,92,117,72,113,68,29,20,177,
68,41,123,144,69,195,141,6,212,132,39,26,191,199,69,253,199,3,90,16,186,200,24,81,147,104,100,44,57,247,174,70,155,106,92,209,205,160,107,60,238,174,27,25,98,229,162,71,35,14,45,174,246,180,51,207,246,
133,108,85,234,20,205,231,125,138,124,140,166,168,184,107,238,136,18,84,229,126,171,215,188,230,53,219,147,64,8,57,133,51,78,63,35,72,65,37,162,223,103,89,15,125,175,67,144,84,70,174,59,110,141,232,147,
210,239,106,195,183,207,241,63,67,118,180,170,123,235,180,15,217,236,41,132,204,65,74,170,209,243,53,45,220,235,222,168,70,254,155,211,8,20,166,152,49,24,168,43,134,251,55,5,43,16,230,177,163,219,75,157,
234,179,29,157,58,195,38,78,46,14,156,79,32,250,10,92,66,244,115,73,189,156,220,206,42,220,69,218,130,68,198,42,234,207,118,215,196,233,135,56,223,40,72,215,213,55,38,194,30,4,165,137,16,134,12,122,86,
235,140,131,14,85,230,127,150,94,85,129,23,71,145,21,2,155,171,181,80,173,233,189,212,181,172,189,123,105,78,81,25,84,170,20,41,123,54,46,178,49,116,173,62,247,222,123,239,214,129,97,70,52,84,221,208,
159,156,163,140,60,135,134,246,35,6,198,51,148,141,102,215,205,65,0,102,89,33,29,2,137,216,183,30,237,44,18,200,73,39,147,28,23,233,232,144,247,61,69,188,78,30,202,228,68,141,251,70,175,104,121,214,187,
63,80,116,243,76,131,118,36,57,120,247,249,75,13,79,55,93,197,161,238,143,24,0,211,52,11,146,6,208,51,53,174,80,220,73,25,105,218,144,234,67,66,137,175,164,68,144,116,3,183,14,78,189,232,78,188,103,102,
237,26,254,146,246,82,166,192,85,173,92,210,190,36,45,41,43,11,153,187,149,212,24,39,245,37,107,215,168,190,238,184,36,186,171,84,247,119,228,229,67,83,141,156,241,234,24,135,43,173,224,172,205,150,98,
30,149,241,214,251,13,65,58,163,116,26,146,38,179,186,239,190,251,182,20,150,170,166,11,68,16,72,4,3,80,104,135,42,253,56,240,13,133,23,21,156,229,168,250,56,17,30,37,3,16,182,159,211,95,238,65,123,150,
242,50,146,162,51,162,107,89,141,218,41,35,81,213,205,133,177,247,17,49,57,100,41,74,248,137,160,206,81,228,136,66,152,100,156,205,72,251,161,242,111,46,57,104,102,20,237,166,29,146,121,228,174,81,179,
81,200,67,165,107,85,220,141,86,247,221,119,223,137,115,127,30,49,37,166,7,229,251,54,116,174,66,18,135,208,172,61,52,124,146,149,193,213,66,173,106,237,142,154,62,87,206,55,213,248,163,109,174,218,97,
164,255,246,61,222,156,250,86,250,45,219,52,146,148,16,122,127,170,235,234,156,45,146,241,227,152,185,207,130,56,71,245,143,15,169,80,228,4,57,142,118,113,54,94,118,255,189,81,81,159,138,70,73,42,1,125,
137,69,6,198,100,145,84,46,48,61,195,227,10,235,140,68,157,217,132,83,17,9,29,236,217,46,157,46,252,132,170,79,92,96,84,52,147,157,7,103,81,6,141,170,35,82,1,209,150,85,14,66,25,82,160,144,16,117,14,238,
142,9,165,1,77,163,74,162,41,77,202,84,209,73,37,233,50,202,24,58,26,51,189,118,37,68,16,18,21,82,115,233,30,156,24,233,65,71,101,206,96,119,122,157,131,88,209,227,27,39,189,199,65,237,40,97,81,205,179,
202,243,233,24,15,215,190,251,239,191,127,91,205,139,116,96,146,217,38,209,135,212,143,157,1,169,204,50,63,118,9,40,251,172,243,108,242,211,73,248,28,135,49,246,73,255,236,219,209,231,184,163,229,67,60,
235,16,101,223,23,146,116,232,241,226,34,87,179,218,214,217,72,31,253,237,154,161,182,75,58,217,253,221,209,127,239,146,42,122,6,195,14,153,161,247,155,221,191,245,76,130,29,147,100,231,128,122,249,12,
71,111,179,162,107,234,106,166,170,251,169,191,81,163,95,215,152,86,17,96,162,122,144,231,40,93,212,222,181,100,44,19,195,119,53,15,70,250,90,141,35,53,182,221,182,163,229,80,122,194,132,60,227,18,148,
150,247,136,180,76,221,241,152,105,235,102,81,9,37,232,208,151,26,105,11,213,150,81,144,226,232,215,186,235,26,37,63,69,186,182,202,188,156,68,153,203,116,23,218,239,170,31,163,192,39,50,242,94,221,127,
255,253,219,138,253,152,138,42,71,21,103,92,165,22,5,117,208,251,84,9,59,10,43,167,58,178,163,132,23,5,75,58,247,28,33,229,28,2,81,56,196,253,71,85,106,104,174,177,91,78,18,41,59,249,129,170,140,46,9,
101,180,126,35,136,79,181,220,251,66,32,142,27,185,56,9,41,103,183,34,90,213,90,107,171,215,190,246,181,83,227,253,170,94,233,113,193,67,163,196,22,2,5,68,139,237,76,213,150,153,191,217,167,230,44,125,
102,213,63,149,38,183,143,192,71,135,152,47,251,202,95,115,54,196,206,248,172,232,235,146,246,37,6,220,68,30,52,155,131,142,246,51,189,70,149,153,142,127,87,31,55,27,63,179,173,194,92,185,85,122,125,86,
239,202,156,28,49,86,87,191,221,184,145,101,180,160,29,253,189,74,244,113,14,153,73,71,184,11,35,49,119,142,140,98,179,23,165,99,2,78,232,231,212,224,154,18,191,20,43,49,131,180,72,219,81,103,120,162,
18,226,24,111,103,36,46,34,204,238,152,127,83,98,87,175,253,163,254,140,22,40,71,11,121,196,223,150,242,34,20,204,70,210,58,28,98,142,138,46,123,247,85,36,35,58,102,84,95,43,66,91,54,54,92,2,23,217,172,
71,36,40,26,189,43,226,21,85,122,114,24,201,61,219,183,172,78,228,157,148,181,19,49,113,79,199,216,235,94,247,186,45,121,105,30,7,228,112,146,62,167,202,37,39,4,50,217,83,116,62,59,162,126,37,221,103,
36,34,152,81,62,234,238,113,28,40,207,73,65,58,42,81,22,141,210,43,228,37,42,5,58,130,208,80,9,211,145,118,191,198,138,88,175,215,55,16,127,232,142,118,68,141,40,34,107,84,8,77,203,255,39,230,194,196,
164,155,16,34,148,50,79,245,229,75,204,160,51,242,132,179,163,207,218,160,87,134,81,101,40,218,86,84,249,41,51,44,142,250,50,35,147,16,210,131,34,182,208,126,202,82,58,28,50,79,68,36,113,8,54,217,179,
9,225,80,153,131,83,87,152,172,15,21,74,178,187,233,165,170,89,206,156,160,4,165,232,187,40,10,38,68,60,162,14,68,13,236,201,220,233,149,87,165,26,169,177,149,33,76,89,148,27,161,8,36,173,133,88,245,217,
235,250,81,4,90,9,241,157,104,109,68,237,132,192,183,142,21,27,129,167,21,116,173,32,180,17,117,159,8,106,32,101,217,119,244,61,90,247,209,254,169,192,144,51,210,135,102,35,22,21,59,167,147,130,154,204,
54,87,223,55,90,116,220,41,111,55,35,233,238,86,70,164,102,126,214,187,209,30,209,127,165,250,137,36,138,168,236,98,137,246,170,138,134,122,154,190,228,94,71,191,203,52,81,157,232,37,107,151,221,103,145,
118,82,145,165,19,33,102,59,227,44,149,131,68,167,36,154,114,235,155,141,207,168,207,104,228,171,202,77,163,119,18,85,102,215,186,40,2,69,16,156,182,142,162,147,165,102,53,137,96,157,177,234,92,31,165,
184,101,145,94,239,126,217,26,161,198,193,178,174,203,49,72,198,31,105,187,170,46,55,89,227,85,91,85,210,30,9,2,233,244,81,230,214,228,140,105,138,176,246,238,181,33,90,170,203,131,221,12,107,238,145,
130,178,176,89,41,197,244,238,27,133,244,142,61,153,130,148,40,59,47,139,38,50,85,165,222,247,106,215,76,40,251,142,181,147,218,209,57,106,69,106,0,186,196,145,172,188,10,45,113,137,113,17,161,39,83,176,
33,11,147,106,115,138,116,100,243,47,154,11,209,188,164,196,164,140,60,19,89,69,101,127,239,41,240,144,126,83,231,90,25,60,231,110,224,84,27,146,151,80,166,146,20,229,150,146,249,71,231,94,54,102,149,
90,86,212,190,116,60,168,245,166,98,146,30,193,188,149,64,42,59,50,81,106,109,225,61,31,120,224,129,114,252,123,10,35,220,92,176,195,204,244,132,147,214,22,21,210,203,108,162,76,197,132,184,82,214,147,
72,56,201,152,205,132,164,50,210,55,39,101,92,82,61,89,215,31,88,181,189,106,75,90,175,138,100,167,98,15,59,107,82,69,39,90,173,109,116,140,86,215,210,141,218,57,209,40,113,100,96,56,59,76,58,1,179,103,
57,14,51,36,191,204,233,56,55,18,113,163,72,165,29,153,149,137,230,183,170,201,165,38,132,218,245,57,11,66,20,5,144,5,90,69,180,149,92,202,204,68,153,204,141,40,106,118,157,71,156,136,157,156,99,71,168,
4,213,20,38,199,43,174,240,59,65,148,8,103,194,21,80,81,139,60,209,221,37,125,159,105,251,146,121,221,171,151,147,22,71,250,201,157,239,74,107,54,67,115,8,242,165,82,109,136,102,186,218,0,94,87,190,55,
188,225,13,91,85,185,153,68,145,209,104,119,68,225,136,188,136,220,133,102,102,212,62,98,243,85,185,31,173,87,229,62,196,72,220,237,183,81,36,100,166,202,143,123,223,147,78,74,57,253,220,250,8,212,73,
173,223,62,82,138,246,149,210,180,188,239,58,34,135,28,93,236,80,167,151,191,203,48,104,18,129,45,127,163,14,180,85,121,9,25,33,195,212,9,177,32,171,19,53,249,93,254,158,144,16,42,109,167,218,128,146,
36,122,215,28,149,249,40,61,74,141,169,168,46,75,146,219,136,113,123,69,243,120,249,187,222,24,80,68,165,170,30,103,84,70,55,221,204,209,233,165,166,242,180,189,157,242,168,117,134,144,96,156,54,161,70,
220,206,220,38,132,204,101,122,13,41,39,213,163,37,164,45,69,102,114,214,112,39,101,142,110,74,93,162,96,244,66,164,92,5,183,15,175,187,254,141,111,124,227,182,18,161,144,8,67,105,206,18,19,109,5,165,
58,42,23,142,28,149,82,36,34,240,160,250,189,130,40,42,145,90,86,111,58,128,43,186,185,89,219,80,169,53,2,193,57,246,106,189,126,217,103,90,8,77,189,170,164,49,141,140,13,7,69,24,69,37,20,146,51,170,77,
75,52,187,43,71,29,51,209,134,125,245,9,65,201,70,230,245,205,130,140,156,36,93,221,238,11,244,56,97,134,125,170,125,144,239,246,69,48,57,201,109,87,49,104,158,105,132,237,150,85,149,237,144,237,70,97,
34,247,89,148,1,222,219,116,204,108,71,71,246,208,37,90,69,207,31,33,147,204,128,239,42,122,183,213,123,142,180,225,232,152,27,33,168,205,34,127,81,191,98,170,103,76,3,40,50,31,8,55,98,227,12,42,181,59,
166,46,37,106,215,72,205,130,9,213,188,194,20,35,245,87,3,64,117,28,21,143,38,169,43,106,146,71,191,83,187,88,162,25,169,234,152,237,132,221,251,186,6,208,238,162,151,141,211,94,217,148,41,114,180,59,
166,178,104,74,115,152,146,118,178,223,184,122,215,17,188,69,84,94,20,28,28,233,202,58,112,189,74,191,32,47,245,172,252,106,158,208,107,119,203,75,201,88,164,13,123,237,81,65,245,20,26,210,107,163,104,
124,171,250,84,210,210,84,14,168,51,30,137,14,119,88,206,55,189,233,77,123,11,157,102,147,59,70,158,235,18,61,70,96,204,125,194,30,199,69,222,58,20,172,117,250,185,249,62,163,8,204,62,116,136,103,166,
14,237,235,57,85,84,98,70,155,237,43,133,203,45,195,108,52,105,31,117,207,202,184,86,187,152,145,195,251,10,145,199,49,36,142,158,215,187,159,34,94,180,214,186,100,151,232,223,84,193,41,219,5,87,136,37,
206,97,61,81,65,34,215,147,182,165,247,89,214,91,233,210,86,213,125,84,125,169,249,185,75,158,81,227,159,246,161,51,30,20,17,205,49,77,118,205,156,9,225,67,41,236,100,47,39,167,255,122,145,20,49,220,86,
253,155,233,165,246,162,32,170,122,165,218,85,57,193,56,74,110,81,132,72,198,13,157,191,217,88,35,238,55,46,169,138,142,235,76,200,194,157,187,55,220,251,77,111,122,211,150,66,16,35,233,20,180,176,149,
20,147,140,64,51,51,74,36,105,27,163,209,237,172,3,114,87,183,152,194,169,180,60,163,81,233,33,116,92,71,158,233,142,253,89,104,198,113,68,251,51,73,27,179,82,177,78,210,152,186,21,62,251,108,155,147,
168,151,60,235,179,118,52,111,157,52,10,181,99,81,105,2,21,7,145,158,6,38,77,249,112,118,117,149,104,161,170,227,73,126,31,105,233,18,154,250,178,189,151,81,56,65,19,104,52,72,162,211,30,26,64,251,136,
244,113,229,190,100,39,60,130,208,68,218,199,142,163,16,153,191,116,135,77,144,25,162,41,93,73,105,88,126,215,27,143,84,190,77,233,219,86,16,133,138,190,180,131,44,145,168,103,100,254,101,17,38,69,120,
168,243,76,180,22,41,157,91,215,249,198,69,167,232,51,201,60,220,244,32,130,204,12,123,121,29,137,36,137,166,106,164,153,73,228,164,212,57,1,61,220,142,34,45,117,46,50,139,240,144,181,9,81,232,32,102,
176,189,54,34,191,113,133,54,42,36,18,119,97,239,61,75,165,28,85,156,115,162,118,161,166,187,164,253,122,253,18,141,77,167,189,21,113,137,146,71,200,119,14,91,82,165,166,16,13,218,10,209,47,211,122,174,
136,171,56,235,166,171,117,77,54,11,21,173,101,2,11,211,20,67,135,72,231,108,34,104,238,168,130,181,85,95,244,214,5,122,132,179,90,173,218,234,193,7,31,220,146,197,242,80,240,192,113,91,15,157,126,246,
147,150,83,77,23,56,238,178,187,101,172,166,1,220,172,253,63,187,190,213,118,37,105,63,106,163,114,200,113,178,175,113,94,253,251,172,242,187,26,190,206,70,136,182,135,171,25,172,54,152,89,26,215,154,
64,78,20,194,117,13,171,137,89,108,22,86,43,248,107,4,158,113,160,236,202,14,171,178,203,116,72,33,116,199,26,69,109,14,12,73,213,170,168,195,7,141,92,29,168,202,129,126,137,89,176,3,31,102,196,25,7,178,
165,42,53,164,159,137,122,23,109,123,162,224,210,91,176,168,42,23,129,171,201,217,106,100,136,174,92,82,104,58,74,149,116,67,142,157,148,154,81,102,52,157,65,160,153,227,15,177,96,36,182,99,217,154,209,
187,71,143,92,164,214,26,181,102,169,177,70,214,188,110,219,62,248,224,131,219,125,30,30,207,52,130,118,69,160,105,132,74,8,73,234,94,179,162,224,125,234,170,30,66,141,199,253,205,190,201,66,35,42,56,
251,66,62,102,18,197,78,138,10,141,154,131,167,168,209,205,137,28,157,214,47,255,172,171,81,83,37,170,171,68,3,78,68,225,106,165,246,238,19,153,3,239,126,223,187,47,73,147,33,187,52,18,17,100,102,219,
89,20,30,165,155,56,125,175,118,165,174,113,122,68,80,33,187,214,12,5,232,181,145,34,104,185,117,161,105,72,52,53,199,53,255,166,81,32,169,187,106,111,7,181,81,250,197,212,232,220,53,160,118,34,198,10,
209,135,180,151,131,16,41,36,64,69,146,81,148,79,8,49,110,164,76,163,71,71,91,218,49,22,239,161,54,132,212,68,163,123,117,191,232,251,141,138,216,136,218,15,33,32,184,209,97,70,168,32,106,25,142,153,112,
22,121,170,195,234,17,243,234,172,29,21,73,35,155,64,68,68,89,41,148,56,80,56,53,160,37,125,173,32,178,8,238,237,213,157,246,45,61,235,33,132,154,104,12,56,6,6,84,183,217,81,203,161,125,82,33,129,100,
234,46,164,29,232,188,82,227,153,206,63,250,178,117,12,200,123,16,168,82,113,138,198,155,154,251,116,142,103,117,117,209,40,85,87,98,104,63,106,48,82,13,142,148,89,188,19,48,222,80,206,135,30,122,232,
150,141,249,15,169,18,114,92,207,56,169,117,84,114,117,85,69,149,89,214,71,132,72,48,66,20,170,16,44,104,251,185,237,61,187,109,169,14,236,204,178,84,117,118,149,46,238,104,121,233,24,217,7,153,168,50,
119,122,253,70,245,142,103,104,240,42,169,81,82,30,119,78,57,126,204,142,22,238,106,181,106,235,202,14,147,90,254,184,180,229,74,254,28,201,7,34,57,124,209,127,43,197,14,66,146,82,36,137,40,5,195,33,169,
184,237,156,61,159,90,173,85,162,236,232,240,158,230,100,101,228,27,186,195,85,16,81,47,130,32,4,30,170,2,227,150,83,221,39,35,94,144,57,219,131,200,20,164,71,16,37,149,86,147,149,41,67,91,92,2,19,93,
15,178,40,73,181,167,130,250,92,221,86,247,232,74,245,23,65,16,105,212,26,145,152,104,110,42,69,151,50,114,143,51,183,34,98,149,130,156,9,18,180,122,243,155,223,188,173,132,244,25,52,70,39,147,243,169,
144,19,246,173,98,178,239,244,156,125,220,227,244,179,159,177,112,179,246,211,113,18,51,92,215,146,25,17,216,33,210,179,110,214,62,113,34,204,153,200,215,108,205,97,199,104,99,116,172,173,157,168,194,
85,188,81,81,2,77,143,32,59,7,55,201,216,193,226,51,210,71,133,174,238,168,127,92,215,89,65,91,187,145,183,218,25,58,233,17,4,125,112,202,74,82,137,72,164,71,162,186,108,23,79,144,15,218,111,36,26,170,
168,162,16,146,19,137,152,201,125,221,190,116,72,61,217,185,116,22,217,101,145,11,105,119,53,174,8,210,228,160,18,84,67,56,91,79,28,162,17,69,11,163,200,79,161,118,228,158,164,45,213,139,218,153,239,78,
54,69,132,144,208,244,160,214,90,91,61,252,240,195,91,74,36,32,127,207,222,240,35,169,12,142,61,14,137,148,41,33,201,141,194,43,174,47,189,114,141,68,213,196,236,156,70,239,202,182,140,234,37,239,211,
117,198,29,19,179,250,190,130,84,40,11,182,125,56,0,205,78,233,153,145,150,116,8,244,166,242,12,151,236,56,162,96,180,143,250,236,115,76,239,59,53,234,102,68,216,86,15,63,252,240,182,26,198,143,134,236,
51,97,13,199,176,150,134,238,68,90,109,38,196,48,27,226,153,209,222,85,50,132,67,162,33,112,203,108,197,34,210,174,153,247,108,182,240,142,18,113,162,13,89,85,177,197,245,151,173,244,125,117,14,140,206,
197,125,140,115,34,59,74,250,199,173,191,58,167,140,250,169,2,203,86,231,151,234,55,42,49,74,199,99,182,65,118,230,12,13,190,20,113,106,249,185,65,11,119,183,96,35,108,45,26,141,80,119,122,18,169,81,99,
95,98,136,157,105,112,246,174,165,250,162,61,56,64,185,201,208,201,27,45,36,212,164,154,180,47,129,109,162,73,64,181,149,201,164,202,202,75,29,80,156,69,204,165,250,171,123,83,13,81,162,243,155,141,243,
236,229,146,181,153,130,186,201,252,112,17,26,66,134,203,218,174,130,156,169,182,219,189,46,210,213,38,27,21,39,234,138,210,178,162,245,163,114,68,69,172,209,220,35,61,162,59,219,107,119,117,164,231,152,
111,211,99,60,106,84,174,54,152,171,71,30,121,100,59,59,132,30,133,103,14,17,202,223,204,132,156,83,50,209,254,208,138,67,151,133,110,228,14,81,246,147,168,244,178,175,50,101,81,199,62,202,74,163,166,
74,89,20,114,226,164,113,40,148,141,254,109,36,165,106,182,209,54,65,114,170,207,218,92,39,140,187,94,219,185,103,189,1,120,116,31,18,189,70,247,117,36,251,104,39,239,254,189,87,70,10,103,100,59,175,108,
64,147,40,62,139,208,118,255,187,2,141,168,29,182,187,48,56,110,59,217,70,192,133,41,233,179,104,116,167,162,43,10,253,68,99,196,57,255,92,70,30,52,143,150,56,11,101,109,191,68,8,104,100,166,34,187,172,
109,136,192,5,185,38,122,62,233,231,40,205,132,190,120,40,148,152,69,52,187,125,30,69,255,212,155,119,55,66,143,34,85,135,79,226,206,53,138,40,169,104,84,173,155,180,207,93,177,17,23,94,95,157,63,127,
126,235,96,208,213,8,136,68,154,142,154,8,193,176,73,153,84,163,86,201,40,170,60,10,110,26,33,186,204,248,222,125,249,205,34,170,40,184,157,252,118,68,35,150,140,245,227,66,77,70,17,139,234,152,170,140,
239,67,35,43,135,210,254,221,135,134,247,233,231,230,66,47,118,63,55,164,177,244,52,93,221,179,48,87,134,169,71,15,142,52,103,151,81,170,227,80,145,221,195,165,193,171,118,80,105,7,153,54,169,75,71,119,
251,75,181,79,166,235,235,184,233,80,129,135,236,55,235,245,186,155,46,148,161,22,36,85,35,42,67,79,155,215,45,183,155,102,67,230,144,74,157,200,202,16,153,214,211,50,186,169,102,217,28,35,238,65,81,27,
70,117,238,105,235,146,52,37,149,202,82,73,71,233,221,103,87,95,187,103,68,238,200,204,17,77,223,172,62,238,90,64,53,125,105,159,146,180,63,242,119,82,134,72,236,129,140,15,242,252,27,32,92,55,76,86,112,
174,138,44,29,189,87,10,209,170,243,5,69,166,33,198,216,78,84,212,219,137,86,217,95,85,3,107,101,252,172,32,14,74,206,112,210,103,148,81,50,53,116,119,77,215,21,139,214,209,228,117,94,132,46,156,68,180,
155,29,13,100,213,55,234,133,21,253,94,29,163,16,50,154,131,150,184,27,90,98,148,156,193,171,17,154,47,96,118,0,0,32,0,73,68,65,84,4,75,81,15,146,214,68,218,81,29,47,40,237,96,5,235,210,113,158,193,194,
100,220,80,221,116,39,72,80,155,253,12,21,35,106,77,105,91,188,229,45,111,185,117,253,111,78,63,83,224,14,74,112,57,9,208,203,44,125,80,231,254,85,211,97,114,30,94,77,157,112,136,28,46,137,101,31,253,
79,181,147,221,254,217,71,202,92,181,30,163,207,157,105,22,78,120,13,106,12,186,101,35,101,30,189,191,74,99,33,109,75,230,195,53,52,71,65,153,51,148,75,28,205,88,170,167,72,97,54,2,213,144,223,82,37,37,
215,10,203,129,195,50,152,186,162,246,227,92,67,29,78,20,148,67,149,84,20,68,149,69,74,234,190,21,152,207,161,195,43,181,167,44,58,38,14,36,142,123,77,207,2,138,194,167,89,84,71,224,124,2,1,146,52,16,
101,176,28,69,100,196,2,171,215,54,25,17,172,162,217,157,173,115,20,162,86,229,80,40,161,51,23,73,148,90,153,219,20,58,141,250,196,81,161,115,234,174,180,138,83,109,227,183,190,245,173,91,194,230,36,208,
102,6,61,81,72,131,194,160,51,8,7,21,246,106,165,158,179,140,143,103,170,153,140,144,125,246,73,130,216,199,189,43,202,82,135,54,0,63,253,28,63,210,114,82,158,61,26,141,31,66,12,103,36,66,38,200,201,33,
34,247,25,159,117,246,214,141,204,142,43,206,29,36,58,33,145,148,99,94,76,118,20,52,186,205,12,138,123,229,216,37,190,244,8,67,174,73,240,238,61,41,89,36,187,71,68,36,201,34,168,168,62,78,116,159,253,
157,32,2,170,47,93,23,18,213,142,149,179,23,122,61,233,123,231,188,176,234,154,227,236,234,93,211,251,12,53,81,101,167,174,75,21,7,144,10,50,52,178,113,162,229,142,80,8,199,75,147,142,11,90,30,229,134,
164,144,137,229,53,81,253,178,72,147,174,235,4,65,115,250,66,146,156,222,246,182,183,109,71,104,234,149,72,213,137,246,168,166,42,77,107,113,211,94,136,191,160,251,27,103,1,86,81,183,163,79,236,62,87,
213,165,170,223,91,73,55,153,129,94,208,251,168,156,221,25,247,175,160,26,163,17,246,8,210,80,77,239,161,243,108,159,101,29,69,200,78,26,170,178,47,29,227,202,186,235,60,215,93,123,246,221,7,51,250,101,
245,182,183,189,13,199,182,51,160,1,229,131,87,81,109,57,20,212,50,114,216,125,28,240,17,133,54,92,2,17,213,179,29,41,103,85,143,245,16,237,165,218,82,181,133,34,112,100,139,216,44,40,48,219,252,141,206,
251,17,243,227,89,125,236,146,84,102,143,35,103,12,84,251,83,9,68,140,24,94,103,227,217,153,175,36,184,162,42,70,35,243,198,213,64,143,238,183,252,108,156,65,76,220,58,232,224,136,118,246,206,162,159,
117,44,81,234,161,242,87,138,18,78,22,122,98,38,75,163,97,71,157,197,33,156,84,22,164,140,12,67,117,126,41,19,149,44,254,84,215,52,66,37,200,184,136,218,142,164,93,101,227,32,131,194,178,49,169,216,145,
116,62,68,109,66,82,73,136,249,112,150,194,166,230,144,58,183,87,115,205,73,251,162,8,91,54,38,50,212,139,206,251,76,97,40,154,223,85,213,42,186,62,100,47,199,202,209,141,74,35,116,85,176,162,119,10,93,
47,213,56,189,225,89,23,46,92,40,109,197,42,106,53,179,33,35,55,12,119,225,232,147,2,185,168,201,120,220,144,210,113,63,231,86,251,156,68,77,218,67,215,223,137,22,70,35,244,106,244,236,246,153,35,87,71,
54,173,135,24,71,179,72,63,149,246,219,71,58,209,8,130,210,187,110,237,42,156,244,190,143,62,187,234,32,196,164,153,152,111,47,255,30,169,230,244,118,29,61,85,27,90,39,135,142,159,237,122,168,97,243,178,
126,14,33,169,74,226,113,104,234,78,74,79,86,94,199,124,60,234,15,215,76,220,53,38,118,140,136,163,185,227,40,73,57,117,137,250,133,212,159,214,131,212,133,166,39,208,58,102,191,237,165,55,100,169,39,
81,153,148,192,72,207,241,37,106,251,44,242,87,235,152,74,193,81,237,22,205,159,200,4,154,244,81,134,216,80,227,106,39,157,136,6,47,78,170,153,18,14,161,196,182,232,57,219,237,246,229,8,148,154,36,171,
168,162,106,248,74,162,207,44,10,163,169,25,174,174,106,245,186,81,51,232,74,132,231,154,104,87,44,191,156,223,81,40,122,214,193,62,133,126,247,221,39,81,61,102,205,155,25,134,235,51,144,131,17,114,201,
12,163,247,234,243,246,145,178,53,186,214,156,162,61,55,239,103,77,118,138,21,58,184,138,108,104,122,10,165,52,147,132,99,26,57,93,11,207,119,162,85,87,220,193,221,101,71,109,227,246,11,45,15,141,152,
92,237,204,30,42,16,213,47,139,166,73,100,76,163,218,138,103,34,21,218,168,160,1,78,234,210,242,154,94,10,209,136,86,41,65,28,200,174,220,237,143,72,11,154,172,7,14,154,147,245,39,61,43,85,253,31,233,
135,103,186,226,142,32,3,105,167,37,218,151,33,123,35,107,20,65,155,20,130,72,81,10,167,173,220,244,169,202,189,123,237,178,33,86,62,74,51,49,194,239,35,76,154,238,66,41,137,66,237,248,137,13,25,45,151,
147,14,67,72,73,189,246,206,244,89,149,106,70,212,39,148,113,185,124,166,242,21,236,65,57,206,185,45,141,64,137,102,101,239,247,164,141,212,88,166,11,171,210,82,86,154,181,21,114,88,166,35,74,73,82,234,
217,116,35,147,49,236,73,191,210,107,220,243,46,162,189,218,187,143,139,160,16,18,85,197,0,154,162,131,217,122,75,244,95,43,134,231,78,46,52,177,191,235,245,117,100,40,79,131,179,108,172,169,54,146,100,
198,183,191,253,237,183,36,91,225,86,131,52,246,173,63,235,150,101,54,137,97,6,137,96,95,41,68,135,72,77,58,180,102,235,190,158,163,200,46,21,146,206,76,125,99,135,140,227,164,100,84,251,47,155,211,21,
141,101,247,126,78,22,1,241,49,174,182,171,211,63,202,167,151,62,207,37,112,245,238,179,38,225,122,22,26,19,232,134,134,245,142,246,171,130,203,40,132,70,224,104,151,44,67,225,212,42,100,227,104,23,187,
154,176,142,98,139,130,235,20,137,65,77,250,108,146,17,194,0,37,24,81,104,56,219,37,171,177,168,116,88,41,124,166,126,175,224,120,135,76,21,69,108,217,177,66,214,7,75,165,25,133,38,56,112,95,20,153,43,
130,9,153,71,203,122,244,8,49,81,189,178,185,155,169,250,168,181,76,253,182,55,215,137,3,82,70,104,34,240,176,107,195,71,163,70,74,116,34,235,42,33,14,17,215,150,214,90,91,189,227,29,239,152,146,198,226,
42,199,184,138,66,163,17,166,155,167,230,150,103,36,42,62,180,250,201,8,217,235,149,136,34,28,178,223,94,73,72,204,41,241,229,228,161,13,55,99,27,140,34,85,35,109,187,30,169,140,58,184,166,122,171,149,
67,238,81,211,238,222,46,68,165,136,56,228,158,104,167,231,70,216,206,2,67,207,3,162,122,46,211,103,220,104,186,170,67,25,221,171,162,235,234,142,153,172,92,145,201,124,133,216,69,162,81,7,241,200,218,
80,165,121,17,243,111,199,21,136,34,54,174,59,9,53,170,167,104,2,69,217,40,66,229,24,200,83,146,75,52,182,162,115,64,58,62,70,180,116,201,239,40,42,18,149,135,68,225,228,252,216,89,75,157,212,174,240,
154,119,190,243,157,219,202,238,144,70,56,74,122,41,75,130,166,26,184,217,32,32,56,249,172,232,130,166,180,208,72,215,77,35,113,163,107,39,58,168,234,240,102,81,60,77,189,169,232,226,146,241,27,181,85,
5,9,161,164,19,178,96,141,58,249,208,49,50,115,28,244,96,181,25,26,197,180,189,149,82,147,51,46,92,49,23,23,93,155,137,168,85,16,147,81,244,175,58,63,111,69,132,162,251,2,61,4,92,176,111,98,198,173,0,
121,236,171,14,35,58,198,14,65,228,80,154,197,51,137,29,51,199,109,85,139,120,22,9,99,249,66,171,92,63,11,30,27,33,120,236,235,217,189,23,109,244,61,49,23,223,151,117,88,149,64,232,106,15,19,99,110,69,
182,201,218,145,104,59,87,236,218,70,199,107,20,244,145,13,241,38,35,11,140,136,3,147,244,141,168,99,28,29,213,232,185,164,204,100,128,18,135,118,53,33,93,109,201,40,221,33,139,158,50,109,80,213,63,52,
90,207,210,47,136,150,108,22,9,146,151,75,212,102,187,240,22,209,102,142,162,11,186,81,136,254,238,164,54,237,126,31,141,255,168,189,72,100,212,35,211,100,247,114,219,45,138,58,178,178,40,136,179,226,
88,211,27,159,189,212,4,130,102,145,53,47,123,110,53,2,39,109,89,113,66,34,66,243,14,201,81,189,96,157,117,53,210,123,142,94,138,116,93,30,117,219,202,250,187,75,134,123,215,187,222,181,173,192,59,51,
236,109,102,107,221,238,11,26,56,52,148,48,203,158,202,129,148,110,22,98,209,233,231,244,115,171,32,65,199,141,150,205,124,174,131,154,16,100,128,190,44,9,74,64,54,198,36,101,166,119,221,117,108,18,71,
39,214,49,3,238,221,199,85,96,81,141,75,202,228,40,172,168,118,161,132,165,172,78,217,243,84,123,237,94,23,29,164,247,136,64,209,61,9,177,200,209,55,117,53,101,73,95,184,132,129,170,254,42,41,175,82,202,
113,201,101,14,217,98,180,236,116,78,103,99,39,187,110,134,150,48,153,195,180,238,174,65,118,85,13,75,245,25,137,240,72,63,71,117,161,227,139,170,186,17,115,122,186,230,238,254,123,41,214,162,198,208,
46,162,232,166,231,68,233,71,106,62,246,144,128,238,56,122,247,187,223,189,29,137,0,213,174,160,87,112,162,235,73,213,131,50,56,211,37,194,40,98,2,133,99,93,50,76,21,126,32,208,46,173,59,237,23,23,69,
160,48,180,131,124,80,136,151,194,199,148,124,82,129,232,40,57,76,65,92,251,64,2,246,69,254,112,17,12,135,144,88,25,131,35,232,77,180,238,28,23,58,51,51,173,238,144,159,138,158,241,161,72,87,67,145,247,
209,11,244,144,48,192,44,131,222,8,119,39,247,174,94,31,97,252,149,223,158,36,216,166,66,234,154,173,142,84,245,90,173,182,243,190,72,31,42,42,113,73,72,238,248,143,54,162,138,59,144,109,44,212,179,156,
113,68,188,121,213,184,162,196,177,108,3,78,251,52,219,76,85,148,150,42,109,94,153,119,14,137,72,109,222,28,174,5,53,114,207,130,173,236,61,81,85,97,138,198,11,221,44,247,94,194,27,119,114,100,111,116,
103,193,115,82,87,156,129,226,76,80,234,100,78,22,53,186,0,100,68,41,53,192,72,100,165,48,126,213,15,52,18,87,11,39,137,228,149,118,114,239,255,43,36,6,250,172,104,12,144,73,239,232,54,207,244,188,13,
201,13,69,221,103,199,60,91,245,71,164,233,156,229,52,102,237,68,13,186,179,205,129,155,230,180,44,119,182,134,244,76,175,149,166,248,146,0,231,166,134,145,186,144,241,237,64,216,89,31,82,72,188,55,47,
179,117,71,229,128,170,126,39,191,161,144,253,117,112,242,187,223,253,238,109,54,129,246,21,250,238,35,79,232,148,228,114,107,127,142,51,53,105,84,191,147,148,159,68,169,199,89,103,130,218,236,51,170,
31,213,86,86,17,137,147,118,68,34,100,135,185,95,73,193,154,129,38,85,208,37,119,156,86,72,67,179,210,184,104,191,87,81,128,181,178,230,169,232,116,102,15,85,182,76,170,208,61,181,28,242,123,199,64,152,
68,68,187,215,171,123,141,148,177,98,98,76,119,132,68,103,50,170,103,214,134,209,14,110,68,161,169,167,93,234,144,152,104,189,28,179,239,108,103,174,198,64,54,175,148,209,51,41,191,234,115,213,86,142,
65,115,79,67,53,235,199,202,120,201,180,149,169,42,84,100,146,221,141,44,18,53,32,21,141,18,231,28,10,101,102,4,32,133,54,244,234,222,35,227,68,247,142,158,223,35,245,56,70,216,89,189,28,29,107,213,38,
42,13,71,153,121,43,242,217,118,187,109,171,247,188,231,61,91,10,209,100,80,225,12,115,92,231,160,158,194,153,51,76,149,179,179,1,245,251,234,65,248,72,62,147,211,230,51,208,129,17,213,25,7,154,114,137,
53,46,241,103,212,28,189,218,31,78,157,142,11,5,154,133,246,140,230,71,158,20,244,107,102,25,94,105,200,217,161,4,98,170,232,133,243,89,171,72,136,164,10,56,186,180,42,130,172,154,228,82,173,82,133,241,
87,119,69,52,210,160,230,208,61,243,105,162,111,219,107,7,98,12,78,35,225,222,247,84,111,181,215,54,209,24,160,207,81,125,186,123,127,101,226,188,94,175,67,4,198,137,236,85,68,69,145,19,87,115,148,180,
189,139,88,16,164,198,49,87,166,154,168,189,52,172,10,210,66,215,45,55,45,202,53,109,39,41,97,100,221,114,141,161,43,174,89,213,113,237,248,113,142,166,90,17,132,144,112,96,42,239,177,221,207,38,218,161,
59,90,160,217,100,80,225,177,235,230,210,139,96,50,232,40,251,13,133,225,178,244,24,21,53,47,219,129,202,97,185,101,143,212,80,178,51,28,26,217,170,137,180,36,66,244,250,131,158,131,100,207,32,253,177,
108,43,247,76,75,213,145,168,217,184,80,44,25,243,132,136,148,205,49,21,65,42,35,229,158,121,55,41,51,209,157,86,253,160,230,122,166,210,163,214,162,172,239,149,233,50,233,183,108,93,34,74,59,206,58,155,
17,238,156,49,165,132,219,157,177,167,72,92,149,119,139,99,236,78,142,94,178,113,45,9,90,239,125,239,123,111,58,193,216,125,164,193,28,10,102,56,41,112,201,33,136,32,51,117,78,41,84,83,253,219,113,235,
63,31,247,156,153,13,119,85,53,116,43,233,71,84,146,211,33,234,184,41,90,35,74,60,78,78,51,65,11,70,203,92,73,207,81,50,136,149,245,133,164,177,204,30,171,132,121,191,59,214,54,100,231,227,48,155,156,
188,41,199,113,194,233,80,117,198,64,189,65,213,61,213,78,113,214,139,165,162,135,219,163,222,171,201,156,221,87,69,182,209,142,187,119,127,7,213,200,118,133,81,29,35,125,77,18,145,144,58,17,177,143,44,
13,74,77,202,104,206,184,99,45,75,223,161,70,230,142,75,141,210,107,117,180,78,29,17,120,18,209,58,136,134,122,49,185,78,38,202,44,92,205,201,12,149,114,209,191,12,233,82,185,149,116,157,36,72,162,115,
158,190,156,207,106,222,146,156,213,44,213,77,33,46,215,253,247,123,223,251,222,45,25,68,164,162,217,130,88,205,111,219,135,90,138,163,132,65,112,240,17,120,108,86,157,156,242,56,191,127,165,17,28,102,
16,210,14,173,240,115,250,57,57,200,206,204,123,84,34,202,12,186,62,201,237,113,28,196,162,25,101,92,47,15,234,51,162,133,163,7,187,120,72,104,246,171,238,227,144,131,178,50,86,136,33,138,72,68,53,59,
221,244,152,222,119,84,23,148,24,133,43,34,130,123,198,64,9,67,206,34,64,250,137,182,139,210,105,205,72,77,89,187,70,229,62,26,239,145,185,124,84,79,154,186,146,238,136,65,154,138,74,241,161,215,86,136,
115,180,95,156,185,235,234,226,146,185,170,136,82,100,67,228,204,123,21,72,184,235,96,239,247,142,206,50,50,147,6,229,82,169,98,89,196,77,158,79,218,48,91,215,28,109,226,174,18,145,34,15,208,80,60,59,
80,166,68,2,21,9,18,18,3,85,172,32,106,44,68,173,131,30,158,103,176,9,181,250,202,32,65,5,151,145,201,67,164,181,8,84,226,170,162,184,27,53,5,235,71,185,97,244,158,42,87,143,192,162,116,130,102,240,88,
36,154,77,198,48,129,219,171,227,151,140,93,66,108,113,94,44,21,226,136,219,22,206,81,130,179,25,167,236,84,165,98,229,42,235,144,62,116,160,83,55,227,34,83,158,82,253,236,10,240,211,188,106,250,194,166,
155,215,53,161,255,187,11,163,19,57,146,151,119,111,71,31,69,88,110,114,189,27,193,184,209,147,27,49,171,29,158,211,214,238,115,123,105,34,189,212,142,229,61,104,122,137,138,132,93,4,97,119,92,84,83,154,
20,26,146,69,111,81,125,156,73,238,140,25,229,182,225,68,206,110,234,140,59,174,85,52,236,162,65,206,75,138,164,163,100,233,83,228,62,149,121,74,231,56,237,79,42,6,163,198,131,147,170,68,4,55,150,235,
73,132,106,86,16,205,234,6,64,141,151,202,179,86,171,213,203,134,218,145,102,42,17,61,206,40,232,142,33,46,217,73,69,17,146,67,106,33,209,92,22,121,40,121,51,101,244,74,61,58,137,41,53,57,20,207,218,143,
156,177,100,102,193,68,19,149,158,253,185,212,126,69,72,25,209,6,141,108,148,178,231,40,3,228,44,154,207,250,52,26,195,174,225,116,22,145,168,244,53,199,128,154,146,166,178,200,203,41,75,166,5,172,8,61,
14,145,108,228,40,131,144,113,212,154,72,210,46,156,212,192,108,60,59,122,221,217,56,34,107,50,125,137,58,41,51,36,221,137,68,219,8,149,121,255,251,223,191,117,39,165,3,63,238,91,173,228,144,159,170,205,
215,205,88,247,83,210,203,201,252,236,59,197,104,230,61,92,199,163,125,213,99,102,10,75,181,252,251,114,46,26,185,158,28,219,56,71,14,174,67,202,62,199,247,62,230,92,111,211,177,30,129,92,28,248,177,10,
101,57,161,191,171,110,65,20,56,8,252,145,41,205,184,208,79,15,174,118,225,241,17,135,4,5,217,184,240,123,175,189,171,47,230,81,231,135,8,146,117,96,164,236,247,132,64,163,198,14,53,185,118,12,232,123,
207,113,207,3,123,247,203,52,87,35,39,28,23,130,86,48,186,3,49,210,122,170,116,21,85,174,12,26,84,164,37,170,17,155,33,46,35,176,164,43,124,65,82,206,212,59,160,162,192,164,218,143,64,235,148,92,152,5,
144,27,71,115,150,64,76,148,208,19,117,124,149,144,162,236,103,104,148,88,249,155,130,78,29,104,146,236,16,213,192,39,57,110,170,77,34,197,16,151,164,21,141,45,199,204,88,221,155,66,124,164,174,116,252,
40,104,153,190,68,213,92,112,219,194,121,94,101,131,162,118,231,78,25,213,250,64,199,90,70,82,169,108,208,43,109,18,17,109,102,183,181,83,159,10,49,135,66,217,4,66,118,198,251,236,241,233,202,15,86,161,
122,172,133,219,139,146,174,221,36,208,246,172,146,12,72,68,236,164,219,80,173,214,74,170,5,25,184,180,45,200,46,43,122,198,17,217,39,138,96,73,26,130,34,142,17,226,12,77,169,161,68,174,229,71,185,248,
168,116,145,140,248,20,145,161,150,101,238,105,12,147,178,19,237,90,114,61,93,56,73,59,143,66,91,116,190,19,151,27,154,226,69,34,53,183,124,149,57,78,82,220,28,180,33,91,191,104,244,174,198,150,227,158,
226,16,44,233,90,227,56,125,17,20,200,237,7,117,29,77,155,185,78,137,72,201,76,169,232,40,59,188,205,146,88,29,243,109,138,77,43,81,97,26,153,186,250,183,138,148,148,181,133,115,112,157,61,47,138,22,51,
85,155,140,124,212,131,116,136,194,76,22,141,145,137,227,24,11,71,117,200,34,241,236,124,42,130,109,92,34,20,49,122,38,227,32,59,139,203,198,54,85,254,161,168,4,245,79,164,138,62,21,43,68,170,129,27,145,
144,148,161,59,73,119,80,215,168,53,148,108,122,8,138,50,146,210,146,205,117,98,151,230,166,127,68,191,35,235,117,164,22,180,108,95,39,202,86,176,178,19,205,174,62,240,129,15,156,152,19,219,155,153,184,
114,210,181,115,111,54,109,223,67,88,17,157,180,254,216,151,174,243,113,143,175,106,93,179,69,126,6,1,42,218,4,84,235,92,33,77,205,238,115,71,194,238,36,104,136,87,100,33,73,31,56,253,229,174,59,187,101,
217,80,119,117,183,98,213,1,168,118,183,52,154,115,26,133,176,203,148,38,172,210,89,165,66,217,106,55,166,162,116,21,105,41,93,219,44,10,37,98,19,84,15,148,70,244,106,87,171,34,36,170,53,235,180,111,22,
101,208,180,39,87,251,86,165,116,80,87,29,178,211,87,105,11,189,178,83,65,144,170,56,3,225,2,16,237,215,101,121,73,148,66,116,106,221,163,168,104,190,17,84,76,181,73,212,110,189,244,68,53,238,72,148,74,
219,129,246,105,20,209,147,247,145,131,134,145,117,74,245,205,234,177,199,30,219,170,138,205,138,12,29,195,226,138,121,245,72,148,75,245,106,21,76,149,221,179,146,218,51,146,3,232,180,13,201,75,157,173,
145,60,210,231,251,106,139,147,144,130,52,98,80,190,207,114,30,18,33,114,73,111,167,159,155,3,233,218,7,130,66,144,128,125,125,66,18,17,77,101,232,226,194,9,1,196,33,224,16,229,154,236,249,14,251,74,153,
45,103,247,142,238,219,35,184,100,170,61,217,243,118,239,29,17,105,40,49,136,246,89,70,13,87,196,29,98,178,188,252,94,25,127,187,4,28,242,251,229,223,43,234,57,196,148,215,33,91,101,26,209,225,68,6,227,
138,164,129,100,215,71,4,176,104,92,16,29,85,154,138,18,141,109,199,108,92,165,219,144,118,83,125,235,16,169,178,177,164,234,78,198,63,209,210,30,237,55,133,112,85,214,98,87,47,92,137,107,40,82,29,81,
174,138,158,189,161,17,33,93,156,212,223,137,157,147,195,42,203,194,254,168,3,156,72,152,236,144,151,249,78,20,86,203,96,44,117,70,144,193,159,25,201,70,169,19,85,250,157,168,195,244,76,183,213,174,148,
64,59,89,223,56,58,207,4,126,87,4,39,154,146,149,105,34,103,42,96,170,174,25,106,228,104,249,210,197,44,130,4,105,250,21,33,189,69,207,37,234,71,89,155,43,114,144,122,137,58,106,53,213,23,51,153,15,244,
188,142,64,170,81,159,70,48,174,251,18,205,234,78,203,233,108,140,105,189,157,246,89,246,241,102,189,94,227,51,138,17,26,120,111,97,81,184,123,246,50,168,190,192,221,13,64,6,19,168,178,205,206,141,139,
34,103,231,92,53,218,137,58,130,249,36,114,165,17,99,52,30,212,194,86,137,24,168,191,228,200,28,200,22,125,119,28,102,115,130,108,24,85,159,80,54,185,83,215,221,241,72,198,116,111,174,47,215,36,138,68,
56,36,145,104,221,115,140,216,123,47,244,221,251,170,241,235,176,132,179,249,23,201,19,102,27,23,210,167,61,100,41,123,169,46,127,215,177,254,178,8,63,52,8,161,54,110,142,184,71,86,174,221,186,111,178,
6,206,52,41,201,195,162,137,175,38,114,22,205,169,23,108,180,219,86,132,21,122,239,222,238,95,69,0,153,107,8,57,184,143,250,68,45,158,148,228,229,18,156,220,67,254,108,192,171,13,148,26,75,84,94,140,216,
70,145,136,58,234,79,18,253,146,180,43,71,14,45,43,135,171,47,155,69,79,106,12,209,180,162,108,161,34,41,35,209,239,212,194,171,8,107,106,221,82,243,87,109,78,162,190,118,162,48,18,228,100,99,199,73,97,
202,234,166,214,175,136,160,165,34,185,12,101,162,250,225,180,253,156,0,80,166,35,125,240,131,31,220,18,201,170,42,212,89,129,68,43,16,234,73,34,24,184,100,149,125,154,135,31,247,103,68,19,249,244,115,
216,207,76,210,197,113,166,219,140,166,82,208,252,225,67,181,221,72,106,134,155,2,147,109,122,71,218,192,221,160,171,223,237,211,40,219,185,215,154,28,160,82,56,110,6,190,76,33,52,170,206,49,91,205,133,
64,99,238,121,98,164,116,147,149,217,81,36,113,108,141,28,83,109,162,114,163,172,208,104,59,81,69,29,87,149,134,234,102,186,231,53,110,251,85,206,117,122,245,34,209,97,212,199,89,196,49,114,142,79,230,
59,49,67,166,82,116,217,81,75,54,62,162,243,237,37,68,26,65,199,149,243,228,74,164,182,212,105,205,32,236,168,29,149,91,12,25,59,61,205,99,50,79,179,255,143,220,98,122,245,166,122,230,106,126,81,72,187,
247,183,141,130,169,156,65,161,114,138,200,89,78,20,117,141,104,177,18,197,145,8,134,200,224,83,98,144,157,65,73,110,190,85,166,196,81,217,41,70,3,149,64,179,4,70,25,25,59,228,44,145,58,200,87,156,56,
178,151,40,81,157,162,155,48,162,71,76,9,42,149,92,60,66,212,33,250,197,206,166,40,35,105,57,209,130,59,214,122,80,245,62,12,45,200,152,160,70,231,234,120,104,212,244,156,194,240,206,38,215,81,89,170,
6,104,149,249,228,108,82,105,63,174,93,58,53,221,85,87,52,65,119,35,50,55,101,69,53,170,19,57,103,244,248,108,231,152,165,103,168,29,33,169,91,166,251,232,154,130,19,141,90,186,144,244,218,203,89,88,221,
148,130,25,226,214,81,202,12,145,152,219,109,171,81,237,231,94,185,162,54,36,169,86,85,84,70,165,246,84,221,62,72,228,173,82,173,150,101,200,210,124,72,138,141,179,48,147,104,140,222,35,171,155,27,173,
59,46,35,78,153,221,53,220,213,26,174,152,194,147,177,68,77,205,93,228,78,233,238,110,122,59,27,66,132,160,106,62,142,206,45,161,228,43,117,151,222,243,169,186,81,20,173,146,73,74,84,138,92,21,158,158,
138,8,89,0,28,154,127,180,27,30,17,86,32,253,91,85,46,33,204,92,114,54,94,101,153,86,22,73,250,119,53,127,136,182,45,45,19,37,236,144,104,71,169,243,16,253,88,21,57,146,141,160,74,233,162,242,125,174,
118,172,82,136,170,204,149,12,149,113,180,104,35,162,152,27,117,245,218,89,149,137,34,16,10,193,34,227,220,121,103,16,200,157,32,67,173,181,182,250,240,135,63,188,117,96,220,202,231,102,36,249,156,126,
14,243,169,232,124,238,251,57,199,93,79,247,94,183,10,249,231,16,101,169,168,214,84,137,47,4,122,30,37,252,68,155,224,89,237,155,213,101,182,73,184,19,20,144,13,80,101,12,184,27,237,141,10,103,103,189,
241,123,80,149,74,159,160,84,124,87,16,58,210,220,85,145,138,18,98,80,187,105,101,66,75,152,128,213,232,138,164,244,208,92,69,210,23,116,209,160,11,145,74,91,81,231,199,110,106,83,134,138,56,41,84,61,
196,134,68,240,68,64,157,252,205,21,89,80,209,152,90,180,233,60,162,235,7,29,127,20,177,136,234,174,198,148,19,217,80,55,26,87,111,122,31,47,34,39,149,101,214,154,227,104,254,46,133,29,20,10,72,210,182,
20,154,154,69,227,55,144,154,62,242,145,143,108,221,136,209,213,141,37,191,25,213,242,156,25,229,30,34,85,231,184,162,96,87,211,150,26,84,143,60,131,180,209,204,241,51,251,247,35,250,202,179,209,154,217,
243,44,123,169,204,68,169,110,22,244,234,20,17,59,153,200,195,136,227,207,72,89,214,203,168,44,34,43,84,204,161,149,206,160,138,116,40,124,177,251,55,215,172,214,189,63,105,11,74,183,119,77,92,103,124,
168,225,116,239,249,149,20,29,74,190,58,250,255,37,65,135,182,11,213,177,205,198,106,229,251,172,111,156,49,72,73,41,74,183,180,151,18,181,123,109,175,125,201,179,34,29,230,37,25,203,233,167,170,4,91,
133,169,73,8,53,51,231,161,34,8,102,109,83,237,27,186,222,100,107,181,115,127,50,255,162,185,76,210,97,220,20,65,226,192,66,198,94,79,94,50,34,31,109,20,84,229,90,111,69,208,149,67,84,234,237,126,51,236,
221,77,47,113,203,210,219,37,102,169,13,170,28,170,35,169,66,138,130,89,21,2,64,68,154,85,164,65,97,166,12,14,87,106,31,132,52,20,89,132,41,235,41,66,38,83,144,52,137,196,92,77,210,202,38,37,91,120,156,
23,16,105,119,2,141,245,254,77,198,63,141,216,92,253,223,232,232,134,166,192,84,225,212,44,37,197,25,51,100,77,115,199,22,37,211,204,144,186,84,58,232,78,90,9,25,155,234,59,66,58,148,99,227,241,199,31,
191,181,156,138,39,135,240,251,188,223,200,61,103,26,0,223,10,125,115,200,114,71,47,216,67,212,249,144,170,56,179,72,34,180,204,206,179,92,203,170,125,65,124,209,38,95,213,171,170,125,91,201,126,112,203,
159,109,36,9,51,159,212,149,108,82,103,140,93,85,7,197,113,81,129,229,70,13,230,42,107,141,238,30,43,97,56,137,182,178,103,41,82,8,57,247,35,233,43,244,16,158,180,189,67,62,114,76,150,137,140,153,186,
23,21,132,238,69,139,132,205,71,196,55,178,137,156,185,209,144,136,212,49,53,119,140,217,179,8,39,170,11,105,47,135,36,165,230,166,99,80,156,69,135,217,156,139,144,170,236,223,78,100,147,141,107,250,66,
163,4,172,168,13,21,74,165,214,63,229,38,83,65,133,162,241,168,136,70,106,108,145,52,165,76,95,186,82,118,133,60,85,76,41,34,141,232,235,254,251,241,199,31,223,58,4,8,37,146,78,224,79,87,172,62,43,79,
229,51,227,94,174,229,148,11,83,185,247,202,72,30,251,36,223,156,148,254,56,41,245,57,37,132,188,50,209,169,87,82,59,236,51,154,31,65,41,170,25,25,132,41,30,69,203,107,247,92,172,71,74,160,218,164,71,
159,165,114,13,81,22,33,154,145,84,53,163,66,48,82,198,189,174,118,173,115,111,117,175,158,74,75,212,126,10,227,167,196,3,245,183,10,185,202,85,188,153,109,210,59,170,36,68,201,115,84,49,197,49,109,119,
203,238,74,213,101,253,65,21,110,84,123,145,126,36,253,231,26,96,43,181,25,183,92,180,255,9,129,71,61,195,41,91,182,33,31,129,72,179,54,34,107,78,54,142,92,2,106,164,17,172,94,198,89,138,76,166,241,187,
113,38,16,177,16,114,60,215,136,181,78,6,135,246,66,109,7,166,34,116,124,10,107,57,16,68,5,102,37,17,41,129,57,157,23,5,129,205,84,57,137,14,102,133,200,224,252,78,141,91,101,183,85,121,201,186,19,152,
110,68,28,148,167,66,182,83,103,69,138,148,85,97,205,246,152,142,153,213,155,210,236,205,214,13,138,174,101,249,132,244,8,197,217,112,58,125,173,94,90,244,247,163,41,66,179,216,211,149,182,168,254,219,
153,207,164,63,214,78,195,40,198,154,67,113,118,10,30,185,149,236,70,191,42,186,36,59,126,119,183,234,180,141,179,160,84,118,226,42,98,35,237,161,118,144,14,67,205,217,85,187,78,54,203,113,65,162,66,103,
1,82,166,194,180,108,46,253,191,146,42,214,123,222,50,21,205,137,110,157,200,203,77,43,136,230,78,175,141,163,84,58,186,198,40,19,250,46,28,39,82,188,142,126,75,174,163,243,197,73,247,115,210,165,162,
116,48,82,30,247,101,71,223,29,14,2,226,110,250,73,116,78,244,160,123,229,138,82,195,174,75,99,81,24,179,67,243,87,170,54,234,0,153,192,11,74,127,210,137,240,162,72,137,24,241,18,229,28,178,219,83,229,
119,206,54,21,17,129,148,69,245,237,12,1,105,133,54,168,182,86,81,6,25,51,25,76,67,35,91,23,85,113,210,187,212,248,140,158,233,232,47,59,206,52,213,93,60,209,195,165,115,150,68,81,164,205,34,199,153,12,
165,138,244,111,123,227,137,206,151,229,117,170,159,162,185,75,52,137,179,126,119,2,34,202,127,33,104,142,50,232,206,144,136,108,173,84,105,42,234,239,106,131,177,221,110,219,234,99,31,251,88,9,4,63,46,
114,10,157,48,213,178,187,114,80,251,172,235,104,31,28,231,231,148,76,115,115,125,70,73,32,35,90,178,179,202,117,92,41,70,14,169,198,41,99,229,30,51,180,165,43,86,128,213,20,26,90,70,194,94,87,27,254,
170,41,121,118,205,166,50,240,136,42,254,81,216,155,165,192,144,232,174,247,27,39,34,200,118,83,189,134,61,210,232,61,250,255,108,247,177,12,241,51,138,55,29,196,52,154,218,133,28,136,182,102,37,255,83,
165,153,168,65,89,21,230,112,82,123,50,84,65,237,220,213,239,232,134,173,34,70,78,52,143,73,250,140,163,33,29,109,110,170,142,73,153,62,169,26,139,20,129,82,209,6,89,240,72,251,145,231,100,8,143,66,196,
156,181,84,69,230,209,89,109,86,15,18,44,244,82,166,200,184,138,180,158,213,156,83,125,66,210,97,28,17,151,42,138,18,205,241,213,106,117,35,137,136,70,149,10,154,81,176,140,82,59,201,242,139,162,133,39,
91,48,122,164,142,10,19,81,65,180,68,253,38,106,75,245,178,167,112,153,130,220,104,185,156,151,171,115,173,51,65,72,123,101,237,224,188,64,148,189,146,130,156,71,12,128,21,220,167,230,24,49,137,39,182,
100,170,253,73,110,93,6,43,59,132,52,247,204,61,171,103,182,232,142,44,172,10,242,139,238,225,206,99,165,36,86,25,151,149,115,73,215,56,156,206,211,17,150,124,213,48,188,26,36,238,126,174,59,13,87,26,
184,234,251,172,224,84,171,52,210,69,93,126,159,25,34,71,207,168,16,107,84,89,233,65,116,175,156,174,254,47,77,107,113,6,18,185,255,242,251,138,65,113,68,188,80,70,222,189,54,29,77,197,161,26,196,52,45,
35,211,85,205,198,120,239,247,116,83,181,76,31,83,227,112,84,74,144,26,149,103,99,43,75,87,83,235,144,106,55,119,44,68,247,234,145,191,162,190,118,117,183,29,115,231,106,90,88,207,124,92,149,151,204,23,
154,106,54,74,132,162,169,82,234,124,114,100,93,164,198,228,173,237,24,106,71,52,240,158,162,134,138,20,179,16,221,21,97,136,162,25,199,222,140,146,111,168,157,88,166,178,162,160,42,165,59,75,85,139,28,
117,30,5,63,42,152,141,164,47,145,200,50,170,43,177,126,115,29,97,92,9,53,133,36,16,85,33,39,157,129,238,254,9,170,144,245,83,54,78,40,49,144,162,0,21,195,116,66,136,34,191,207,198,46,77,105,200,16,10,
18,37,59,118,97,89,123,41,205,238,108,78,146,151,110,102,170,157,245,125,101,115,224,104,255,170,249,144,145,131,20,98,82,121,137,102,232,234,181,251,63,241,196,19,211,229,35,78,9,36,135,255,156,116,221,
223,17,125,78,250,114,60,238,122,30,186,92,135,210,20,221,7,57,100,31,109,225,16,110,70,52,116,15,53,103,232,241,68,245,236,189,34,215,231,182,181,163,30,164,198,220,136,150,119,213,79,55,11,20,110,136,
64,73,20,81,49,172,118,117,99,213,225,118,182,67,114,23,30,218,73,170,60,89,35,211,72,150,70,70,213,69,206,25,224,89,68,77,202,79,119,166,52,114,37,81,130,138,112,162,62,115,250,210,17,203,166,145,124,
22,225,59,232,10,141,32,232,34,209,67,40,20,74,65,80,20,66,254,82,237,74,162,124,7,2,117,206,195,40,201,75,145,168,92,179,106,247,12,84,153,127,171,104,43,154,103,142,215,51,121,65,59,17,107,207,197,137,
174,17,100,157,205,158,211,157,127,79,60,241,196,150,64,142,251,54,44,118,22,78,103,240,159,196,200,120,134,18,145,163,27,236,166,237,236,187,79,103,152,36,83,145,126,23,250,157,49,230,14,153,194,53,235,
94,167,168,209,233,199,137,204,246,225,100,179,111,20,165,247,239,209,103,172,51,98,8,81,179,160,187,58,122,72,75,238,223,211,223,141,112,115,138,119,87,25,97,202,152,183,119,191,93,146,68,79,217,100,
89,87,117,15,213,7,74,31,55,170,51,61,180,207,238,73,141,132,123,202,57,25,89,97,183,93,150,196,143,168,28,132,164,209,123,102,164,247,236,232,197,102,253,68,21,154,220,113,233,252,45,211,33,173,156,215,
210,49,68,198,9,105,175,81,149,48,74,112,172,24,61,103,115,164,186,166,82,2,99,197,212,12,127,162,185,0,0,32,0,73,68,65,84,91,177,210,35,30,3,213,4,95,222,135,142,75,215,252,59,122,126,37,48,148,90,184,
81,154,129,115,200,234,64,52,21,166,150,138,220,148,90,80,100,11,69,160,202,170,177,44,89,108,40,185,128,182,83,6,223,16,200,130,164,92,244,198,0,73,187,80,103,56,202,102,42,43,51,133,145,92,195,245,108,
236,43,226,72,86,255,104,30,145,35,139,104,156,145,5,73,193,117,81,58,150,3,127,103,48,26,65,7,162,242,142,108,228,29,205,99,39,48,160,132,149,104,236,140,4,38,100,237,33,127,35,41,138,180,45,157,181,
156,166,94,85,225,122,234,252,69,45,249,150,101,223,84,26,193,21,147,158,113,14,65,58,134,52,232,174,64,130,58,107,169,184,27,148,96,128,69,153,170,59,213,108,129,220,157,176,61,145,8,167,93,163,221,152,
74,102,143,202,232,44,118,81,91,101,240,12,17,254,232,10,69,7,98,32,203,114,144,122,100,125,151,245,127,214,191,202,231,51,147,133,35,168,133,211,206,106,206,30,221,111,249,226,80,155,243,74,132,208,27,
139,106,35,72,54,103,203,246,200,22,96,18,133,238,206,69,71,57,39,234,39,215,238,75,189,36,119,203,22,221,215,233,171,140,217,154,161,6,203,118,114,2,178,44,16,82,140,124,114,38,188,33,114,72,100,135,
233,24,100,19,242,15,33,136,68,187,5,226,76,17,221,67,41,1,209,191,43,18,16,73,167,80,209,136,210,204,85,11,28,77,233,80,253,167,132,44,232,162,235,168,231,16,97,1,119,209,80,169,10,153,33,50,53,177,118,
210,123,156,232,200,217,144,68,125,76,200,80,21,67,114,117,77,70,230,35,145,184,74,107,139,202,149,45,228,89,52,158,173,39,148,160,226,8,197,100,232,18,221,4,247,218,89,145,54,179,8,155,24,86,59,168,12,
81,60,35,136,19,65,221,50,17,13,138,140,92,251,238,19,159,248,196,118,148,164,114,28,31,202,194,188,217,63,110,238,215,233,103,255,99,237,244,243,202,250,204,34,157,236,139,136,51,163,44,206,70,116,244,
57,135,110,47,42,31,90,73,151,90,71,111,242,165,210,143,50,192,86,135,191,203,251,168,191,41,40,207,37,60,56,59,181,12,10,203,254,238,24,46,171,114,247,218,166,106,158,156,149,161,2,171,87,100,177,14,
161,202,164,32,112,82,246,94,155,19,75,179,170,205,31,237,47,167,221,149,225,50,29,211,196,62,139,144,72,28,165,48,151,212,230,112,19,8,177,76,157,143,247,96,64,119,78,101,202,70,21,98,153,90,87,212,121,
55,65,35,162,51,75,101,138,222,123,142,234,115,85,102,178,78,210,181,151,172,113,217,88,219,184,150,47,74,133,135,132,228,209,160,140,58,48,83,74,114,22,44,10,167,17,152,141,46,158,84,5,166,183,19,162,
185,91,163,209,120,245,37,170,206,213,84,158,160,67,172,138,96,106,74,114,80,90,176,132,236,66,200,48,25,156,20,65,153,89,251,17,56,144,194,210,10,6,35,125,20,229,197,41,72,175,194,58,165,94,185,228,59,
71,128,220,221,176,100,191,37,86,89,149,250,211,181,208,217,196,208,245,155,168,65,185,155,109,151,29,95,169,163,251,114,36,155,178,13,237,128,222,33,46,173,164,98,156,85,104,235,213,133,158,252,38,35,
26,185,80,222,108,97,106,21,201,100,18,111,110,219,85,94,154,189,157,167,43,58,175,198,76,5,218,137,206,50,233,6,130,48,116,163,242,171,57,163,92,135,162,123,58,68,155,140,56,22,93,163,54,127,42,34,112,
28,78,92,120,173,215,214,100,14,102,164,32,181,9,82,107,68,182,94,80,33,150,168,125,168,3,84,22,49,103,47,195,108,115,229,6,81,209,122,228,16,146,178,231,81,119,31,117,6,90,17,71,233,146,136,212,162,66,
229,148,92,6,164,219,168,163,226,1,25,61,159,178,21,85,219,144,1,76,201,23,78,132,71,22,156,40,218,87,101,32,169,37,68,141,200,177,151,34,134,233,196,57,35,43,15,205,5,35,11,176,50,67,142,202,77,197,75,
92,2,84,5,126,167,226,20,35,155,48,101,108,77,114,3,179,113,73,230,135,251,226,33,4,37,71,229,43,219,12,58,235,14,61,206,33,47,2,85,38,218,206,170,174,4,57,137,156,127,150,247,39,132,212,10,172,174,250,
244,186,121,249,201,79,126,242,120,78,177,7,63,51,212,108,70,158,117,250,97,209,254,204,223,31,39,233,98,86,157,78,106,29,102,24,64,239,187,223,104,89,14,77,120,81,114,155,21,99,131,81,35,235,10,33,198,
141,138,163,151,149,35,141,58,58,166,14,53,191,162,251,110,42,166,199,35,3,59,27,104,52,106,201,32,41,170,31,154,193,2,36,21,131,24,252,206,154,8,170,205,42,194,21,89,212,73,158,167,206,181,179,93,125,
85,195,53,67,57,220,244,32,130,166,100,17,7,129,159,84,148,161,206,224,169,230,178,243,27,231,56,100,153,194,54,26,125,80,45,101,7,206,84,207,166,16,158,179,6,100,209,52,141,32,21,250,64,28,141,136,88,
75,230,48,229,160,25,68,48,164,130,220,185,233,91,25,79,198,93,71,20,196,173,208,137,237,118,251,114,4,234,228,228,237,67,51,149,12,202,202,179,170,19,66,181,193,204,8,117,150,22,173,147,67,89,21,108,
167,191,175,212,105,38,162,176,79,196,96,86,57,247,145,38,54,210,222,135,68,89,78,17,157,91,191,109,110,54,180,168,90,222,117,102,44,123,20,233,245,190,95,254,59,211,69,205,116,91,163,93,67,53,93,99,169,
223,171,76,124,51,195,112,98,246,92,121,201,59,105,44,106,87,168,250,129,164,14,101,164,146,94,191,43,45,202,44,205,73,221,175,194,164,139,218,130,238,172,29,131,109,215,176,59,250,62,107,219,200,184,
94,105,189,82,13,98,58,134,9,97,208,77,65,34,243,133,164,140,101,101,138,254,219,37,244,185,237,78,198,131,26,123,202,40,157,140,119,170,117,237,182,185,155,138,227,180,181,147,238,72,222,71,116,125,85,
154,186,202,224,123,67,40,201,142,226,131,179,107,207,32,74,106,225,68,141,174,233,129,191,74,167,161,209,185,146,231,34,68,36,5,183,56,82,100,106,183,229,66,157,106,215,150,193,102,206,51,156,163,3,69,
72,33,48,30,145,153,35,227,194,133,239,220,5,190,98,152,144,29,65,56,176,174,243,66,162,17,59,33,132,101,176,154,130,245,50,198,40,129,252,51,102,187,99,62,239,24,68,147,151,94,52,86,221,182,140,214,36,
149,202,149,69,205,21,91,59,103,227,67,181,213,35,69,49,58,166,178,119,33,78,99,33,17,99,53,122,82,141,69,239,85,77,112,175,230,145,102,250,161,36,225,91,157,21,245,238,235,70,13,174,206,106,22,105,168,
23,157,35,174,159,93,191,212,7,117,35,250,106,84,50,122,6,164,218,42,91,4,169,223,109,53,178,203,52,146,29,230,180,250,13,101,177,147,77,153,195,6,117,142,125,150,186,188,217,49,143,155,27,236,192,130,
164,252,51,210,147,220,113,157,141,101,242,210,238,205,19,37,21,152,109,74,201,102,33,187,110,23,209,33,108,121,178,113,187,246,2,173,104,206,86,220,189,73,68,169,204,183,169,121,47,33,88,56,137,235,42,
178,165,68,7,247,89,84,52,220,121,185,170,151,128,106,119,226,170,162,118,245,81,52,184,251,12,74,240,33,81,3,21,219,86,99,86,145,150,122,66,24,89,212,71,156,82,168,38,42,65,58,200,253,201,98,26,141,165,
222,191,201,139,53,90,84,41,145,205,17,144,32,209,27,93,87,162,191,245,202,175,132,79,42,4,47,154,222,147,173,57,163,193,147,227,222,148,109,206,162,251,210,212,72,154,146,66,163,122,186,25,93,253,210,
47,253,210,150,132,214,4,154,33,139,48,249,84,8,14,36,191,114,38,113,194,129,37,102,26,72,239,155,196,53,227,67,54,42,135,74,65,154,213,183,167,159,155,247,51,131,208,50,211,132,121,102,185,110,214,246,
60,68,185,14,145,206,180,174,156,173,236,134,229,35,7,235,68,107,115,25,130,71,101,234,153,127,47,255,77,140,165,41,68,234,66,146,21,248,181,7,67,40,141,203,222,61,137,49,122,85,250,74,61,207,129,244,
157,126,232,245,159,171,185,75,180,100,51,146,65,69,255,84,145,18,84,63,101,125,68,198,197,136,84,90,52,71,9,137,137,104,208,18,50,12,237,119,213,190,116,62,58,2,38,170,108,68,64,33,107,23,215,120,60,
91,123,157,35,23,74,174,115,198,102,213,12,220,153,119,74,44,194,81,213,11,165,252,220,168,134,96,199,68,193,35,59,216,173,156,247,80,159,185,8,130,162,29,66,32,29,39,55,140,182,49,201,25,203,96,113,74,
98,113,205,142,221,246,167,233,64,132,100,69,21,137,28,198,169,42,179,171,133,28,181,5,65,68,42,99,135,156,163,57,164,137,236,25,61,43,47,215,0,185,234,7,76,175,113,189,140,41,185,139,188,68,233,70,197,
213,56,118,95,162,4,78,85,99,121,116,14,145,32,196,37,240,84,120,51,206,220,38,71,13,235,74,244,81,25,204,132,150,77,210,45,178,93,154,187,171,36,209,36,73,11,161,81,39,130,4,130,72,179,71,14,90,62,175,
247,236,74,74,192,136,136,182,51,169,85,68,185,91,87,26,181,184,11,234,110,187,145,201,86,105,59,186,219,205,202,66,235,21,33,14,106,188,57,47,171,168,15,178,113,231,212,101,189,94,119,231,129,131,14,
85,33,120,234,228,67,219,77,69,206,116,157,116,220,139,178,181,81,173,93,35,105,74,42,90,84,243,139,34,117,238,139,185,18,117,71,237,178,92,119,55,138,80,64,213,67,104,116,65,213,85,104,218,134,163,163,
171,118,224,42,236,119,207,71,168,16,54,141,148,85,68,70,137,1,68,165,70,61,211,53,169,38,170,51,81,25,119,159,169,116,115,221,122,100,187,208,140,20,67,163,63,58,166,157,136,167,71,176,113,220,51,178,
231,81,138,127,134,28,56,228,156,30,129,134,176,52,157,178,147,49,65,53,112,105,251,186,17,144,66,132,50,51,247,108,141,205,94,152,138,228,53,98,255,72,94,112,209,119,149,53,152,40,125,17,228,172,183,
198,164,27,132,95,254,229,95,222,86,222,246,170,50,35,10,52,206,132,173,60,243,244,115,115,127,78,154,17,241,62,203,185,15,242,74,181,236,51,159,127,92,245,34,27,108,181,49,223,71,223,207,210,28,174,222,
195,117,131,57,238,121,72,234,78,250,149,164,203,100,253,187,86,240,152,11,197,70,80,64,4,63,140,152,208,58,144,203,168,122,208,232,142,139,252,183,130,124,72,219,186,103,5,4,174,36,80,80,197,208,56,27,
15,10,34,173,66,75,14,241,165,247,247,158,133,22,57,211,33,81,73,175,76,68,131,215,129,74,171,22,129,149,99,30,58,119,179,235,40,177,134,16,84,162,107,105,110,167,171,228,69,199,247,50,18,167,16,104,134,
118,16,85,178,222,117,170,45,28,178,20,125,159,140,152,131,103,245,167,117,193,209,102,207,80,91,65,114,10,74,33,176,22,85,226,81,58,180,212,95,49,219,233,102,247,119,181,111,9,108,232,40,198,208,92,166,
104,177,86,48,133,34,54,185,66,239,89,82,116,118,173,115,208,79,114,105,29,51,111,53,14,34,120,157,234,69,83,51,105,74,124,82,112,234,136,201,118,53,241,126,244,37,74,231,81,22,101,56,30,185,213,13,176,
3,199,142,192,184,116,67,235,192,234,51,55,67,149,243,236,17,143,103,103,172,209,114,86,250,152,172,83,107,103,39,75,118,5,106,199,27,17,98,168,114,207,104,244,154,237,38,40,249,98,89,239,229,193,178,
235,82,64,219,217,25,212,209,111,20,185,41,211,14,142,180,59,123,215,244,158,211,235,103,245,89,18,74,162,251,201,129,190,184,118,217,30,138,180,212,187,111,148,174,147,165,75,245,158,145,141,73,146,130,
69,163,159,106,4,89,69,56,84,244,212,155,55,142,6,182,179,30,145,40,196,89,203,40,113,209,73,157,114,214,137,221,121,70,52,175,71,208,52,74,164,164,107,174,90,79,71,55,48,68,155,154,32,81,164,76,155,40,
186,164,54,96,189,136,128,68,81,84,54,203,57,64,206,14,206,179,148,144,222,61,28,21,161,94,27,57,100,25,199,84,152,146,175,168,250,70,106,22,43,124,12,157,148,19,162,75,74,35,208,40,159,174,226,190,227,
68,183,68,225,74,169,171,144,239,42,34,29,85,67,246,172,95,149,180,27,69,92,220,8,89,157,147,86,153,202,217,186,19,165,69,57,105,31,209,217,106,246,18,237,145,192,104,164,153,33,37,89,170,96,54,46,42,
186,181,174,81,54,49,209,38,232,91,180,158,100,125,236,108,84,122,101,90,142,245,213,167,62,245,169,155,210,80,251,36,126,110,86,101,145,91,161,94,68,216,254,16,207,119,141,140,247,89,182,25,166,197,217,
6,77,61,203,205,235,38,76,117,199,159,150,244,211,104,127,141,142,59,231,154,125,154,71,147,108,6,117,173,219,103,217,6,133,26,50,184,237,57,171,79,142,62,67,134,218,100,183,166,38,5,25,132,209,238,201,
221,105,146,20,28,50,81,93,195,223,108,167,239,24,32,19,41,194,170,182,112,213,33,133,180,135,179,163,166,134,220,106,176,59,102,186,68,195,151,10,104,184,145,156,99,150,93,25,19,84,222,210,53,12,87,169,
109,74,83,216,65,98,8,167,64,69,184,106,190,185,232,5,49,236,166,40,3,213,183,94,62,215,69,37,50,191,99,71,84,157,244,7,169,159,203,57,200,198,184,210,222,206,16,42,106,92,222,45,255,175,252,202,175,108,
29,104,203,253,56,38,213,52,109,165,66,252,81,80,2,113,72,63,238,15,181,81,83,101,39,131,103,212,240,249,36,166,21,29,87,185,111,133,20,171,211,52,177,155,27,213,169,166,184,84,210,113,14,25,1,238,59,
173,76,5,125,235,222,174,216,33,31,56,100,150,8,55,87,59,31,162,111,75,211,44,8,157,186,71,78,25,101,31,58,7,211,209,255,71,100,37,66,98,137,72,22,61,245,152,200,240,153,170,44,85,148,161,220,52,164,94,
185,72,212,80,97,139,102,99,157,244,103,100,146,76,198,99,52,167,178,185,68,180,167,103,212,189,186,201,116,76,144,93,213,48,50,30,72,186,18,109,151,108,14,19,57,68,53,158,43,207,160,227,210,33,109,209,
180,149,172,94,206,220,166,243,129,4,12,74,214,212,9,54,150,191,219,208,193,209,11,145,85,129,8,76,169,6,88,100,109,164,148,113,178,133,39,251,141,34,223,84,180,50,9,100,16,41,224,100,208,2,129,174,122,
131,204,77,109,160,233,26,36,229,40,179,193,202,218,60,131,101,29,2,6,49,105,207,80,15,87,227,215,137,238,73,58,84,102,247,70,32,40,69,212,163,70,214,106,173,112,13,196,233,75,41,35,185,17,131,109,74,
74,114,8,39,202,227,210,65,126,200,218,85,81,154,114,245,162,233,59,65,109,230,40,17,141,164,227,85,231,91,244,18,117,84,183,162,121,191,86,209,135,187,59,34,209,151,27,221,46,211,31,28,55,18,181,131,
119,191,155,17,237,68,41,30,203,186,238,94,151,69,159,36,217,186,186,195,118,28,92,104,14,94,229,58,71,95,179,34,78,225,244,95,69,170,76,149,111,153,142,64,132,29,40,2,84,137,58,171,243,199,41,171,243,
210,80,206,70,89,36,223,91,63,28,52,204,205,215,237,61,55,123,182,163,193,77,68,18,92,4,172,130,78,144,244,186,170,3,78,246,204,76,131,152,184,64,81,81,6,149,230,120,244,217,144,29,142,218,73,69,59,183,
10,35,171,18,177,18,39,23,37,154,16,233,0,47,163,224,104,135,169,200,15,81,100,221,107,159,94,212,77,201,45,132,220,64,162,97,170,179,233,154,79,71,187,82,165,73,169,118,181,174,94,112,22,45,68,6,209,
234,92,68,93,23,213,35,67,31,8,201,72,69,76,89,138,84,37,42,162,58,182,142,193,122,175,172,81,27,18,8,47,66,201,34,71,37,103,141,35,58,224,189,241,171,162,52,234,138,227,164,68,169,136,81,33,116,21,65,
7,106,70,158,93,171,94,164,20,125,201,206,127,157,0,176,55,214,87,171,85,91,125,230,51,159,217,170,201,51,155,64,112,51,17,18,102,155,110,187,247,61,169,132,166,155,165,127,79,201,47,251,255,28,50,133,
200,205,16,152,125,223,232,218,67,107,36,171,13,206,161,159,79,211,131,72,246,133,51,158,220,76,143,217,250,212,107,7,214,116,33,28,10,97,57,112,146,218,117,84,161,229,168,110,174,225,43,173,143,34,4,
57,229,112,219,71,245,163,75,140,234,193,108,174,121,181,3,41,83,24,120,9,141,42,88,167,242,93,21,26,158,97,84,172,218,209,129,158,41,233,206,209,194,38,242,141,174,1,56,137,146,179,168,181,42,67,183,
172,147,51,111,50,125,99,98,207,72,198,134,138,150,41,228,170,214,11,58,6,118,251,189,170,59,157,205,167,170,237,34,53,67,207,230,212,110,27,111,34,37,21,5,237,70,57,59,89,126,82,4,235,58,47,30,10,5,17,
232,212,25,72,81,88,79,216,97,68,31,54,130,219,20,220,145,229,117,17,181,15,213,30,138,144,228,64,54,106,162,169,186,146,221,40,221,57,146,141,129,34,73,16,205,91,87,131,211,53,33,175,158,43,57,11,73,
84,78,186,233,137,230,142,115,246,69,215,8,165,252,163,142,171,42,207,206,180,148,157,123,87,216,162,85,169,83,5,185,210,117,103,212,0,222,229,87,140,180,171,115,150,77,249,53,235,104,151,82,61,108,206,
116,68,157,29,122,214,224,21,227,222,229,115,149,233,244,140,239,122,36,17,181,192,168,246,35,139,149,107,60,77,140,187,73,59,238,150,125,87,195,54,43,163,106,147,140,52,146,221,199,73,187,32,227,180,
162,123,234,188,0,43,198,209,78,59,70,8,72,181,236,145,182,48,25,175,35,230,219,78,164,151,213,57,50,32,175,44,224,244,69,50,18,73,69,122,225,85,20,170,119,63,162,147,93,33,233,57,253,58,170,35,158,141,
179,106,228,157,149,97,227,98,250,74,27,212,89,164,40,225,96,25,93,145,232,83,221,131,16,55,168,202,74,37,82,206,112,252,76,31,51,139,112,201,129,189,163,198,65,44,159,150,99,132,210,191,149,246,37,137,
134,137,134,112,86,15,170,24,19,149,53,211,45,238,245,167,219,30,89,89,35,237,221,74,206,34,33,100,84,54,114,14,26,227,68,152,81,255,211,104,59,27,251,74,169,135,70,89,174,129,188,171,66,229,56,55,245,
198,50,137,188,72,212,234,138,202,103,239,130,232,29,83,113,200,114,222,61,238,198,250,186,23,40,221,153,147,130,209,240,95,193,192,149,156,54,186,243,165,17,92,245,30,163,48,131,19,177,84,118,240,51,
172,153,102,64,94,35,48,228,8,244,50,234,236,48,18,213,142,76,214,163,157,244,238,66,179,94,175,173,227,1,7,122,37,48,248,8,132,92,141,48,142,234,76,207,98,201,75,71,229,123,211,141,104,182,57,80,98,3,
180,92,68,151,86,229,57,18,178,17,221,92,209,128,139,110,32,220,57,230,228,49,247,54,65,46,225,104,249,183,181,163,222,67,136,13,78,14,14,205,233,36,16,131,99,159,227,46,130,138,228,81,57,7,163,38,207,
20,2,119,77,172,157,243,42,106,1,69,238,239,140,33,117,86,229,144,98,156,133,222,33,78,56,164,32,245,226,207,230,197,50,10,82,253,155,189,56,102,204,243,8,62,166,249,218,213,92,189,136,156,66,198,84,68,
254,113,215,133,222,121,103,54,206,123,142,40,132,184,210,171,235,242,111,106,94,56,105,39,148,204,150,141,55,39,157,71,213,63,91,55,168,101,25,205,189,141,4,22,212,125,54,173,248,161,57,70,189,78,86,
74,52,132,224,80,141,252,92,243,235,10,9,134,234,244,42,115,234,232,37,66,173,202,28,129,100,215,54,202,69,39,178,69,205,97,250,82,8,93,221,63,66,71,212,115,179,190,113,25,165,85,225,114,103,193,175,144,
52,70,81,134,202,25,97,101,83,238,150,85,145,116,156,151,232,204,178,57,237,65,207,85,85,228,61,250,236,221,160,102,68,181,105,86,253,157,53,231,186,52,20,179,252,55,212,63,219,149,58,170,63,106,119,144,
25,87,47,15,241,35,194,141,170,16,61,48,166,58,183,217,53,42,42,166,169,39,21,101,156,140,216,17,125,191,251,93,164,115,75,210,90,34,120,145,236,18,179,246,119,21,158,50,205,95,186,72,69,227,145,32,16,
17,196,90,209,0,166,47,50,69,242,112,95,136,142,158,172,27,25,84,200,77,206,139,218,85,145,89,182,163,75,228,33,234,74,84,173,199,69,61,178,251,145,13,66,69,135,219,65,144,168,153,121,47,170,118,159,175,
68,39,200,218,149,101,79,208,186,95,51,212,166,250,172,196,188,185,23,33,17,133,159,12,174,115,45,105,136,6,107,20,29,147,136,133,40,241,68,109,208,123,174,178,230,138,72,12,164,191,162,50,40,3,104,245,
178,207,82,149,168,246,103,239,94,36,250,35,227,207,137,8,42,237,154,69,222,132,136,150,157,17,101,105,67,21,81,8,138,126,56,17,154,34,64,145,180,17,231,37,74,210,133,148,105,123,229,108,190,42,76,144,
141,69,250,18,237,41,40,169,115,90,138,220,141,188,68,21,225,138,188,232,40,10,148,245,171,131,144,81,31,81,133,242,244,126,179,161,81,6,197,175,171,131,180,2,39,57,73,204,10,54,232,133,242,36,26,85,81,
247,118,187,181,96,130,229,110,145,136,84,103,147,137,66,38,21,248,134,194,95,4,122,164,209,20,133,163,212,217,20,93,84,151,68,29,53,150,73,219,83,79,219,106,187,19,50,139,203,152,175,206,215,209,107,
51,241,120,210,151,42,159,58,107,187,229,24,112,214,158,222,184,113,148,119,118,127,63,114,222,233,100,20,168,114,86,16,22,114,159,221,53,178,87,86,151,184,166,94,152,42,31,153,250,57,183,214,250,103,
160,142,225,109,20,101,70,81,91,180,195,32,218,159,217,2,161,34,89,181,51,140,38,92,166,209,234,56,197,87,164,174,178,221,123,164,153,171,118,109,100,66,69,125,147,69,54,153,182,169,179,128,210,241,69,
52,136,137,228,23,69,14,168,161,181,26,83,132,150,79,124,95,179,104,87,213,221,53,150,119,117,145,201,34,157,161,0,10,229,160,47,74,133,136,84,162,94,178,62,85,202,74,198,132,19,185,71,109,79,214,38,213,
55,106,141,81,235,30,141,124,201,90,88,57,123,206,198,175,203,135,217,56,225,42,133,4,178,70,115,114,13,29,104,133,118,48,85,229,112,34,232,172,3,212,166,162,2,145,41,130,64,150,71,234,182,115,21,254,
170,68,28,36,106,80,176,207,40,137,167,114,46,163,54,3,213,123,142,40,172,140,40,185,184,144,99,213,38,111,6,10,53,3,201,112,202,187,143,60,89,53,246,170,8,142,211,79,71,17,96,148,38,68,219,33,67,87,70,
20,138,70,212,185,84,89,34,244,145,28,155,172,41,36,224,22,210,85,169,88,66,108,14,124,218,107,160,158,210,198,200,130,162,58,87,17,88,150,42,30,145,22,46,41,223,146,244,18,25,106,171,84,20,146,2,208,
211,146,205,250,36,234,107,154,198,177,91,191,234,130,227,192,213,174,146,21,73,165,114,198,241,44,19,107,69,254,115,20,123,156,49,79,97,237,172,254,164,204,206,145,138,210,96,173,166,172,69,215,81,69,
50,247,165,150,173,139,68,107,152,110,180,104,234,134,75,190,204,142,212,156,186,146,223,58,107,26,101,44,91,17,232,146,212,226,138,34,100,15,36,26,186,4,122,161,206,36,244,236,131,232,212,210,198,36,
231,48,138,180,68,245,96,35,242,148,130,83,35,66,145,123,118,64,190,119,132,55,200,11,143,194,153,14,186,65,84,94,40,18,224,68,57,138,240,70,35,125,106,111,22,217,50,17,120,141,244,87,197,148,59,131,147,
157,141,124,54,254,123,121,159,244,236,55,67,185,28,68,129,160,16,78,148,229,234,99,147,178,87,54,82,106,77,29,73,155,154,137,106,141,68,232,100,126,111,72,24,59,2,151,140,146,14,246,1,1,84,141,184,163,
65,171,20,62,150,7,228,187,3,109,183,221,171,100,21,5,205,102,223,171,132,240,236,211,171,87,239,59,114,54,66,206,199,72,29,118,219,85,45,152,132,168,81,133,243,163,141,35,221,189,19,127,91,10,193,102,
155,164,37,116,23,253,198,241,232,37,30,158,138,24,179,204,211,35,231,98,89,180,19,205,63,117,118,235,110,168,157,252,100,122,95,234,33,60,122,14,72,34,232,145,49,173,54,217,202,59,183,98,127,86,57,54,
202,136,107,203,191,109,8,41,135,24,35,211,206,119,76,158,21,233,40,218,241,144,131,103,53,137,178,244,20,210,9,138,129,217,19,151,32,17,146,234,92,138,26,56,218,156,153,225,119,214,198,21,29,223,222,
0,166,8,132,27,201,47,191,115,60,90,213,184,115,12,190,213,60,80,207,205,80,30,74,2,201,94,188,89,116,227,164,115,169,200,140,108,248,8,18,70,208,51,103,174,18,114,18,65,130,136,243,11,37,207,85,3,11,
138,214,101,227,62,90,159,212,203,154,160,8,228,157,226,172,115,180,46,85,41,211,141,130,102,28,136,161,98,193,69,211,44,50,43,46,2,95,58,208,6,141,88,43,202,34,14,115,175,34,11,56,18,61,85,96,142,17,
116,194,129,210,170,11,197,40,218,144,69,222,35,22,75,164,127,51,241,14,69,205,175,202,54,170,99,138,25,208,32,209,133,85,112,170,11,59,186,107,89,134,22,85,161,70,39,189,174,130,234,56,71,106,238,188,
232,161,20,180,47,122,191,171,234,25,71,227,38,66,158,178,122,41,6,123,239,184,102,89,150,53,125,1,244,174,201,136,9,189,206,119,77,122,179,251,247,136,52,21,114,132,106,96,231,176,220,125,201,186,196,
23,162,246,228,234,231,186,186,168,21,18,73,245,229,25,77,4,66,82,83,215,211,243,39,170,193,217,19,243,38,106,67,142,22,116,70,28,113,206,217,8,145,70,109,96,137,90,142,218,96,58,44,234,222,11,144,88,
47,42,81,3,50,54,136,227,75,86,255,168,140,217,113,4,117,44,113,52,181,151,186,180,212,94,173,71,48,34,71,76,81,94,180,122,7,68,230,229,89,125,213,250,237,26,206,171,23,236,181,60,208,12,6,140,132,129,
171,94,139,25,76,91,217,209,70,137,213,116,135,234,230,93,81,3,108,18,137,143,24,102,147,148,28,10,221,69,59,53,146,154,67,161,40,39,66,169,64,48,148,254,79,93,54,92,251,35,165,168,69,22,29,90,86,2,143,
186,253,230,204,105,247,40,97,31,166,208,142,150,181,243,76,231,133,78,33,67,7,233,89,174,175,85,82,151,131,78,85,53,181,171,232,206,44,239,215,42,66,85,29,127,81,91,173,41,84,215,163,241,171,232,44,187,
54,210,195,205,162,13,21,45,206,132,244,34,189,76,162,113,27,165,168,204,160,155,171,129,176,76,227,81,59,246,93,227,107,178,107,203,82,106,162,29,180,235,162,83,129,220,85,27,81,215,147,17,187,55,55,
42,84,17,178,170,127,79,195,183,162,107,220,211,73,174,234,186,210,20,132,17,83,116,122,79,103,33,141,210,191,84,228,26,153,76,87,142,57,34,163,107,138,192,100,8,0,25,151,217,247,4,57,27,121,121,58,235,
43,173,3,25,255,110,190,244,242,222,27,69,98,80,187,225,12,51,239,237,238,178,195,123,66,115,39,145,73,22,45,18,226,75,196,144,139,20,127,178,104,143,238,4,73,196,216,35,33,17,221,72,69,12,137,162,121,
103,215,150,69,101,217,216,202,238,167,140,193,201,2,149,169,81,17,200,50,67,13,84,36,79,8,96,89,219,81,34,78,47,45,133,140,11,234,149,153,153,138,83,132,42,51,12,207,218,75,69,248,228,236,210,49,112,
166,214,112,89,42,153,67,120,83,237,55,42,134,78,202,91,17,75,113,210,140,84,95,204,250,91,149,60,232,228,130,46,127,191,201,6,93,149,153,84,57,107,114,66,238,25,59,158,153,231,116,51,83,117,42,139,129,
42,135,58,59,113,94,156,85,232,166,23,165,87,77,118,179,151,53,41,107,149,232,84,21,175,38,17,5,241,76,36,200,203,136,190,177,218,48,71,227,69,25,18,56,130,246,187,215,170,49,18,109,58,92,130,222,40,236,
167,180,96,93,185,200,94,221,73,190,186,59,15,162,190,82,99,147,62,155,104,84,171,52,186,40,197,138,50,118,163,151,231,242,222,75,98,96,182,105,218,125,238,198,201,31,116,10,171,242,117,220,6,160,250,
155,149,51,180,74,231,68,215,19,87,16,71,23,84,137,21,208,129,67,202,170,52,127,201,25,39,213,36,38,139,149,138,68,170,242,91,81,4,67,211,180,28,202,124,85,191,54,171,47,117,186,136,202,72,73,49,189,57,
173,68,65,84,148,72,250,82,157,247,102,200,146,163,145,74,82,226,232,181,153,38,115,134,44,101,99,131,204,25,213,46,149,141,169,66,90,40,161,74,33,55,206,249,53,201,1,165,226,63,68,72,134,242,56,54,4,
22,169,228,198,41,34,134,171,102,228,210,244,213,34,82,237,80,154,139,85,201,125,115,34,27,34,240,30,13,6,162,162,228,16,110,220,168,117,196,208,184,122,70,73,203,164,54,62,106,220,56,218,207,244,92,55,
186,174,146,64,79,199,108,133,160,50,155,160,81,177,174,170,160,62,85,141,92,5,253,86,157,119,70,145,146,89,237,162,162,234,74,185,50,148,162,242,46,160,104,84,5,137,34,105,75,93,45,220,170,233,52,133,
155,42,169,33,170,44,25,25,201,129,147,71,207,254,142,26,190,215,105,174,33,50,73,51,161,109,60,146,218,65,211,30,162,122,100,100,50,55,53,167,50,113,105,58,73,239,111,132,160,179,172,159,42,19,77,91,
112,33,220,202,226,79,200,85,14,161,164,162,191,171,76,154,179,181,201,153,223,106,110,85,215,161,104,46,101,233,31,206,223,157,52,12,151,252,67,231,69,132,36,69,191,119,5,17,168,94,178,106,63,98,38,78,
200,149,100,142,93,147,242,83,249,78,153,118,103,166,156,225,134,228,202,98,134,170,93,184,42,49,234,28,144,218,75,17,225,4,5,167,145,51,10,101,69,70,245,88,221,8,220,57,195,161,231,93,149,118,118,206,
110,233,88,205,142,6,136,113,187,35,205,71,20,120,168,97,178,27,125,83,13,231,10,130,163,94,218,84,122,206,177,192,170,190,68,157,242,184,250,185,217,203,52,106,255,145,104,91,17,100,102,27,82,43,68,138,
160,59,110,221,156,121,158,173,155,68,139,221,177,110,91,187,41,19,153,83,70,5,158,164,201,204,36,250,162,19,172,146,182,224,236,212,200,78,134,70,73,42,106,172,194,63,81,154,75,245,101,24,165,63,56,139,
185,147,103,90,17,208,200,34,69,103,199,58,43,66,38,72,137,75,38,162,2,23,187,232,128,26,215,187,99,197,25,175,209,152,235,57,252,84,21,175,28,59,59,138,192,56,136,25,21,92,113,83,93,28,244,205,157,79,
238,75,122,121,31,55,229,208,17,51,160,136,28,121,103,69,99,181,247,14,163,99,97,121,191,13,221,241,169,136,33,250,91,20,113,144,29,167,58,184,119,156,229,105,178,119,70,170,161,6,223,36,98,202,206,73,
233,66,75,244,109,9,139,78,161,2,149,93,187,195,64,116,180,144,143,190,167,187,200,158,122,72,182,179,141,140,185,21,210,162,200,12,116,220,17,212,133,70,201,42,138,236,9,233,171,115,41,69,100,114,8,92,
36,146,137,250,136,68,67,217,60,38,68,58,210,87,17,116,152,205,25,98,166,238,32,84,187,115,194,65,208,34,68,48,98,237,43,82,148,234,127,42,210,174,198,73,134,20,145,40,148,104,73,147,40,122,187,221,182,
213,111,253,214,111,213,197,21,33,220,227,76,44,247,218,67,220,103,95,159,147,94,190,211,54,185,181,62,46,203,252,86,173,255,173,90,238,74,138,135,251,28,181,57,153,53,238,142,163,175,42,207,220,204,104,
160,101,104,219,139,200,118,195,102,101,165,67,37,1,201,78,66,165,65,68,187,231,106,174,81,180,91,206,36,222,156,136,150,70,36,174,253,18,109,147,108,140,80,25,65,194,146,83,226,20,89,89,41,90,80,105,
155,138,0,7,249,155,66,116,178,246,35,110,66,4,57,81,17,115,214,70,68,60,192,181,164,34,115,145,200,40,18,175,99,21,161,211,192,128,164,222,56,12,122,53,231,213,122,20,245,187,74,47,34,110,56,81,217,201,
248,203,218,213,117,211,82,235,4,65,64,148,243,87,52,47,55,142,126,173,154,52,10,86,203,200,72,212,152,53,59,31,33,233,4,42,41,153,66,145,4,82,37,80,133,163,206,161,234,76,13,150,179,28,181,108,0,141,
56,155,40,24,139,18,213,72,95,82,130,24,137,120,71,100,192,136,170,76,53,149,67,61,143,64,170,51,220,105,42,231,191,36,229,39,235,87,162,44,67,116,107,41,105,206,153,143,35,82,144,78,95,80,211,103,242,
111,50,14,157,126,117,32,253,138,92,103,101,157,172,222,71,213,111,173,42,66,220,61,168,62,41,29,92,74,147,146,14,2,215,129,163,58,160,104,62,92,228,82,163,218,131,234,139,206,104,27,50,144,43,121,132,
84,103,52,27,15,187,247,169,246,13,121,41,57,228,145,89,147,219,77,21,203,210,181,162,182,203,218,195,101,186,18,2,80,101,97,34,109,71,83,103,84,89,122,4,42,58,175,85,202,141,59,39,213,122,17,17,89,148,
22,47,37,123,85,132,216,71,136,123,116,141,164,228,171,153,235,245,82,79,60,91,135,55,116,119,162,162,48,229,82,50,66,146,32,134,202,68,157,72,193,5,20,170,202,96,11,23,126,84,237,236,18,175,20,212,71,
162,18,2,33,71,7,237,228,30,4,58,115,32,232,44,205,167,215,135,4,190,162,68,12,234,69,171,80,158,76,225,167,87,70,5,15,18,184,150,144,83,72,212,219,51,135,119,29,119,8,154,164,32,197,44,5,40,91,87,42,
139,109,164,145,29,233,225,82,181,183,94,249,168,64,141,163,122,68,231,84,214,78,100,62,185,109,17,245,189,90,135,178,151,40,65,97,42,58,186,173,181,182,161,48,70,53,36,174,26,238,142,64,19,85,187,181,
209,144,159,216,140,81,120,103,196,170,168,106,122,61,98,109,228,194,157,78,59,142,232,206,170,133,55,50,10,206,94,58,174,194,204,190,199,150,35,134,62,171,204,21,40,204,189,102,89,118,98,40,157,245,211,
104,26,73,84,190,209,241,79,213,170,40,95,36,107,19,194,1,216,213,133,117,198,78,197,204,189,247,194,234,25,214,47,203,149,109,250,85,253,163,127,103,155,239,232,218,77,79,68,55,42,84,182,163,115,83,74,
156,137,144,69,140,110,202,12,137,184,104,59,68,209,101,175,51,150,147,63,211,189,85,26,189,148,88,163,180,137,201,46,56,171,147,67,150,33,81,60,137,152,157,200,86,149,217,209,107,238,157,31,43,82,132,
227,252,163,54,144,21,125,82,122,238,78,202,224,164,34,145,51,120,213,191,202,65,136,146,119,178,241,164,250,50,90,227,178,54,35,107,11,29,163,202,13,74,181,67,22,33,71,227,51,155,7,132,228,68,16,193,
44,234,36,17,63,13,134,122,168,141,131,24,42,196,177,181,14,11,87,237,222,137,90,125,4,173,101,13,83,73,192,39,110,30,138,241,70,195,123,231,48,188,170,151,91,117,24,160,238,10,85,81,113,119,7,95,33,92,
144,193,90,137,108,43,246,108,25,25,162,114,31,167,62,14,116,154,157,17,185,227,206,65,20,28,61,91,183,15,171,231,153,150,171,51,0,0,32,0,73,68,65,84,135,85,133,154,81,84,134,26,15,84,250,184,122,118,
90,65,150,92,68,201,105,251,25,168,132,186,87,15,157,112,198,1,125,145,222,240,92,122,80,77,59,42,186,87,164,62,226,154,9,43,221,209,229,119,189,235,29,99,234,202,96,35,101,84,237,180,172,239,136,65,44,
213,178,165,80,178,51,40,43,19,55,83,10,33,253,22,181,103,5,222,167,234,43,148,180,86,37,65,245,198,53,125,177,80,82,217,40,145,132,170,109,57,101,29,57,158,160,42,105,85,125,98,162,169,74,148,114,170,
199,46,21,109,96,87,175,216,213,61,206,72,76,238,189,157,13,162,130,112,29,45,118,165,191,188,251,239,77,79,201,161,71,186,80,81,22,133,74,8,244,72,239,79,96,139,40,18,35,106,38,234,28,179,90,143,172,
179,123,100,18,71,129,73,125,92,141,81,138,72,168,122,56,176,166,130,149,8,164,166,72,13,180,111,105,84,155,61,35,27,91,21,189,91,5,113,59,191,39,185,169,81,4,172,156,124,220,141,167,99,56,78,209,7,10,
245,245,22,85,7,29,235,141,13,146,222,225,110,134,171,105,111,10,33,163,74,60,84,184,93,29,113,205,98,214,146,117,104,4,1,80,144,252,154,56,47,84,34,50,178,251,26,137,82,70,27,186,167,239,57,178,251,206,
162,39,10,33,101,81,187,114,126,168,230,108,85,8,43,100,81,172,232,4,87,68,195,41,26,49,242,189,138,136,93,164,198,141,224,150,247,205,254,237,234,243,186,78,32,203,136,156,234,162,46,163,112,229,176,
225,68,208,42,178,86,227,63,155,83,14,225,201,65,201,178,20,26,215,185,197,173,251,46,170,53,146,178,229,162,57,153,43,147,187,110,209,113,28,33,80,68,100,63,75,59,60,250,108,178,93,35,81,73,161,231,119,
84,207,49,219,229,170,244,16,181,147,166,110,38,138,16,68,118,55,52,146,173,166,249,68,145,40,209,100,173,186,204,59,68,132,17,191,210,236,220,80,145,169,104,202,140,138,178,104,27,144,115,120,50,198,
213,253,119,191,203,82,53,122,227,146,40,127,41,20,133,64,104,84,89,73,69,126,81,31,56,103,230,21,179,245,81,63,77,197,39,232,33,114,174,251,144,187,145,172,184,225,144,181,131,34,73,106,30,43,162,160,
218,244,83,211,110,58,111,137,103,242,13,74,68,68,178,169,170,176,65,212,88,232,32,113,204,154,73,35,68,147,43,234,228,106,164,234,156,211,168,151,58,25,28,17,115,81,193,177,164,79,41,243,113,150,3,132,
3,223,57,11,228,172,178,186,240,101,245,108,189,66,124,113,145,5,90,198,140,176,225,154,114,87,231,137,147,191,234,142,165,145,212,30,146,230,84,37,117,85,203,182,76,215,170,156,43,247,188,77,21,105,39,
202,109,174,172,5,209,134,127,183,78,52,5,165,55,134,213,121,106,24,205,187,230,217,174,209,246,146,20,163,224,147,17,134,153,58,32,31,53,62,118,241,114,23,14,33,166,215,61,56,161,7,31,18,123,49,7,50,
83,176,85,85,10,171,114,20,224,146,116,156,92,230,10,227,119,249,91,5,81,102,47,70,66,234,155,217,71,196,106,202,49,113,119,198,190,107,99,85,237,63,87,65,137,62,199,185,63,49,109,174,30,109,16,63,215,
106,187,246,94,74,36,79,155,146,122,136,234,80,239,252,52,147,132,85,144,188,75,46,203,8,84,93,8,151,24,204,210,200,36,131,31,51,59,37,213,161,202,152,150,116,174,130,2,20,121,71,233,120,210,40,79,217,
126,17,226,82,230,12,239,42,16,169,242,168,126,161,121,125,132,212,163,210,3,92,18,138,75,8,33,176,46,133,147,178,133,155,160,35,213,104,132,232,205,58,40,210,8,90,68,115,57,201,102,170,26,233,143,8,79,
184,107,133,27,73,86,197,7,70,209,177,145,180,153,138,232,13,61,195,116,81,74,167,61,28,93,228,48,136,33,59,53,23,134,114,41,194,100,199,86,49,172,30,81,191,81,215,82,138,123,149,154,79,118,69,116,23,
181,140,74,73,180,18,253,150,26,205,86,162,115,103,119,175,34,192,81,168,61,34,16,40,51,111,154,50,228,68,17,78,250,86,182,24,145,178,186,16,103,229,156,176,55,30,221,20,152,37,186,149,141,31,151,108,
151,233,183,238,254,175,135,250,80,253,224,202,75,52,170,15,37,192,16,125,93,53,15,85,123,81,132,171,162,145,76,34,122,135,220,164,218,145,108,10,55,174,238,170,19,29,40,53,27,199,6,136,164,45,184,94,
146,196,208,56,139,68,122,145,215,242,55,148,44,148,149,129,170,184,168,246,164,138,36,180,92,81,100,225,248,190,42,148,66,213,145,188,60,20,137,165,87,95,42,156,65,18,232,51,226,16,209,143,94,254,150,
144,124,28,179,225,222,189,163,49,27,161,10,217,152,203,206,45,35,61,93,186,177,28,209,96,37,26,187,61,253,92,58,14,28,2,153,66,101,170,103,136,148,112,67,77,194,157,212,41,87,103,89,137,239,208,168,49,
123,255,56,68,56,130,76,108,42,59,205,17,152,130,44,132,213,131,254,89,90,183,85,184,170,122,14,72,219,155,182,131,82,66,26,177,63,154,169,169,58,202,134,28,81,71,201,238,147,105,174,146,178,101,4,5,7,
70,171,42,76,85,231,105,70,248,80,57,161,100,222,18,21,25,199,47,116,249,247,136,220,164,96,198,222,239,150,132,155,170,128,67,54,46,142,34,183,140,108,51,50,191,92,152,150,194,226,228,90,186,33,113,203,
64,238,79,190,167,47,89,53,238,215,116,241,175,28,102,19,85,10,7,182,115,243,19,43,86,106,10,246,33,132,159,236,239,163,196,137,12,102,200,242,188,92,120,163,250,189,106,115,162,94,66,33,198,74,127,56,
176,181,130,170,213,2,64,230,14,129,223,179,251,42,88,93,141,25,2,145,85,206,17,157,163,33,138,36,16,184,210,129,48,105,157,157,99,19,18,225,208,77,144,163,248,67,218,155,64,219,238,209,145,179,214,246,
252,133,137,36,34,37,210,81,97,153,30,255,38,130,198,149,12,231,198,57,136,85,202,56,217,0,82,121,89,52,159,208,137,38,84,26,138,251,114,85,240,159,82,103,201,224,14,119,167,149,181,169,27,53,18,66,142,
11,211,84,93,120,220,8,84,149,211,177,121,83,182,81,138,200,225,160,33,206,100,175,32,58,149,115,119,215,48,158,34,69,78,42,155,130,134,71,206,128,41,124,232,160,21,21,162,139,155,154,148,165,171,169,
103,168,122,141,56,112,85,214,212,12,241,169,164,239,140,186,132,141,212,103,181,90,181,181,218,153,147,136,142,124,34,77,215,170,16,54,221,53,85,225,140,168,163,35,131,104,18,81,184,209,2,105,211,74,
164,69,34,126,162,168,180,108,19,167,205,151,101,200,8,24,25,130,81,177,62,203,202,236,192,234,153,158,49,237,119,26,133,58,139,55,77,27,91,222,35,75,125,82,232,133,66,148,28,3,229,168,191,93,227,108,
7,189,160,74,60,174,122,153,131,46,145,62,27,61,102,27,77,31,115,73,71,110,26,150,131,244,208,249,239,32,136,14,178,211,90,199,141,37,59,128,39,212,244,232,83,49,155,37,94,123,244,128,91,153,78,171,84,
138,94,98,48,33,113,40,165,14,85,118,26,189,56,169,39,89,100,77,35,206,76,145,164,119,15,117,29,73,247,113,34,8,69,60,82,99,33,27,123,74,109,70,161,55,52,26,93,170,14,41,50,152,138,178,137,168,134,66,
115,72,20,74,209,41,133,50,101,182,93,52,58,86,234,93,20,9,160,182,115,25,122,231,152,216,83,4,202,65,121,122,150,94,244,37,74,29,166,200,75,45,91,103,233,184,114,159,151,217,192,245,230,44,85,179,218,
84,13,146,221,168,105,223,196,148,89,59,49,181,208,56,145,193,76,219,40,10,27,85,132,0,122,36,142,17,178,132,171,64,51,11,210,86,139,231,72,219,85,144,141,222,153,37,245,51,173,64,226,138,244,50,58,47,
40,140,237,36,230,211,113,169,32,63,101,182,93,169,207,110,157,136,93,86,74,54,217,33,12,245,238,65,230,160,11,99,19,195,12,234,105,219,51,157,207,238,67,190,31,133,87,35,47,107,21,88,244,144,23,98,160,
112,244,140,221,235,55,170,177,149,41,47,165,222,147,72,147,80,205,179,115,39,55,26,115,207,161,92,3,108,21,97,103,109,153,13,102,39,82,32,41,56,100,241,87,34,9,202,76,57,123,94,212,199,84,19,152,140,
65,186,3,206,254,63,218,189,246,218,128,70,135,174,179,78,54,174,148,91,76,37,45,131,32,51,52,66,91,34,13,84,87,155,154,64,103,145,23,65,184,178,254,239,213,213,209,68,206,218,141,24,90,19,100,78,57,227,
56,47,60,138,12,208,244,178,172,94,14,47,196,245,48,142,214,105,231,218,12,41,217,184,138,66,209,98,75,67,122,34,38,77,66,105,10,19,186,164,16,250,34,205,180,23,41,233,33,35,57,17,161,113,18,253,141,216,
180,101,253,76,35,103,71,35,119,84,46,177,122,62,239,144,60,170,176,22,69,16,212,194,49,11,161,168,42,229,184,17,251,136,166,176,131,162,140,204,103,58,14,170,253,231,162,2,21,132,199,69,178,84,234,82,
246,93,117,124,71,235,215,110,36,73,81,4,138,114,56,158,185,14,27,252,90,217,119,43,65,173,95,42,11,89,100,112,77,15,250,163,231,102,7,211,202,178,172,98,11,70,136,7,153,85,209,238,125,34,5,143,204,124,
124,249,93,197,210,40,179,95,138,202,167,116,102,163,231,41,50,210,136,228,90,86,103,55,87,215,49,237,238,253,70,105,111,82,226,132,90,232,42,41,35,148,252,228,16,127,212,124,160,47,71,7,106,166,247,169,
216,132,245,218,216,25,7,78,185,233,186,66,84,149,162,241,214,219,156,83,5,35,50,126,72,202,15,33,142,141,144,68,201,239,233,188,137,162,234,94,29,119,219,118,67,119,24,142,154,141,130,64,92,221,72,122,
46,160,32,168,94,153,162,134,33,240,75,86,46,250,183,232,160,63,34,43,101,186,191,234,172,163,186,123,207,32,171,236,172,128,192,61,10,2,39,27,51,71,83,149,30,85,80,187,38,250,146,38,164,44,250,29,57,
239,116,206,208,102,243,19,220,51,60,165,188,21,205,205,236,187,12,98,175,68,153,52,189,174,34,213,72,63,202,254,45,234,131,10,75,126,196,69,139,174,61,179,132,99,92,244,166,130,120,133,231,244,206,11,
76,61,220,73,160,158,105,166,90,153,248,153,129,181,11,15,206,252,27,217,201,87,104,244,145,115,73,21,26,165,17,118,85,251,146,164,183,168,8,36,75,157,138,12,126,221,244,38,58,241,149,94,104,175,95,149,
118,177,138,102,170,125,87,137,144,85,127,84,145,7,146,46,166,218,125,41,44,226,174,71,174,70,111,165,29,213,181,153,195,79,52,143,213,252,38,81,189,171,117,61,67,33,46,90,155,233,181,85,109,118,23,162,
190,65,72,129,184,105,40,41,38,165,149,74,101,186,168,89,178,123,32,236,208,212,213,142,202,77,223,81,101,232,181,133,99,30,94,49,207,117,228,175,122,245,207,118,251,89,84,71,211,51,168,110,47,117,64,
137,250,198,37,110,169,205,100,22,65,71,209,173,210,224,84,4,173,44,122,203,162,189,234,57,34,33,215,100,245,85,99,188,34,154,178,172,103,149,3,65,162,166,229,115,93,93,99,130,236,209,116,14,18,193,103,
145,56,37,113,101,207,82,235,145,139,24,82,242,169,155,254,226,122,23,103,107,232,134,228,4,170,9,229,88,193,140,40,74,80,181,144,145,157,136,83,214,17,203,156,30,180,224,170,217,84,72,24,238,14,219,185,
119,197,164,218,213,79,29,81,147,154,1,33,85,208,18,215,0,154,160,7,142,25,58,57,39,167,27,200,202,252,170,214,151,110,234,170,243,55,107,75,66,108,204,158,213,211,210,117,200,93,179,12,196,151,134,211,
4,186,85,227,194,113,141,138,238,231,104,74,171,114,103,90,198,100,205,80,99,63,123,254,58,51,37,118,22,65,2,143,84,124,222,232,239,168,2,133,187,144,87,38,64,54,169,50,120,146,40,96,84,77,169,151,144,
15,129,255,232,198,198,105,131,236,89,100,17,115,141,208,171,240,182,3,225,41,72,41,51,253,117,200,34,17,65,132,110,16,170,121,133,21,221,93,122,230,228,104,175,58,27,13,213,174,89,116,161,72,86,203,151,
66,22,89,210,227,173,229,53,138,161,159,149,143,156,7,103,227,148,48,115,201,24,136,206,156,179,243,104,53,23,178,23,160,163,3,29,33,33,174,220,226,70,65,22,100,208,46,27,154,230,26,210,151,40,85,17,82,
86,61,228,249,212,97,32,50,213,165,187,28,154,246,161,136,0,163,26,145,52,42,38,169,56,153,198,108,53,2,174,10,125,16,248,38,154,196,36,53,42,186,182,98,140,237,64,75,35,186,176,163,209,118,164,179,234,
30,81,168,23,152,139,196,184,127,175,108,224,171,185,151,84,152,69,125,151,145,23,71,199,9,133,171,93,148,128,190,80,43,99,111,68,9,201,77,171,75,57,26,51,53,19,119,35,45,181,243,27,81,25,114,118,255,
238,34,67,15,227,51,205,88,69,176,34,58,140,78,59,41,194,142,147,66,17,17,111,40,84,57,218,215,110,212,75,238,21,145,82,28,98,15,209,178,93,18,86,156,23,61,105,243,81,120,217,249,77,69,183,52,67,48,28,
50,17,33,183,85,55,88,85,152,153,166,39,85,73,91,142,22,239,114,44,211,182,38,209,30,65,149,178,246,170,246,127,21,173,160,207,115,230,29,209,243,61,250,239,13,241,71,115,76,173,213,46,205,37,3,81,146,
72,111,103,150,237,182,136,49,116,22,181,69,103,7,189,8,37,139,66,136,170,79,101,35,144,41,190,100,125,73,145,8,69,208,170,234,126,70,125,166,118,229,21,178,4,73,53,234,17,81,20,113,71,45,50,68,193,134,
140,79,162,4,69,132,62,92,147,244,10,33,196,141,66,73,116,227,136,140,56,86,98,217,58,22,33,108,174,209,52,53,251,94,62,39,34,223,85,17,8,213,246,148,112,147,173,115,81,42,92,37,186,204,214,200,138,211,
10,37,184,69,109,182,201,224,24,114,222,67,152,168,85,131,236,234,142,174,74,156,25,129,205,156,115,202,234,238,90,25,238,58,226,251,149,100,113,71,240,218,129,100,201,4,172,140,43,101,118,93,181,171,
90,234,154,142,194,131,85,232,172,218,175,145,225,55,45,135,50,192,166,121,129,148,68,87,53,122,206,94,178,196,56,156,68,137,110,186,155,107,3,25,173,179,209,56,38,36,164,202,58,214,171,135,51,151,42,
218,189,81,219,85,162,251,202,28,35,218,213,27,117,190,17,69,110,74,112,151,68,135,85,1,98,21,93,69,229,167,59,50,122,246,67,35,24,85,135,104,87,155,237,234,137,198,173,138,216,84,84,64,95,112,52,26,139,
250,59,18,222,32,103,74,142,22,115,212,119,212,245,38,27,75,244,108,147,164,236,16,39,21,82,39,21,145,211,243,225,108,71,174,250,59,91,51,20,33,135,204,123,114,173,218,236,168,239,84,234,90,198,3,169,
30,103,80,102,48,209,44,38,47,19,34,144,179,68,100,232,60,112,17,63,71,188,36,66,98,72,116,77,162,113,181,185,220,80,56,149,152,43,211,66,69,209,110,38,94,236,178,116,171,3,183,34,42,81,217,237,168,156,
77,119,80,86,229,199,8,100,23,245,59,141,182,220,212,40,181,241,33,46,36,10,162,218,167,27,80,175,93,137,26,202,76,150,250,136,12,154,19,61,84,212,127,102,180,49,213,151,38,176,177,211,182,51,198,74,101,
60,141,200,64,58,115,174,42,120,81,45,39,61,87,173,104,228,42,135,30,26,121,102,245,88,247,10,48,131,196,49,66,93,119,6,211,82,77,102,31,11,225,104,238,169,123,144,222,131,204,122,139,111,70,34,112,250,
140,154,104,187,196,178,140,144,68,200,23,209,4,119,52,140,43,134,223,234,217,85,101,158,42,169,163,250,12,162,134,68,83,142,150,215,211,114,247,198,128,234,71,162,114,166,32,85,245,98,168,104,52,59,58,
205,213,23,73,37,101,109,150,213,36,85,29,170,16,114,200,88,170,110,88,84,100,74,199,124,239,56,83,145,8,55,212,110,140,216,251,80,200,116,4,110,235,237,112,85,131,59,118,84,142,119,36,49,96,142,160,49,
146,186,210,107,71,117,198,17,181,151,50,3,87,48,177,227,48,211,171,39,81,185,162,209,113,134,132,56,200,136,130,200,179,178,40,232,203,133,208,178,168,72,125,159,205,21,183,109,93,50,206,172,151,196,
168,30,182,67,78,113,94,154,206,194,157,181,189,234,59,114,54,74,80,22,119,78,100,101,203,206,28,157,180,21,138,72,18,40,158,124,239,114,115,70,54,216,27,231,109,191,47,123,31,7,154,114,42,236,70,82,89,
200,79,8,10,85,40,37,179,215,161,74,81,21,43,163,221,58,59,22,68,100,243,19,181,213,110,27,247,200,44,85,194,131,187,160,143,44,166,85,17,113,71,46,173,10,53,19,242,200,242,59,69,6,33,112,173,106,27,234,
63,73,202,224,250,72,42,195,101,213,62,217,6,159,30,95,100,109,81,233,179,12,101,32,210,155,153,226,80,143,36,68,234,223,67,127,84,191,58,239,128,140,121,155,141,145,172,63,104,127,70,27,236,141,186,152,
166,100,40,83,220,104,119,66,14,233,85,212,24,77,18,69,172,160,238,31,78,130,187,114,221,80,19,129,158,217,81,211,103,135,221,74,93,120,220,179,156,104,17,113,211,160,42,41,25,4,85,33,187,93,98,240,236,
164,121,41,146,84,182,147,166,142,50,149,121,25,189,208,122,41,20,89,95,244,230,152,138,64,20,1,106,217,38,17,171,86,165,33,17,212,75,109,12,149,120,72,164,241,76,219,66,69,136,142,17,186,66,234,72,244,
78,215,33,181,86,211,84,52,34,190,144,189,252,42,105,74,21,205,240,141,122,211,58,97,116,37,42,155,137,121,71,3,158,64,79,148,126,238,24,79,83,137,41,167,253,136,149,149,26,108,85,121,52,23,190,203,94,
236,213,179,200,204,194,106,230,153,147,123,159,153,58,205,251,36,106,56,176,233,136,250,213,8,90,85,117,189,113,34,156,89,41,95,52,213,135,70,207,35,81,90,5,133,81,144,120,133,188,227,148,173,215,78,
203,191,41,228,205,57,42,113,130,62,146,74,183,86,122,145,196,24,117,132,132,226,152,235,170,251,80,5,137,202,203,221,97,241,46,237,147,178,250,169,206,38,228,144,168,63,150,125,83,33,103,16,227,234,158,
125,24,49,254,165,139,132,99,153,53,162,133,219,171,155,90,84,151,70,231,206,121,95,69,215,215,233,51,170,128,69,143,67,42,103,151,196,208,152,90,33,58,74,61,196,226,74,105,230,42,11,181,172,108,145,161,
181,210,94,117,63,148,148,165,12,9,232,25,168,66,66,92,117,35,138,164,40,132,204,93,223,151,155,112,55,165,234,58,67,237,12,94,205,224,52,170,8,146,217,29,245,34,10,69,12,138,206,218,122,16,45,201,245,
114,34,175,232,163,140,127,73,52,149,221,151,192,101,228,12,72,229,123,82,232,146,192,148,81,223,56,122,187,228,60,209,37,193,184,231,110,132,28,162,96,61,2,87,71,16,159,179,176,16,18,18,177,204,114,224,
61,55,69,76,105,234,102,112,41,137,248,71,236,192,42,105,88,78,52,68,137,84,244,124,215,213,217,85,249,172,20,217,35,229,161,58,192,149,116,27,119,189,160,229,117,214,159,213,106,213,214,217,225,239,108,
145,111,71,59,114,86,186,65,53,42,161,80,156,27,45,209,118,86,247,24,113,45,33,250,181,203,239,168,161,45,137,230,122,6,199,164,125,85,250,132,187,123,116,220,93,156,246,33,38,208,100,140,68,41,32,203,
107,40,1,42,51,24,143,62,110,95,57,17,52,169,103,102,36,93,133,228,221,117,109,183,141,9,41,207,93,200,93,61,228,30,218,69,94,214,142,209,122,245,232,96,132,96,74,251,148,24,125,147,103,41,7,36,130,182,
109,168,57,182,163,46,68,213,76,50,2,144,218,49,246,254,78,8,23,217,206,146,156,77,58,164,156,138,169,114,182,19,173,232,125,186,4,148,168,93,8,33,34,67,28,156,9,69,83,160,178,116,29,2,57,41,210,137,138,
92,163,51,19,98,110,78,201,115,116,62,170,51,118,50,78,157,200,132,154,123,207,216,180,102,105,67,212,21,73,69,213,100,76,210,52,18,39,224,32,66,33,217,56,38,105,97,78,4,233,188,248,41,130,70,163,107,
213,142,138,148,151,217,156,185,125,76,163,225,77,101,103,65,33,160,17,141,80,242,34,173,170,229,184,59,67,37,180,238,238,168,156,157,217,108,3,241,209,212,160,125,105,233,186,117,172,168,218,204,220,
29,247,210,127,70,242,31,137,208,121,69,172,63,42,235,8,236,69,198,86,6,105,239,150,137,246,171,242,144,116,95,206,35,250,176,148,61,190,108,119,119,211,84,93,27,178,252,200,17,147,10,119,115,224,140,
55,5,245,86,16,207,170,18,81,22,32,45,219,117,147,69,17,212,101,66,157,151,170,104,208,129,71,105,36,28,253,205,137,82,51,72,138,232,238,170,54,202,162,152,104,49,165,247,86,125,230,68,51,110,91,101,218,
182,25,245,189,130,62,16,253,85,21,141,41,198,161,186,47,209,237,37,212,126,242,247,104,236,169,28,57,138,142,16,222,131,83,119,170,177,170,16,37,7,157,33,17,17,97,95,246,198,46,137,186,179,57,220,227,
4,168,20,143,72,156,132,44,252,132,127,66,218,91,165,123,209,179,213,101,253,104,106,26,69,211,40,26,74,116,165,201,60,218,56,234,50,180,163,73,212,74,97,21,34,122,78,14,173,51,114,15,205,137,162,141,
170,242,161,178,29,123,229,76,33,170,3,85,118,162,2,234,145,176,130,130,186,72,78,216,12,85,27,181,99,165,230,231,85,104,143,156,67,141,32,54,244,156,171,186,219,118,34,157,104,60,184,8,148,171,73,235,
158,153,101,155,70,149,19,77,94,200,213,151,217,12,99,232,106,100,54,138,102,85,145,173,25,200,221,236,121,182,140,84,169,149,218,181,223,42,216,68,165,170,236,254,62,34,154,100,191,83,249,160,46,41,193,
93,24,150,229,202,234,160,104,237,52,122,117,224,219,153,162,224,75,77,93,103,1,160,154,195,84,235,183,162,191,26,149,215,33,3,144,69,138,212,129,16,124,28,88,148,144,149,122,101,25,177,238,115,239,151,
25,137,187,105,104,21,114,95,69,95,219,109,195,170,206,112,111,45,36,164,198,170,198,239,232,209,69,101,29,37,169,62,213,13,78,53,173,144,164,239,168,190,207,224,99,85,207,77,6,119,246,34,42,162,220,66,
20,41,156,221,4,209,191,84,112,87,180,251,204,162,50,5,169,69,90,145,153,106,13,209,131,85,98,1,84,7,85,69,204,68,251,215,125,46,33,159,57,80,79,70,12,34,145,17,29,223,196,86,201,61,163,86,10,50,46,121,
138,64,87,74,205,101,228,124,216,149,251,163,103,75,4,49,160,81,93,21,74,164,81,39,81,226,153,21,173,41,61,108,183,110,110,159,83,78,10,125,137,18,180,80,69,234,244,185,17,122,150,193,185,149,20,153,77,
101,7,225,62,164,10,75,206,216,201,208,232,103,244,123,26,254,87,73,39,244,122,162,158,145,45,6,206,167,98,7,149,193,38,21,152,166,135,116,84,188,24,21,225,160,162,178,227,8,92,207,118,212,136,72,78,164,
143,179,141,164,195,206,31,169,15,105,63,87,40,197,209,146,85,155,226,229,194,235,200,66,222,0,3,118,198,158,210,42,166,94,187,217,189,105,182,132,218,248,69,229,142,54,73,153,214,110,101,254,168,246,
206,52,183,137,93,90,246,156,77,27,252,56,190,149,25,89,99,52,29,36,122,158,115,206,167,34,40,135,0,147,69,188,206,78,159,68,238,74,255,146,244,5,49,172,38,227,128,26,125,19,177,142,108,71,237,68,178,
132,144,67,181,150,21,154,66,211,134,162,93,178,75,176,82,227,32,115,80,82,68,161,42,218,163,206,30,221,23,170,19,33,142,158,15,58,40,92,134,236,168,239,200,252,86,250,185,42,109,42,154,155,61,4,45,123,
65,43,148,142,152,109,103,169,113,100,92,208,212,54,114,118,25,33,156,106,60,247,238,191,25,81,100,113,33,28,74,123,118,23,215,140,164,162,32,22,231,101,48,18,125,56,48,85,182,115,203,224,65,50,152,92,
162,82,149,156,162,148,93,40,76,166,54,78,212,250,140,70,241,234,122,199,88,128,62,219,237,159,10,66,164,32,211,170,227,210,136,163,76,53,18,117,218,228,208,223,87,206,243,28,248,59,66,26,92,164,42,66,
199,20,217,209,237,91,186,201,205,198,29,201,145,30,233,187,40,205,43,18,252,216,109,163,181,163,232,50,99,112,101,13,72,244,44,179,223,245,212,96,50,83,103,245,201,8,69,170,236,106,194,80,243,107,162,
135,218,27,184,145,130,76,85,31,120,116,179,224,64,228,100,82,100,102,226,174,134,44,129,4,119,159,91,53,77,119,180,92,157,151,168,26,43,215,38,123,135,8,70,136,75,138,8,68,54,0,78,187,184,76,222,17,191,
207,172,76,142,4,159,67,18,114,55,0,217,186,216,51,127,206,234,226,174,177,212,15,52,250,94,157,223,82,217,69,165,64,68,8,169,209,111,72,176,17,213,55,180,51,35,182,96,20,110,233,93,147,193,32,4,146,80,
106,49,89,190,21,129,2,40,36,171,118,109,89,84,226,230,92,101,126,155,10,218,174,146,133,28,163,102,247,76,147,26,16,171,8,136,44,226,138,92,68,38,117,5,138,117,35,105,7,245,112,55,53,244,191,163,185,
227,34,82,42,183,150,30,89,56,16,61,65,171,28,24,89,105,115,187,233,92,89,30,178,243,18,173,140,77,39,250,173,164,231,208,77,52,77,95,26,225,11,56,86,141,46,193,240,186,204,6,181,139,175,236,218,41,153,
198,209,34,37,17,93,207,125,36,115,10,33,59,142,94,36,23,69,183,25,204,226,186,98,144,190,88,70,20,206,78,146,246,89,212,158,21,72,206,137,74,93,103,5,213,15,189,116,158,221,58,101,250,181,46,12,230,148,
133,68,42,163,81,140,163,141,28,141,95,7,109,80,41,79,212,45,164,87,174,222,152,207,116,154,179,177,76,199,45,209,155,37,243,106,57,230,156,53,80,141,125,119,35,229,92,163,250,119,6,90,89,69,200,212,218,
16,233,24,247,214,132,12,9,141,202,184,113,244,55,163,200,70,153,236,170,115,73,170,228,18,157,147,186,10,52,142,66,77,182,107,137,202,152,237,182,170,169,13,244,60,152,166,178,100,81,147,34,214,40,253,
91,69,64,114,72,42,21,5,167,106,228,75,213,72,178,58,103,243,132,68,81,42,226,87,10,42,42,250,114,203,211,187,150,46,94,110,59,102,81,239,146,44,147,33,50,52,221,106,4,153,81,200,89,228,16,53,114,254,
153,193,155,138,128,228,244,193,136,180,171,227,50,84,65,51,40,170,67,202,231,34,26,189,223,109,122,63,168,152,47,59,249,135,206,249,192,172,179,197,12,78,33,103,28,89,39,85,204,192,247,161,61,235,92,
151,149,127,212,151,149,70,107,238,217,79,165,77,70,18,207,71,213,103,156,79,69,81,168,154,26,54,26,149,184,237,76,164,56,105,180,220,139,82,169,104,120,20,153,143,230,201,186,107,136,139,220,68,215,68,
41,91,61,82,204,238,223,158,124,242,201,246,145,143,124,228,186,123,29,253,237,234,213,171,237,15,255,240,15,219,87,190,242,149,214,90,107,119,221,117,87,251,245,95,255,245,246,187,191,251,187,255,24,
117,109,54,237,87,127,245,87,219,67,15,61,116,195,245,173,181,246,11,191,240,11,237,207,255,252,207,175,187,254,215,126,237,215,218,67,15,61,212,174,92,185,114,195,253,127,227,55,126,163,189,230,53,175,
41,173,129,209,70,49,74,3,82,215,185,243,116,221,11,147,41,36,66,96,214,25,106,41,68,157,197,133,36,163,122,210,137,164,26,219,97,185,58,80,204,8,81,203,129,123,35,40,217,29,96,35,139,134,42,3,181,189,
163,240,144,67,6,115,97,87,74,96,25,125,118,101,67,74,141,152,43,245,37,245,156,65,104,113,13,175,157,99,148,108,28,210,205,133,35,130,79,140,189,151,17,168,34,197,236,254,237,169,167,158,106,79,62,249,
228,181,235,159,124,242,201,246,212,83,79,181,214,90,251,131,63,248,131,246,181,175,125,173,61,240,192,3,237,193,7,31,108,191,249,155,191,217,238,189,247,222,214,90,107,103,206,156,105,15,60,240,64,187,
235,174,187,218,23,190,240,133,246,237,111,127,251,186,235,143,94,130,71,207,217,189,254,247,127,255,247,219,183,190,245,173,240,254,84,137,139,190,107,50,143,89,215,66,49,155,47,200,141,69,89,249,84,
34,35,5,65,45,239,159,237,54,162,144,157,104,177,18,1,226,8,74,116,83,28,104,42,129,250,61,17,31,119,163,168,94,221,70,19,255,171,118,65,116,67,18,165,202,144,151,79,164,141,172,22,71,210,199,20,245,200,
230,192,62,95,162,170,172,14,169,101,164,255,51,248,252,80,194,43,110,180,93,109,127,53,22,71,202,81,169,207,83,79,61,213,30,127,252,241,107,255,125,244,221,215,190,246,181,118,239,189,247,182,207,126,
246,179,55,220,247,213,175,126,117,251,236,103,63,219,158,126,250,233,246,133,47,124,161,125,253,235,95,191,238,250,163,191,211,235,43,27,255,17,244,101,52,37,177,155,237,64,42,145,29,162,19,141,84,50,
209,70,172,150,232,193,115,166,17,235,66,51,116,183,178,124,70,5,146,205,202,90,205,55,92,238,198,122,196,138,200,224,56,51,113,174,234,149,86,12,207,233,216,203,200,97,163,59,221,221,178,144,58,70,218,
203,68,111,184,146,254,83,209,193,205,12,164,51,19,120,135,60,232,44,140,21,195,249,209,40,93,69,155,89,164,171,162,156,136,212,54,154,219,186,124,118,5,97,107,173,181,139,23,47,182,47,127,249,203,237,
27,223,248,198,117,215,239,254,125,247,243,210,75,47,181,47,127,249,203,237,155,223,252,102,107,173,181,59,239,188,51,189,255,75,47,189,212,190,244,165,47,93,187,127,69,43,155,180,49,69,132,28,132,106,
249,217,68,17,103,20,129,146,168,48,250,208,116,1,231,121,84,57,197,77,203,161,36,36,162,178,68,219,212,113,69,161,114,125,170,236,81,20,160,80,3,165,242,68,52,73,169,42,19,161,253,19,119,141,222,36,35,
134,198,132,44,149,69,83,189,8,151,106,48,103,253,215,107,31,162,178,69,250,32,75,13,201,174,87,68,158,104,108,80,205,219,12,201,160,132,157,138,44,30,209,231,38,40,158,82,143,82,218,177,110,25,178,239,
127,231,119,126,167,251,247,231,158,123,174,253,209,31,253,81,59,127,254,124,123,228,145,71,174,221,227,232,239,203,207,243,207,63,127,237,239,247,222,123,111,123,236,177,199,218,159,254,233,159,134,47,
158,231,159,127,190,253,241,31,255,113,59,127,254,124,123,248,225,135,195,179,236,217,168,103,150,70,88,225,85,108,183,219,62,11,119,6,53,90,45,156,179,172,116,8,4,84,169,67,149,180,84,85,197,152,161,
67,236,158,5,142,194,179,163,236,190,17,101,30,74,18,171,64,155,189,72,151,168,27,169,13,200,40,252,26,33,2,42,79,154,206,159,72,47,84,65,187,196,196,56,114,192,112,136,69,61,38,120,180,129,201,94,142,
187,109,150,65,198,84,215,53,59,166,33,112,126,212,206,42,64,217,173,7,241,179,165,115,237,85,175,122,85,251,232,71,63,218,238,190,251,238,235,190,191,243,206,59,219,227,143,63,222,126,240,131,31,180,
191,252,203,191,12,255,190,75,32,234,125,118,239,95,213,47,222,182,214,214,32,23,158,230,125,147,32,168,119,237,186,146,215,86,57,115,202,96,44,10,243,69,147,164,106,77,228,168,156,16,8,170,66,30,161,
54,76,35,9,212,10,218,32,57,105,164,221,168,154,7,177,24,34,103,137,209,130,90,61,187,139,218,92,157,203,237,78,42,34,120,238,170,194,80,53,170,136,92,162,224,105,50,174,50,82,70,47,186,204,54,60,234,
69,172,230,87,20,213,47,219,192,73,71,136,218,91,193,122,217,75,213,201,247,236,125,159,37,247,43,205,238,136,84,180,123,191,207,125,238,115,237,115,159,251,220,13,247,191,237,182,219,218,123,222,243,
158,118,254,252,249,235,126,115,251,237,183,183,247,189,239,125,55,252,253,182,219,110,107,63,255,243,63,127,237,239,207,61,247,92,218,206,231,206,157,187,118,255,10,49,237,234,235,223,218,174,190,243,
147,93,65,255,94,148,218,219,80,57,202,82,217,92,88,171,31,70,214,93,209,226,27,13,104,250,226,33,3,144,38,103,247,58,34,203,171,204,22,112,87,154,173,183,72,40,53,12,53,225,212,89,139,186,87,22,61,102,
47,76,250,34,206,250,62,139,128,178,8,174,146,106,163,94,66,164,141,200,89,8,121,169,170,104,157,70,216,203,114,171,190,163,103,140,132,141,156,189,240,178,69,204,17,141,136,34,179,170,246,54,61,91,171,
100,8,80,177,24,213,63,213,180,27,218,151,209,253,222,241,142,119,132,207,189,112,225,66,123,246,217,103,219,239,253,222,239,181,207,127,254,243,237,217,103,159,13,121,7,173,181,118,225,194,133,176,30,
143,62,250,232,13,223,93,184,112,161,253,228,39,63,185,118,255,103,158,121,198,98,108,183,205,185,118,229,252,47,182,51,79,63,137,94,130,100,92,184,65,204,117,136,11,57,236,62,34,142,56,4,135,145,92,187,
165,50,76,149,176,16,193,30,81,163,103,196,18,162,61,171,148,45,212,100,170,106,209,102,68,132,236,254,25,25,168,114,166,82,37,91,85,108,219,212,203,113,36,242,116,162,107,250,82,160,19,87,109,122,220,
242,204,62,166,112,210,85,156,235,221,151,1,237,71,55,194,113,82,101,232,198,150,32,85,46,116,79,3,138,94,155,126,234,83,159,106,143,61,246,88,183,140,159,249,204,103,218,133,11,23,218,247,190,247,189,
246,237,111,127,187,125,254,243,159,111,63,250,209,143,194,168,248,211,159,254,244,181,23,242,238,223,63,252,225,15,183,143,127,252,227,55,252,253,211,159,254,244,13,247,255,241,143,127,124,93,57,175,
220,255,112,187,244,79,255,69,183,205,46,95,248,88,59,243,237,191,108,171,139,207,15,25,172,95,126,203,227,237,226,71,254,59,11,53,232,62,231,115,159,251,220,54,218,105,42,56,193,33,59,44,239,147,17,133,
122,164,131,108,2,81,66,141,235,56,67,44,190,136,229,142,227,28,66,211,121,50,194,1,37,44,209,242,71,101,166,68,10,117,95,71,153,68,153,145,87,218,118,116,204,244,174,143,198,235,33,202,224,182,1,237,
79,167,191,29,133,36,167,252,51,62,174,217,248,204,242,85,251,146,60,103,223,117,169,142,93,103,141,217,174,214,237,226,135,254,155,118,246,75,255,75,91,63,255,227,235,190,187,122,223,67,237,242,195,31,
104,103,255,226,247,219,106,176,141,94,250,240,127,219,214,63,248,122,59,251,119,255,23,186,199,213,187,95,223,46,93,248,88,59,247,103,255,67,44,229,55,234,52,79,119,216,100,135,60,162,177,58,114,157,
147,2,67,35,167,158,161,171,107,250,92,113,75,167,253,84,109,199,37,25,163,119,46,228,68,173,61,227,102,114,254,67,251,91,153,102,143,140,173,172,175,71,23,183,145,69,145,154,22,19,47,89,245,125,100,188,
29,49,44,51,233,79,85,94,106,164,64,72,35,174,44,100,212,190,142,143,113,212,118,85,228,135,26,77,184,166,241,209,185,33,37,37,81,9,190,163,251,93,152,112,103,86,0,0,12,161,73,68,65,84,121,248,177,182,
254,209,183,218,153,23,158,105,187,79,216,158,57,219,46,93,120,162,157,253,210,255,220,86,112,157,201,250,254,182,167,126,175,123,93,111,141,216,110,91,187,250,186,183,180,179,95,254,95,111,248,126,157,
65,38,213,133,150,18,147,42,16,148,115,46,74,224,40,215,46,172,114,6,179,60,63,142,206,141,28,123,37,247,236,203,129,89,41,220,148,157,127,145,51,177,222,206,143,144,104,162,51,50,5,7,102,187,95,2,65,
18,75,165,101,217,50,55,29,58,238,220,179,175,140,64,66,212,116,232,162,29,157,91,210,23,6,133,58,41,177,172,122,156,84,217,120,186,58,195,174,245,150,3,37,170,163,38,165,208,228,170,112,45,55,74,228,
40,131,176,245,175,222,254,234,118,249,159,188,187,173,158,127,166,93,122,235,71,219,229,243,31,190,30,186,253,254,87,219,153,23,158,121,25,130,125,224,209,118,241,157,255,213,203,209,225,235,206,183,
75,239,248,228,63,146,140,86,103,218,149,159,123,95,187,116,254,35,237,210,163,255,172,93,126,243,7,218,165,119,253,243,151,95,208,111,120,123,123,233,237,255,229,203,245,88,111,94,254,247,251,126,181,
181,182,106,87,94,127,161,189,244,222,207,92,95,135,213,170,181,219,239,106,103,190,243,229,118,230,210,11,55,140,243,117,143,181,70,206,7,50,18,70,143,34,78,206,22,34,58,58,85,197,161,47,215,108,103,
146,89,42,145,73,144,45,138,74,233,70,189,132,179,201,208,43,39,25,228,164,94,228,133,234,190,56,29,82,147,218,72,84,250,194,37,14,209,141,96,69,70,207,17,255,112,54,44,234,5,211,139,166,212,185,103,85,
33,169,186,225,117,206,57,233,25,32,61,211,37,103,181,244,69,235,140,149,40,75,161,231,234,52,131,179,64,81,52,245,92,103,156,244,196,30,174,60,250,177,182,254,217,15,219,250,153,239,180,205,55,255,172,
93,254,185,247,190,252,66,188,255,205,237,234,61,111,108,155,111,252,63,47,175,133,119,220,211,174,156,255,80,59,247,119,95,108,109,115,174,93,122,228,67,109,243,159,161,216,171,247,254,147,118,249,23,
255,85,91,93,122,177,157,253,250,147,109,245,210,207,218,149,71,62,208,54,79,63,213,182,119,220,211,46,159,255,80,59,251,244,147,173,173,214,109,123,231,61,109,245,226,179,173,221,118,87,219,222,118,103,
91,93,124,174,93,189,235,254,127,92,143,90,107,219,115,119,182,213,165,23,218,246,213,15,116,251,127,125,221,63,18,197,33,210,105,110,158,97,164,200,65,35,44,39,234,85,209,148,154,108,163,139,58,53,40,
142,22,206,200,24,188,103,187,86,217,249,86,118,228,78,84,67,216,174,75,171,39,7,202,167,47,251,170,217,118,37,82,169,44,98,206,38,176,250,82,137,54,56,217,6,154,188,236,179,23,190,138,150,84,63,68,168,
14,89,212,29,25,67,50,30,170,243,137,246,177,3,191,210,40,147,174,233,174,37,95,52,38,92,15,213,43,247,63,220,174,222,247,112,219,124,235,223,183,205,243,63,110,151,223,248,174,182,126,241,167,109,123,
230,108,187,248,232,39,218,217,175,254,155,182,110,173,109,111,123,85,187,248,79,127,169,109,158,126,170,173,46,189,216,46,93,248,120,219,124,227,207,218,153,43,47,181,203,111,120,123,187,248,158,207,
180,205,211,95,108,103,190,247,31,219,213,59,238,105,87,30,122,127,219,124,227,207,219,234,165,231,218,75,31,250,87,237,236,215,255,109,59,115,249,197,182,189,243,53,47,63,231,45,31,105,155,175,254,235,
182,186,244,66,187,252,232,19,109,243,157,47,181,237,118,219,174,220,251,115,237,197,39,254,251,182,190,248,124,219,174,214,237,202,155,222,217,173,243,134,158,201,45,211,89,122,176,212,242,111,209,57,
137,178,90,170,218,203,144,50,19,243,234,8,82,28,133,129,84,25,156,93,120,148,155,71,84,162,168,177,119,22,189,83,107,39,165,127,154,17,58,200,228,235,245,113,6,43,102,73,234,142,218,204,232,75,84,89,
107,101,176,118,118,190,170,206,95,29,184,85,189,140,233,57,254,168,110,46,25,35,164,173,233,88,203,144,34,39,159,181,114,150,93,177,151,84,58,209,84,131,218,177,207,163,107,29,250,126,125,166,93,126,
219,199,218,250,255,251,235,182,121,230,239,219,149,87,221,223,46,63,252,129,118,238,111,254,184,93,126,203,227,237,204,179,255,208,206,252,248,239,219,149,87,221,215,174,60,240,246,182,126,241,103,237,
204,247,191,214,174,190,238,124,219,158,189,163,157,253,225,211,237,202,221,175,111,87,30,254,96,219,124,231,175,218,230,135,95,111,219,179,183,183,139,239,254,23,173,93,122,161,109,190,253,23,237,226,
219,63,209,214,207,255,176,109,190,255,213,118,245,142,215,180,245,139,63,105,151,223,240,246,182,126,233,133,118,230,153,239,180,75,143,252,98,219,174,182,237,236,183,254,162,181,213,170,93,250,249,127,
217,110,251,171,255,233,229,246,187,255,205,237,234,61,111,234,243,42,40,253,63,210,114,173,24,230,170,72,183,74,162,200,162,26,130,247,47,163,32,247,197,73,119,192,25,196,73,204,123,221,40,207,137,220,
28,88,176,130,66,100,17,13,177,19,202,198,216,242,254,81,212,94,154,228,205,215,24,118,175,113,28,67,28,17,10,103,14,84,251,184,66,28,36,235,133,139,32,209,118,233,161,29,209,250,164,234,237,230,137,247,
238,151,161,111,10,137,82,99,43,51,241,174,8,168,208,119,198,50,197,47,106,163,75,15,253,66,219,222,126,87,59,247,245,255,187,93,189,227,158,118,241,157,255,188,157,251,219,255,189,157,253,209,55,219,
149,7,46,180,205,55,255,93,219,222,121,95,59,115,233,197,118,229,77,239,110,155,191,251,98,91,173,215,237,226,133,39,218,185,167,191,216,174,220,121,111,91,95,124,174,109,207,221,209,54,223,250,247,237,
234,230,246,118,233,173,31,109,237,204,166,221,246,181,63,109,219,205,237,237,234,27,31,109,231,254,246,79,218,213,59,94,211,86,87,47,183,182,185,173,93,122,228,131,237,236,211,255,103,91,181,214,174,
188,233,93,237,220,87,254,143,214,86,103,218,149,215,191,173,109,183,87,95,134,116,239,126,160,93,126,219,199,219,250,199,223,238,182,239,134,24,223,18,243,235,44,58,232,17,70,162,131,247,106,90,136,99,
200,186,140,130,29,195,103,101,52,220,51,1,38,187,246,40,130,114,82,111,40,108,66,181,91,85,155,244,250,89,105,14,171,232,49,139,162,51,13,216,106,180,18,69,221,78,84,183,188,159,114,47,82,207,114,157,
112,50,233,50,106,38,157,113,3,150,253,161,202,168,22,213,12,233,112,82,233,42,136,75,100,116,157,17,254,50,212,196,217,116,17,121,83,87,222,210,233,3,21,225,43,173,113,218,119,17,2,217,251,126,123,199,
171,219,149,135,222,215,206,252,195,127,108,151,31,122,127,219,182,214,110,255,171,255,177,173,47,189,240,242,189,127,250,189,118,229,222,7,219,230,135,95,111,237,210,11,109,253,147,239,182,237,107,31,
105,219,239,254,77,59,243,147,127,104,87,95,119,190,173,191,255,116,91,189,244,92,59,251,173,63,107,151,31,249,96,219,174,90,91,63,247,163,182,62,119,71,91,63,243,247,173,93,221,182,51,63,252,102,187,
250,218,71,218,250,135,255,111,91,189,240,179,246,210,59,62,217,54,223,253,155,151,33,218,214,218,250,71,223,106,87,95,123,190,93,125,213,125,237,236,63,124,165,109,191,121,127,123,233,253,255,117,107,
151,94,108,103,190,255,213,118,238,27,255,182,191,134,254,246,111,255,246,86,193,29,179,62,21,39,114,247,126,135,252,28,58,135,236,244,115,248,143,147,210,112,136,50,56,41,4,213,212,140,147,216,134,251,
44,191,211,86,110,57,246,113,239,74,91,144,20,22,231,217,35,169,50,187,99,249,133,119,253,114,91,189,240,108,187,237,233,47,166,199,112,68,151,248,232,111,87,55,183,181,23,63,240,155,237,246,255,240,135,
109,253,211,239,227,178,210,64,241,58,8,55,130,8,40,84,64,161,176,200,174,169,7,47,101,112,155,107,119,20,193,133,206,142,57,130,143,40,35,209,33,50,80,88,206,129,219,168,102,240,8,187,174,2,189,59,164,
17,2,87,81,6,44,181,72,138,206,195,102,176,114,29,40,53,91,112,163,114,168,84,31,213,159,132,217,62,154,222,230,88,85,101,250,190,84,186,145,214,167,23,173,143,228,132,171,212,52,149,247,172,214,35,181,
62,57,250,215,174,241,183,155,85,176,123,221,165,123,31,106,87,238,121,99,59,247,205,63,11,201,84,17,65,169,171,125,124,246,142,118,245,206,123,219,197,71,255,89,59,251,131,175,182,245,79,191,47,145,204,
222,92,207,56,3,203,114,110,232,217,139,50,254,117,96,214,30,132,218,91,172,8,52,73,33,206,108,119,67,234,168,82,80,92,179,109,5,195,70,112,23,53,123,118,72,18,153,250,18,129,216,92,226,67,212,55,106,
17,113,9,71,149,51,77,146,106,228,26,141,187,185,145,163,100,13,119,195,187,79,3,106,242,34,160,17,15,121,57,171,178,58,168,207,204,151,168,219,174,149,64,197,41,243,140,250,186,99,242,250,208,237,76,
187,244,214,255,162,221,246,141,127,215,214,87,46,218,65,197,238,231,234,230,246,118,245,206,151,137,65,109,189,105,219,187,95,219,54,95,249,147,112,211,162,72,155,14,207,103,157,85,86,25,77,211,232,98,
249,239,72,91,87,165,110,168,50,186,209,103,207,68,58,186,111,117,112,19,114,80,22,113,82,103,136,172,191,156,69,140,230,201,169,232,154,244,81,68,238,136,190,207,234,87,213,72,37,17,246,8,49,74,237,226,
213,142,190,250,178,34,194,11,14,41,134,44,186,142,243,8,125,17,70,109,25,173,31,174,224,66,47,47,145,174,41,217,56,25,17,140,39,200,145,163,183,235,32,120,163,170,110,148,0,118,241,231,222,223,90,219,
182,179,223,253,107,57,126,178,185,116,229,213,111,104,219,219,239,110,103,127,250,189,182,186,248,124,187,248,232,19,237,182,175,252,235,118,102,123,5,147,45,9,226,22,181,251,38,138,232,200,46,93,157,
203,80,211,220,44,202,160,101,80,81,18,221,213,19,29,95,21,105,247,190,87,145,91,68,176,201,8,75,52,130,81,207,36,250,186,81,148,219,131,191,20,74,224,74,112,169,51,23,213,158,17,121,196,65,9,20,161,41,
171,135,154,3,153,84,154,83,231,108,76,82,84,39,35,27,101,102,207,189,190,82,230,237,4,241,201,250,137,162,34,10,21,82,136,64,175,125,213,248,81,72,146,106,191,108,172,86,124,103,179,54,81,107,99,133,
187,146,61,247,202,185,187,218,165,135,222,223,110,255,219,255,237,101,77,91,64,92,236,181,209,229,215,60,216,86,47,62,219,206,188,248,211,214,90,107,23,223,242,120,59,251,157,191,110,155,159,124,55,236,
123,138,160,81,132,97,51,211,228,216,61,7,27,129,2,92,10,254,12,152,165,234,161,56,178,163,115,33,170,234,46,178,82,95,202,120,204,244,88,35,86,101,79,99,52,243,252,115,38,176,42,19,233,75,146,43,27,237,
158,201,38,117,68,175,88,33,54,196,164,217,129,65,201,81,67,133,67,65,115,141,201,198,146,194,187,187,255,221,27,131,209,2,236,192,238,189,126,232,141,151,168,175,34,99,240,108,51,125,157,126,107,162,
223,155,33,72,145,29,31,205,98,56,250,92,122,248,3,237,204,179,223,105,103,127,244,13,59,179,99,183,252,87,239,126,109,59,247,204,223,183,214,90,123,233,141,239,110,103,126,242,189,118,246,135,79,75,132,
135,4,126,36,104,105,109,39,141,69,85,156,176,162,50,74,62,105,96,18,101,100,41,14,213,151,24,137,144,212,36,204,14,160,213,153,34,217,125,169,20,14,218,47,153,59,130,227,148,19,237,84,201,228,114,35,
83,178,0,210,58,103,11,139,74,183,33,247,82,99,217,97,253,169,179,250,168,159,178,136,51,107,191,108,199,31,149,151,136,12,16,71,150,222,189,163,127,211,197,54,67,88,104,202,11,89,208,171,238,51,110,26,
78,134,100,44,37,89,201,248,84,115,206,49,66,160,104,76,107,173,221,241,181,127,243,242,181,3,243,120,181,90,181,43,119,190,182,93,124,243,99,173,93,122,177,157,253,79,223,104,103,46,254,172,27,205,42,
49,151,232,157,64,234,191,81,29,72,39,69,68,82,161,121,74,42,212,166,185,99,21,75,30,39,164,87,47,68,71,185,163,26,121,186,47,84,231,252,142,192,219,51,136,43,238,153,158,130,204,105,36,238,248,48,42,
184,178,66,62,152,113,46,88,25,183,14,114,80,133,179,40,82,81,61,23,36,80,100,20,77,87,252,81,85,180,126,104,20,168,58,135,142,234,209,171,143,131,108,69,110,70,164,140,234,125,209,251,189,226,141,220,
249,213,63,65,168,195,40,202,154,166,177,16,90,56,61,148,238,85,188,106,176,221,59,84,86,10,33,209,36,88,14,130,145,69,45,35,55,81,103,2,5,85,209,69,136,210,249,233,243,212,243,29,119,138,25,131,55,106,
91,55,229,37,27,143,74,1,166,162,74,149,45,170,244,94,138,120,85,121,33,41,113,119,170,161,234,166,22,145,241,73,137,114,206,56,161,218,177,110,159,82,121,69,117,4,225,212,199,45,211,114,241,239,25,78,
168,190,82,46,44,100,93,82,107,65,196,122,207,248,3,116,140,16,195,244,232,62,153,201,202,117,105,44,74,57,71,133,211,61,120,41,59,252,166,190,145,61,136,65,193,53,20,70,160,16,75,5,186,112,118,205,25,
193,136,124,20,17,36,131,67,40,233,40,219,80,56,187,217,136,156,226,70,236,20,238,82,103,145,89,123,244,234,72,207,75,123,229,204,212,128,232,75,152,252,150,120,56,86,94,26,10,194,119,136,117,36,215,117,
86,174,49,25,63,10,146,205,250,109,86,106,23,237,219,12,178,119,208,5,165,177,172,126,235,204,67,138,128,169,119,70,181,253,93,46,129,203,193,249,255,1,96,97,82,21,232,247,74,54,0,0,0,0,73,69,78,68,174,
66,96,130,0,0};

const char* MoorerReverbAudioProcessorEditor::pluginbkg_png = (const char*) resource_MoorerReverbAudioProcessorEditor_pluginbkg_png;
const int MoorerReverbAudioProcessorEditor::pluginbkg_pngSize = 36205;


//[EndFile] You can add extra defines here...
//[/EndFile]
