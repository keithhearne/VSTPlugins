/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SchroederReverbAudioProcessor::SchroederReverbAudioProcessor()
{
    
    UserParams[MasterBypass] = 0.0f;
    UserParams[Mix] = 0.5f;
    UserParams[Decay] = 3.0f;

    UIUpdateFlag = true;
    
    
}

SchroederReverbAudioProcessor::~SchroederReverbAudioProcessor()
{
    
}

//==============================================================================
const String SchroederReverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int SchroederReverbAudioProcessor::getNumParameters()
{
    return NumParams;
}

float SchroederReverbAudioProcessor::getParameter (int index)
{
    switch (index) {
        case MasterBypass:
            return UserParams[MasterBypass];
        case Mix:
            return UserParams[Mix];
        case Decay:
            return UserParams[Decay];
        default:
            return 0.0f;
    }
}

void SchroederReverbAudioProcessor::setParameter (int index, float newValue)
{
    switch (index) {
        case MasterBypass:
            UserParams[MasterBypass] = newValue;
            sRev.setBypass((bool)UserParams[MasterBypass]);
            break;
        case Mix:
            UserParams[Mix] = newValue;
            break;
        case Decay:
            UserParams[Decay] = newValue;
            sRev.setDecayFactor(UserParams[Decay]);
            break;
        default:
            break;
    }
}

const String SchroederReverbAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case MasterBypass:
            return "MasterBypass";
        case Mix:
            return "Wet Signal";
        case Decay:
            return "Decay";
        default:
            return String::empty;
    }
}

const String SchroederReverbAudioProcessor::getParameterText (int index)
{
    if(index >= 0 && index < NumParams){
        return String(UserParams[index]);
    }
    else{
        return String::empty;
    }
}

const String SchroederReverbAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String SchroederReverbAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool SchroederReverbAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool SchroederReverbAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool SchroederReverbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SchroederReverbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SchroederReverbAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double SchroederReverbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SchroederReverbAudioProcessor::getNumPrograms()
{
    return 0;
}

int SchroederReverbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SchroederReverbAudioProcessor::setCurrentProgram (int index)
{
}

const String SchroederReverbAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void SchroederReverbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SchroederReverbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    //check for change in sample rate!!!
    // initialisation that you need..
   
}

void SchroederReverbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
}

void SchroederReverbAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    int numSamples = buffer.getNumSamples(); //THIS IS NUM SAMPLES PER CHANNEL
    float mix = getParameter(Mix);
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    float* channelDataLeft = buffer.getSampleData(0);  //buffer.getSampleData(0);
    float* channelDataRight = buffer.getSampleData(1); 

    /*
    for(int i = 0; i < numSamples; i++){
        float in = channelDataLeft[i], out=0.0f;
               
        out = mix * sRev.next(in) + (1.0f - mix) * in;                
        channelDataLeft[i] = out;
                
        //MONO-IN, Stereo Out
        if(getNumInputChannels() == 1 && getNumOutputChannels() == 2){
            channelDataRight[i] = channelDataLeft[i]; //copy mono
        }
                
        //Stereo In , Stereo Out
        if(getNumInputChannels() == 2 && getNumOutputChannels() == 2){
            channelDataRight[i] = channelDataLeft[i];
        }      
                    
    }
    */
    float outL=0.0f, outR=0.0f;
    
    for(int i = 0; i < numSamples; i+=2){
        float in = channelDataLeft[i], in_1 = channelDataRight[i+1];
        
        outL = mix * sRev.next(in) + (1.0f - mix) * in;
        outR = mix * sRev.next(in_1) + (1.0f - mix) * in_1;
        channelDataLeft[i] = outL;
        channelDataRight[i+1] = outR;
        
        //MONO-IN, Stereo Out
/*        if(getNumInputChannels() == 1 && getNumOutputChannels() == 2){
            channelDataRight[i] = channelDataLeft[i]; //copy mono
        }
        
        //Stereo In , Stereo Out
        if(getNumInputChannels() == 2 && getNumOutputChannels() == 2){
            channelDataRight[i] = channelDataLeft[i];
        }
  */
    }
    
    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
   
    
}


void SchroederReverbAudioProcessor::processBlockBypassed (AudioSampleBuffer& buffer, MidiBuffer& midiMessages){
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
bool SchroederReverbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SchroederReverbAudioProcessor::createEditor()
{
    return new SchroederReverbAudioProcessorEditor (this);
}

//==============================================================================
void SchroederReverbAudioProcessor::getStateInformation (MemoryBlock& destData)
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
    copyXmlToBinary(root, destData);
}

void SchroederReverbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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

        }
        delete pRoot;
    }
    UIUpdateFlag = true; //Request UI update
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SchroederReverbAudioProcessor();
}
