/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CrossStereoDelayAudioProcessor::CrossStereoDelayAudioProcessor()
{
    //default values for plugin parameters
    UserParams[MasterBypass] = 0.0f;
    UserParams[Mix] = 50.0f;
    UserParams[Delay] = 0.0f;
    UserParams[Feedback] = 0.0f;
    UserParams[CrossFeedback] = false;
    UIUpdateFlag = true;
    
    //by default do not use external feedback
    cDelay_Left.setUseExternalFeedback(false);
    cDelay_Right.setUseExternalFeedback(false);
    
}

CrossStereoDelayAudioProcessor::~CrossStereoDelayAudioProcessor()
{
    
}

//==============================================================================
const String CrossStereoDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int CrossStereoDelayAudioProcessor::getNumParameters()
{
    return NumParams;
}

float CrossStereoDelayAudioProcessor::getParameter (int index)
{
    //return the value of the parameter based on which indexed parameter is selected
    switch (index) {
        case MasterBypass:
            return UserParams[MasterBypass];
        case Mix:
            return UserParams[Mix];
        case Delay:
            return UserParams[Delay];
        case Feedback:
            return UserParams[Feedback];
        case CrossFeedback:
            return UserParams[CrossFeedback];    
        default:
            return 0.0f;
    }
}

void CrossStereoDelayAudioProcessor::setParameter (int index, float newValue)
{
    //set the parameter in the UI when user interacts and pass this
    //value back through to the underlying Delay classes left and right
    switch (index) {
        case MasterBypass:
            UserParams[MasterBypass] = newValue;
            cDelay_Left.setByPass((bool)UserParams[MasterBypass]);
            cDelay_Right.setByPass((bool)UserParams[MasterBypass]);
            break;
        case Mix:
            UserParams[Mix] = newValue;
            //Mix is received in value between 0 and 100
            cDelay_Left.setMix(UserParams[Mix]);
            cDelay_Right.setMix(UserParams[Mix]);
            break;
        case Delay:
            UserParams[Delay] = newValue;
            //delay is received in seconds between 0.00 and 2.00
            cDelay_Left.setDelay(UserParams[Delay]);
            cDelay_Right.setDelay(UserParams[Delay]);
            break;
        case Feedback:
            UserParams[Feedback] = newValue;
            //Feedback is received in -100 to +100
            cDelay_Left.setFeedback(UserParams[Feedback]);
            cDelay_Right.setFeedback(UserParams[Feedback]);
            break;
        case CrossFeedback:
            UserParams[CrossFeedback] = newValue;
            //CrossFeedback is either set or unset
            cDelay_Left.setCrossedFeedback(UserParams[CrossFeedback]);
            cDelay_Right.setCrossedFeedback(UserParams[CrossFeedback]);
            break;    
        default:
            break;
    }
    
}

const String CrossStereoDelayAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case MasterBypass:
            return "MasterBypass";
        case Mix:
            return "Mix";
        case Delay:
            return "Delay";
        case Feedback:
            return "Feedback";
        case CrossFeedback:
            return "Crossed Feedback";    
        default:
            return String::empty;
    }
}

const String CrossStereoDelayAudioProcessor::getParameterText (int index)
{
    if(index >= 0 && index < NumParams){
        return String(UserParams[index]);
    }
    else{
        return String::empty;
    }
}

const String CrossStereoDelayAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String CrossStereoDelayAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool CrossStereoDelayAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool CrossStereoDelayAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool CrossStereoDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CrossStereoDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CrossStereoDelayAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double CrossStereoDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CrossStereoDelayAudioProcessor::getNumPrograms()
{
    return 0;
}

int CrossStereoDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void CrossStereoDelayAudioProcessor::setCurrentProgram (int index)
{
}

const String CrossStereoDelayAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void CrossStereoDelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void CrossStereoDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    //check for change in sample rate!!!
    // initialisation that you need..
    cDelay_Left.resetBuffer();
    cDelay_Right.resetBuffer();
}

void CrossStereoDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
}

