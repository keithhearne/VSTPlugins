/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
StereoDelayAudioProcessor::StereoDelayAudioProcessor()
{
    //default values for plugin parameters
    UserParams[MasterBypass] = 0.0f;
    UserParams[Mix] = 50.0f;
    UserParams[Delay] = 0.0f;
    UserParams[Feedback] = 0.0f;
    UIUpdateFlag = true;
    
    //set the left and right feedbacks to be internal not crossed
    bDelay_Left.setUseExternalFeedback(false);
    bDelay_Right.setUseExternalFeedback(false);
    
}

StereoDelayAudioProcessor::~StereoDelayAudioProcessor()
{
    
}

//==============================================================================
const String StereoDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int StereoDelayAudioProcessor::getNumParameters()
{
    return NumParams;
}

float StereoDelayAudioProcessor::getParameter (int index)
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

void StereoDelayAudioProcessor::setParameter (int index, float newValue)
{
    //set the parameter in the UI when user interacts and pass this
    //value back through to the underlying Delay classes left & right
    switch (index) {
        case MasterBypass:
            UserParams[MasterBypass] = newValue;
            bDelay_Left.setByPass((bool)UserParams[MasterBypass]);
            bDelay_Right.setByPass((bool)UserParams[MasterBypass]);
            break;
        case Mix:
            UserParams[Mix] = newValue;
            //Mix is received in value between 0 and 100
            bDelay_Left.setMix(UserParams[Mix]);
            bDelay_Right.setMix(UserParams[Mix]);
            break;
        case Delay:
            UserParams[Delay] = newValue;
            //delay is received in seconds between 0.00 and 2.00
            bDelay_Left.setDelay(UserParams[Delay]);
            bDelay_Right.setDelay(UserParams[Delay]);
            break;
        case Feedback:
            UserParams[Feedback] = newValue;
            //Feedback is received in -100 to +100
            bDelay_Left.setFeedback(UserParams[Feedback]);
            bDelay_Right.setFeedback(UserParams[Feedback]);
            break;
        default:
            break;
    }

}

const String StereoDelayAudioProcessor::getParameterName (int index)
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

const String StereoDelayAudioProcessor::getParameterText (int index)
{
    if(index >= 0 && index < NumParams){
        return String(UserParams[index]);
    }
    else{
        return String::empty;
    }
}

const String StereoDelayAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String StereoDelayAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool StereoDelayAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool StereoDelayAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool StereoDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool StereoDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool StereoDelayAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double StereoDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int StereoDelayAudioProcessor::getNumPrograms()
{
    return 0;
}

int StereoDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void StereoDelayAudioProcessor::setCurrentProgram (int index)
{
}

const String StereoDelayAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void StereoDelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void StereoDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    //check for change in sample rate!!!
    // initialisation that you need..
    bDelay_Left.resetBuffer();
    bDelay_Right.resetBuffer();
}

void StereoDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//  ProcessBlock : Process Audiobuffer containing sample info for current block
//  
//  if mono input : copy input to both left and right channels
//  if stereo input : process seperate left and right channels
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
void StereoDelayAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    //THIS IS NUM SAMPLES PER CHANNEL
    int numSamples = buffer.getNumSamples(); //THIS IS NUM SAMPLES PER CHANNEL

    //Left and Right channels for stereo input, mono input just channel 0
    float* channelDataLeft = buffer.getSampleData(0);
    float* channelDataRight = buffer.getSampleData(1); 

    //for each sample in the audio buffer process the output
    for(int i = 0; i < numSamples; i++){
        float in = channelDataLeft[i], in_1 = channelDataRight[i], out=0.0f;
        
        //pass the samples value to the Basic Delay Line for processing
        //we have a bDelay_Left and a bDelay_Right for stereo image
        out = bDelay_Left.next(in);                
        channelDataLeft[i] = out;
                
        //MONO-IN, Stereo Out
        if(getNumInputChannels() == 1 && getNumOutputChannels() == 2){
            channelDataRight[i] = channelDataLeft[i]; //copy mono
        }
                
        //Stereo In , Stereo Out
        if(getNumInputChannels() == 2 && getNumOutputChannels() == 2){
            channelDataRight[i] = bDelay_Right.next(in_1);
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


void StereoDelayAudioProcessor::processBlockBypassed (AudioSampleBuffer& buffer, MidiBuffer& midiMessages){
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
bool StereoDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* StereoDelayAudioProcessor::createEditor()
{
    return new StereoDelayAudioProcessorEditor (this);
}

//==============================================================================
void StereoDelayAudioProcessor::getStateInformation (MemoryBlock& destData)
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

void StereoDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
    return new StereoDelayAudioProcessor();
}
