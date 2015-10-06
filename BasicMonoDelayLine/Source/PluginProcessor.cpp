/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicDelayAudioProcessor::BasicDelayAudioProcessor()
{
    //default values for plugin parameters
    UserParams[MasterBypass] = 0.0f;
    UserParams[Mix] = 50.0f;
    UserParams[Delay] = 0.0f;
    UserParams[Feedback] = 0.0f;
    UIUpdateFlag = true;
    
    
}

BasicDelayAudioProcessor::~BasicDelayAudioProcessor()
{
    
}

//==============================================================================
const String BasicDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int BasicDelayAudioProcessor::getNumParameters()
{
    return NumParams;
}

float BasicDelayAudioProcessor::getParameter (int index)
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
        default:
            return 0.0f;
    }
}

void BasicDelayAudioProcessor::setParameter (int index, float newValue)
{
    //set the parameter in the UI when user interacts and pass this
    //value back through to the underlying Delay class
    switch (index) {
        case MasterBypass:
            UserParams[MasterBypass] = newValue;
            bDelay.setByPass((bool)UserParams[MasterBypass]);
            break;
        case Mix:
            UserParams[Mix] = newValue;
            //Mix is received in value between 0 and 100
            bDelay.setMix(UserParams[Mix]);
            break;
        case Delay:
            UserParams[Delay] = newValue;
            //delay is received in seconds between 0.00 and 2.00
            bDelay.setDelay(UserParams[Delay]);
            break;
        case Feedback:
            UserParams[Feedback] = newValue;
            //Feedback is received in -100 to +100
            bDelay.setFeedback(UserParams[Feedback]);
            break;
        default:
            break;
    }
    
}

const String BasicDelayAudioProcessor::getParameterName (int index)
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
        default:
            return String::empty;
    }
}

const String BasicDelayAudioProcessor::getParameterText (int index)
{
    if(index >= 0 && index < NumParams){
        return String(UserParams[index]);
    }
    else{
        return String::empty;
    }
}

const String BasicDelayAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String BasicDelayAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool BasicDelayAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool BasicDelayAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool BasicDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool BasicDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool BasicDelayAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double BasicDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BasicDelayAudioProcessor::getNumPrograms()
{
    return 0;
}

int BasicDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void BasicDelayAudioProcessor::setCurrentProgram (int index)
{
}

const String BasicDelayAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void BasicDelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void BasicDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    //check for change in sample rate!!!
    // initialisation that you need..
    bDelay.resetBuffer();
}

void BasicDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
}

void BasicDelayAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    int numSamples = buffer.getNumSamples(); //THIS IS NUM SAMPLES PER CHANNEL

    float* channelDataLeft = buffer.getSampleData(0); 
    float* channelDataRight = buffer.getSampleData(1);
        
    for(int i = 0; i < numSamples; i++){
        float in = channelDataLeft[i], out = 0.0f;
                
        out = bDelay.next(in);
        channelDataLeft[i] = out;
            
        //MONO-IN, Stereo Out
        if(getNumInputChannels() == 1 && getNumOutputChannels() == 2){
            channelDataRight[i] = channelDataLeft[i]; //copy mono
        }
            
        //MONO EFFECT
        //Stereo In , Stereo Out
        if(getNumInputChannels() == 2 && getNumOutputChannels() == 2){
            channelDataRight[i] = channelDataLeft[i]; //copy mono
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


void BasicDelayAudioProcessor::processBlockBypassed (AudioSampleBuffer& buffer, MidiBuffer& midiMessages){
    int numSamples = buffer.getNumSamples(); //THIS IS NUM SAMPLES PER CHANNEL

    for(int channel = 0; channel < getNumInputChannels(); channel++){
        float* channelData = buffer.getSampleData(channel);
        for(int i = 0; i < numSamples; i++){
            //float in = channelData[i], out = 0.0f;
            //out = in;
            channelData[i] = channelData[i];
            
        }
    }
   
    return;
}

//==============================================================================
bool BasicDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* BasicDelayAudioProcessor::createEditor()
{
    return new BasicDelayAudioProcessorEditor (this);
}

//==============================================================================
void BasicDelayAudioProcessor::getStateInformation (MemoryBlock& destData)
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
    copyXmlToBinary(root, destData);
}

void BasicDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
        }
        delete pRoot;
    }
    UIUpdateFlag = true; //Request UI update
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BasicDelayAudioProcessor();
}