//  The I/O buffers are interleaved depending on the number of channels. If NumChannels = 2, then the
//	buffer is L/R/L/R/L/R etc...
void CrossStereoDelayAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    int numSamples = buffer.getNumSamples(); //THIS IS NUM SAMPLES PER CHANNEL
    
    // CROSS FB DELAY --- NOTE: MUST HAVE STEREO FILE! ------------------------- //

    float* channelDataLeft = buffer.getSampleData(0);  //buffer.getSampleData(0);
    float* channelDataRight = buffer.getSampleData(1); 


    for(int i = 0; i < numSamples; i+=2){
        float in = channelDataLeft[i], in_1 = channelDataRight[i+1], out=0.0f;
        
        //Crossed-Feedback Enabled, cross the feedback lines
        //If crossed then the currentFeedback Input for the left channel
        //becomes the Feedback output of the right channel and vice versa
        if(cDelay_Left.isCrossedFeedback())
        {
            cDelay_Left.setUseExternalFeedback(true);
            cDelay_Right.setUseExternalFeedback(true);
            cDelay_Left.setCurrentFeedbackInput(cDelay_Right.getCurrentFeedbackOutput());
            cDelay_Right.setCurrentFeedbackInput(cDelay_Left.getCurrentFeedbackOutput());
        }
        else{
            cDelay_Left.setUseExternalFeedback(false);
            cDelay_Right.setUseExternalFeedback(false);
        }
        
        out = cDelay_Left.next(in);                
        channelDataLeft[i] = out;
               
        
    
        //MONO-IN, Stereo Out
        if(getNumInputChannels() == 1 && getNumOutputChannels() == 2){
            channelDataRight[i+1] = channelDataLeft[i]; //copy mono
        }
                
        //Stereo In , Stereo Out
        if(getNumInputChannels() == 2 && getNumOutputChannels() == 2){
            channelDataRight[i+1] = cDelay_Right.next(in_1);
        }      
                    
    }
        
    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
        
}


void CrossStereoDelayAudioProcessor::processBlockBypassed (AudioSampleBuffer& buffer, MidiBuffer& midiMessages){
    int numSamples = buffer.getNumSamples(); //THIS IS NUM SAMPLES PER CHANNEL

    for(int channel = 0; channel < getNumInputChannels(); channel++){
        float* channelData = buffer.getSampleData(channel);
        for(int i = 0; i < numSamples; i++){
            channelData[i] = channelData[i];       
        }
    }
   
    return;
}

//==============================================================================
bool CrossStereoDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* CrossStereoDelayAudioProcessor::createEditor()
{
    return new CrossStereoDelayAudioProcessorEditor (this);
}

//==============================================================================
void CrossStereoDelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    XmlElement root("Root");
    XmlElement *el;
    el = root.createNewChildElement("MasterBypass");
    el->addTextElement(String(UserParams[MasterBypass]));
    el = root.createNewChildElement("Mix");
    el->addTextElement(String(UserParams[Mix]));
    el = root.createNewChildElement("Delay");
    el->addTextElement(String(UserParams[Delay]));
    el = root.createNewChildElement("Feedback");
    el->addTextElement(String(UserParams[Feedback]));
    el = root.createNewChildElement("CrossFeedback");
    el->addTextElement(String(UserParams[CrossFeedback]));    
    copyXmlToBinary(root, destData);
}

void CrossStereoDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    XmlElement *pRoot = getXmlFromBinary(data, sizeInBytes);
    if(pRoot != NULL){
        forEachXmlChildElement((*pRoot), pChild){
            if(pChild->hasTagName("MasterBypass")){
                String text = pChild->getAllSubText();
                setParameter(MasterBypass, text.getFloatValue());
            }
            if(pChild->hasTagName("Mix")){
                String text = pChild->getAllSubText();
                setParameter(Mix, text.getFloatValue());
            }
            if(pChild->hasTagName("Delay")){
                String text = pChild->getAllSubText();
                setParameter(Delay, text.getFloatValue());
            }
            if(pChild->hasTagName("Feedback")){
                String text = pChild->getAllSubText();
                setParameter(Feedback, text.getFloatValue());
            }
            if(pChild->hasTagName("CrossFeedback")){
                String text = pChild->getAllSubText();
                setParameter(CrossFeedback, text.getFloatValue());
            }
        }
        delete pRoot;
    }
    UIUpdateFlag = true; //Request UI update
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CrossStereoDelayAudioProcessor();
}
