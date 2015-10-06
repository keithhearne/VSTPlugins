/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PingPongDelayAudioProcessor::PingPongDelayAudioProcessor()
{
    //default values for plugin parameters
    UserParams[MasterBypass] = 0.0f;
    UserParams[Mix] = 50.0f;
    UserParams[Delay] = 0.0f;
    UserParams[Feedback] = 0.0f;
    UIUpdateFlag = true;
    
    //by default use external feedback
    ppDelay_Left.setUseExternalFeedback(true);
    ppDelay_Right.setUseExternalFeedback(true);
    
}

PingPongDelayAudioProcessor::~PingPongDelayAudioProcessor()
{
    
}

//==============================================================================
const String PingPongDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int PingPongDelayAudioProcessor::getNumParameters()
{
    return NumParams;
}

float PingPongDelayAudioProcessor::getParameter (int index)
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

void PingPongDelayAudioProcessor::setParameter (int index, float newValue)
{
    //set the parameter in the UI when user interacts and pass this
    //value back through to the underlying Delay classes left and right
    switch (index) {
        case MasterBypass:
            UserParams[MasterBypass] = newValue;
            ppDelay_Left.setByPass((bool)UserParams[MasterBypass]);
            ppDelay_Right.setByPass((bool)UserParams[MasterBypass]);
            break;
        case Mix:
            UserParams[Mix] = newValue;
            //Mix is received in value between 0 and 100
            ppDelay_Left.setMix(UserParams[Mix]);
            ppDelay_Right.setMix(UserParams[Mix]);
            break;
        case Delay:
            UserParams[Delay] = newValue;
            //delay is received in seconds between 0.00 and 2.00
            ppDelay_Left.setDelay(UserParams[Delay]);
            ppDelay_Right.setDelay(UserParams[Delay]);
            break;
        case Feedback:
            UserParams[Feedback] = newValue;
            //Feedback is received in -100 to +100
            ppDelay_Left.setFeedback(UserParams[Feedback]);
            ppDelay_Right.setFeedback(UserParams[Feedback]);
            break;   
        default:
            break;
    }
    //std::cout << "updating param " << index << ": " << newValue << std::endl;
}

const String PingPongDelayAudioProcessor::getParameterName (int index)
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

const String PingPongDelayAudioProcessor::getParameterText (int index)
{
    if(index >= 0 && index < NumParams){
        return String(UserParams[index]);
    }
    else{
        return String::empty;
    }
}

const String PingPongDelayAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String PingPongDelayAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool PingPongDelayAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool PingPongDelayAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool PingPongDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PingPongDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PingPongDelayAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double PingPongDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PingPongDelayAudioProcessor::getNumPrograms()
{
    return 0;
}

int PingPongDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PingPongDelayAudioProcessor::setCurrentProgram (int index)
{
}

const String PingPongDelayAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void PingPongDelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PingPongDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    //check for change in sample rate!!!
    // initialisation that you need..
    ppDelay_Left.resetBuffer();
    ppDelay_Right.resetBuffer();
}

void PingPongDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
}

//  The I/O buffers are interleaved depending on the number of channels. If NumChannels = 2, then the
//	buffer is L/R/L/R/L/R etc...
void PingPongDelayAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    int numSamples = buffer.getNumSamples(); //THIS IS NUM SAMPLES PER CHANNEL
    
    // DELAY --- NOTE: MUST HAVE STEREO FILE! ------------------------- //
    float* channelDataLeft = buffer.getSampleData(0);  //buffer.getSampleData(0);
    float* channelDataRight = buffer.getSampleData(1); 


    ppDelay_Left.setUseExternalFeedback(true);
    ppDelay_Right.setUseExternalFeedback(true);
    
    //cross the feedback loops
    ppDelay_Left.setCurrentFeedbackInput(ppDelay_Right.getCurrentFeedbackOutput());
    ppDelay_Right.setCurrentFeedbackInput(ppDelay_Left.getCurrentFeedbackOutput());
      

    float storedOut=0.0f;
    
    for(int i = 0; i < numSamples; i+2){
        float in_Left = channelDataLeft[i], in_Right = channelDataRight[i+1], outLeft=0.0f, outRight=0.0f;
        
        //cycle the delays back and forth for
        //set feedback paths and cycle delays back and forth
        ppDelay_Left.setCurrentFeedbackInput(ppDelay_Right.getCurrentFeedbackOutput());
        ppDelay_Right.setCurrentFeedbackInput(ppDelay_Left.getCurrentFeedbackOutput());
        outRight = ppDelay_Right.next(in_Left);
        outLeft = ppDelay_Left.next(in_Right);
         
        channelDataLeft[i] = outLeft;
        
        //MONO-IN, Stereo Out
        
        if(getNumInputChannels() == 1 && getNumOutputChannels() == 2){
            channelDataRight[i+1] = channelDataLeft[i]; //copy mono
        }
        
                
        //Stereo In , Stereo Out
        if(getNumInputChannels() == 2 && getNumOutputChannels() == 2){
            channelDataRight[i+1] = outRight;
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


void PingPongDelayAudioProcessor::processBlockBypassed (AudioSampleBuffer& buffer, MidiBuffer& midiMessages){
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
bool PingPongDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PingPongDelayAudioProcessor::createEditor()
{
    return new PingPongDelayAudioProcessorEditor (this);
}

//==============================================================================
void PingPongDelayAudioProcessor::getStateInformation (MemoryBlock& destData)
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

void PingPongDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
    return new PingPongDelayAudioProcessor();
}
