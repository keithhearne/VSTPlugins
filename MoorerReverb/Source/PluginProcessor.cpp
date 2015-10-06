/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MoorerReverbAudioProcessor::MoorerReverbAudioProcessor()
{
    //default values for plugin parameters, 50% mix, 3second RT60, and 
    //LPF cutoff frequency of 3800KHz
    UserParams[MasterBypass] = 0.0f;
    UserParams[Mix] = 50.0f;
    UserParams[Decay] = 3.0f;
    UserParams[LPF] = 3800.0f;

    UIUpdateFlag = true;
    
    
}

MoorerReverbAudioProcessor::~MoorerReverbAudioProcessor()
{
    
}

//==============================================================================
const String MoorerReverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int MoorerReverbAudioProcessor::getNumParameters()
{
    return NumParams;
}

float MoorerReverbAudioProcessor::getParameter (int index)
{
    //return the value of the parameter based on which indexed parameter is selected
    switch (index) {
        case MasterBypass:
            return UserParams[MasterBypass];
        case Mix:
            return UserParams[Mix];
        case Decay:
            return UserParams[Decay];    
        case LPF:
            return UserParams[LPF];             
        default:
            return 0.0f;
    }
}

void MoorerReverbAudioProcessor::setParameter (int index, float newValue)
{
    //set the parameter in the UI when user interacts and pass this
    //value back through to the underlying Moorer classes to update
    //parameters of the class
    switch (index) {
        case MasterBypass:
            UserParams[MasterBypass] = newValue;
            mRev.setBypass((bool)UserParams[MasterBypass]);
            break;
        case Mix:
            UserParams[Mix] = newValue;
            break;
        case Decay:
            UserParams[Decay] = newValue;
            mRev.setDecayFactor(UserParams[Decay]);
            break;     
        case LPF:
            UserParams[LPF] = newValue;
            mRev.setLPFreq(UserParams[LPF]);
            break;             
        default:
            break;
    }
}

const String MoorerReverbAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case MasterBypass:
            return "MasterBypass";
        case Mix:
            return "Wet Signal";
        case Decay:
            return "Decay";     
        case LPF:
            return "LPF";             
        default:
            return String::empty;
    }
}

const String MoorerReverbAudioProcessor::getParameterText (int index)
{
    if(index >= 0 && index < NumParams){
        return String(UserParams[index]);
    }
    else{
        return String::empty;
    }
}

const String MoorerReverbAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String MoorerReverbAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool MoorerReverbAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool MoorerReverbAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool MoorerReverbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MoorerReverbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MoorerReverbAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double MoorerReverbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MoorerReverbAudioProcessor::getNumPrograms()
{
    return 0;
}

int MoorerReverbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MoorerReverbAudioProcessor::setCurrentProgram (int index)
{
}

const String MoorerReverbAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void MoorerReverbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MoorerReverbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    //check for change in sample rate!!!
    // initialisation that you need..
   
}

void MoorerReverbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
}

//  The I/O buffers are interleaved depending on the number of channels. If NumChannels = 2, then the
//	buffer is L/R/L/R/L/R etc...
void MoorerReverbAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    int numSamples = buffer.getNumSamples(); //THIS IS NUM SAMPLES PER CHANNEL
    float mix = getParameter(Mix)/100;
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    float* channelDataLeft = buffer.getSampleData(0);  //buffer.getSampleData(0);
    float* channelDataRight = buffer.getSampleData(1); 

    float outL=0.0f, outR=0.0f;
    
    for(int i = 0; i < numSamples; i+=2){
        float in = channelDataLeft[i], in_1 = channelDataRight[i+1];
        
        //seperate out left and right channels
        outL = mix * mRev.next(in) + (1.0f - mix) * in;
        outR = mix * mRev.next(in_1) + (1.0f - mix) * in_1;
        
        channelDataLeft[i] = outL;
        
        //MONO-IN, Stereo Out
       if(getNumInputChannels() == 1 && getNumOutputChannels() == 2){
            channelDataRight[i+1] = channelDataLeft[i]; //copy mono
        }
        
        //Stereo In , Stereo Out
        if(getNumInputChannels() == 2 && getNumOutputChannels() == 2){
            channelDataRight[i+1] = outR;
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


void MoorerReverbAudioProcessor::processBlockBypassed (AudioSampleBuffer& buffer, MidiBuffer& midiMessages){
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
bool MoorerReverbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MoorerReverbAudioProcessor::createEditor()
{
    return new MoorerReverbAudioProcessorEditor (this);
}

//==============================================================================
void MoorerReverbAudioProcessor::getStateInformation (MemoryBlock& destData)
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
    el = root.createNewChildElement("Decay");
    el->addTextElement(String(UserParams[Decay]));    
    el = root.createNewChildElement("LPF");
    el->addTextElement(String(UserParams[LPF]));      
    copyXmlToBinary(root, destData);
}

void MoorerReverbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
            if(pChild->hasTagName("Decay")){
                String text = pChild->getAllSubText();
                setParameter(Decay, text.getFloatValue());
            }  
            if(pChild->hasTagName("LPF")){
                String text = pChild->getAllSubText();
                setParameter(LPF, text.getFloatValue());
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
    return new MoorerReverbAudioProcessor();
}
