/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <cmath>

//==============================================================================
SyncedTapDelayAudioProcessor::SyncedTapDelayAudioProcessor()
{
    //default values for plugin parameters
    UserParams[MasterBypass] = 0.0f;
    UserParams[Delay] = 0.0f;
    UserParams[Feedback] = 0.0f;
    UserParams[Mix] = 50.0f;
    UserParams[Tap1Delay] = 0;
    UserParams[Tap1Level] = 0.0f;
    UserParams[Tap2Delay] = 0;
    UserParams[Tap2Level] = 0.0f;
    UserParams[Tap3Delay] = 0;
    UserParams[Tap3Level] = 0.0f;
    UserParams[Tap4Delay] = 0;
    UserParams[Tap4Level] = 0.0f;
    UIUpdateFlag = true;
    //default host BPM to 120, default in most DAWs
    hostBPM = 120;
    
    //set the left and right delay lines to not use external feedback
    bDelay_Left.setUseExternalFeedback(false);
    bDelay_Right.setUseExternalFeedback(false);
    
}

SyncedTapDelayAudioProcessor::~SyncedTapDelayAudioProcessor()
{
    
}

//==============================================================================
const String SyncedTapDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int SyncedTapDelayAudioProcessor::getNumParameters()
{
    return NumParams;
}

float SyncedTapDelayAudioProcessor::getParameter (int index)
{
    //return the value of the parameter based on which indexed parameter is selected
    switch (index) {
        case MasterBypass:
            return UserParams[MasterBypass];
        case Delay:
            return UserParams[Delay];            
        case Feedback:
            return UserParams[Feedback];
        case Mix:
            return UserParams[Mix];
        case Tap1Delay:
            return UserParams[Tap1Delay];    
        case Tap2Delay:
            return UserParams[Tap2Delay];    
        case Tap3Delay:
            return UserParams[Tap3Delay];    
        case Tap4Delay:
            return UserParams[Tap4Delay];  
        case Tap1Level:
            return UserParams[Tap1Level];    
        case Tap2Level:
            return UserParams[Tap2Level];    
        case Tap3Level:
            return UserParams[Tap3Level];    
        case Tap4Level:
            return UserParams[Tap4Level];              
        default:
            return 0.0f;
    }
}

void SyncedTapDelayAudioProcessor::setParameter (int index, float newValue)
{
    //set the parameter in the UI when user interacts and pass this
    //value back through to the underlying Delay classes left and right
    switch (index) {
        case MasterBypass:
            UserParams[MasterBypass] = newValue;
            bDelay_Left.setByPass((bool)UserParams[MasterBypass]);
            bDelay_Right.setByPass((bool)UserParams[MasterBypass]);
            break;
        case Delay:
            UserParams[Delay] = newValue;
            //Delay between 0 and 2.00 (multiply by 1000 for ms)
            bDelay_Left.setDelay(UserParams[Delay]*1000);
            bDelay_Right.setDelay(UserParams[Delay]*1000);
            break;            
        case Feedback:
            UserParams[Feedback] = newValue;
            //Feedback is received in -100 to +100
            bDelay_Left.setFeedback(UserParams[Feedback]);
            bDelay_Right.setFeedback(UserParams[Feedback]);
            break;
        case Mix:
            UserParams[Mix] = newValue;
            //Mix is received in value between 0 and 100
            bDelay_Left.setMix(UserParams[Mix]);
            bDelay_Right.setMix(UserParams[Mix]);
            break;            
        case Tap1Delay:
            UserParams[Tap1Delay] = newValue;
            //calculate the tap delays based on host bpm and tap
            //note values
            bDelay_Left.setTap1Delay(calculateDelayTap(newValue));
            bDelay_Right.setTap1Delay(calculateDelayTap(newValue));
            break;
        case Tap2Delay:
            UserParams[Tap2Delay] = newValue;
            //calculate the tap delays based on host bpm and tap
            //note values
            bDelay_Left.setTap2Delay(calculateDelayTap(newValue));
            bDelay_Right.setTap2Delay(calculateDelayTap(newValue));
            break;  
        case Tap3Delay:
            UserParams[Tap3Delay] = newValue;
            //calculate the tap delays based on host bpm and tap
            //note values
            bDelay_Left.setTap3Delay(calculateDelayTap(newValue));
            bDelay_Right.setTap3Delay(calculateDelayTap(newValue));
            break;  
        case Tap4Delay:
            UserParams[Tap4Delay] = newValue;
            //calculate the tap delays based on host bpm and tap
            //note values
            bDelay_Left.setTap4Delay(calculateDelayTap(newValue));
            bDelay_Right.setTap4Delay(calculateDelayTap(newValue));
            break;
        case Tap1Level:
            UserParams[Tap1Level] = newValue;
            bDelay_Left.setTap1Level(UserParams[Tap1Level]);
            bDelay_Right.setTap1Level(UserParams[Tap1Level]);
            break; 
        case Tap2Level:
            UserParams[Tap2Level] = newValue;
            bDelay_Left.setTap2Level(UserParams[Tap2Level]);
            bDelay_Right.setTap2Level(UserParams[Tap2Level]);
            break; 
        case Tap3Level:
            UserParams[Tap3Level] = newValue;
            bDelay_Left.setTap3Level(UserParams[Tap3Level]);
            bDelay_Right.setTap3Level(UserParams[Tap3Level]);
            break; 
        case Tap4Level:
            UserParams[Tap4Level] = newValue;
            bDelay_Left.setTap4Level(UserParams[Tap4Level]);
            bDelay_Right.setTap4Level(UserParams[Tap4Level]);
            break;             
            
        default:
            break;
    }
}

const String SyncedTapDelayAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case MasterBypass:
            return "MasterBypass";
        case Delay:
            return "Delay";            
        case Feedback:
            return "Feedback";
        case Mix:
            return "Mix";            
        case Tap1Delay:
            return "Tap1Delay";          
        case Tap2Delay:
            return "Tap2Delay";          
        case Tap3Delay:
            return "Tap3Delay";          
        case Tap4Delay:
            return "Tap4Delay"; 
        case Tap1Level:
            return "Tap1Level"; 
        case Tap2Level:
            return "Tap2Level";
        case Tap3Level:
            return "Tap3Level";
        case Tap4Level:
            return "Tap4Level";             
        default:
            return String::empty;
    }
}

const String SyncedTapDelayAudioProcessor::getParameterText (int index)
{
    if(index >= 0 && index < NumParams){
        return String(UserParams[index]);
    }
    else{
        return String::empty;
    }
}

const String SyncedTapDelayAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String SyncedTapDelayAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool SyncedTapDelayAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool SyncedTapDelayAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool SyncedTapDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SyncedTapDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SyncedTapDelayAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double SyncedTapDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SyncedTapDelayAudioProcessor::getNumPrograms()
{
    return 0;
}

int SyncedTapDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SyncedTapDelayAudioProcessor::setCurrentProgram (int index)
{
}

const String SyncedTapDelayAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void SyncedTapDelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SyncedTapDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    //check for change in sample rate!!!
    // initialisation that you need..
    //bDelay_Left.resetBuffer();
    //bDelay_Right.resetBuffer();
}

void SyncedTapDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
}

//  The I/O buffers are interleaved depending on the number of channels. If NumChannels = 2, then the
//	buffer is L/R/L/R/L/R etc...
void SyncedTapDelayAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    //get the host BPM and sync playhead to it
    juce::AudioPlayHead::CurrentPositionInfo result;
    juce::AudioPlayHead* jap = getPlayHead();
    jap->getCurrentPosition(result);
    this->hostBPM = result.bpm;
    /*
    // for bpm calculations...
    //  60/bpm equals is 1/4 note
    //  1/4 note halved is 1/8
    //  1/8 note halved is 1/16th
    //  a dotted 1/8th note is 3/16ths so 3 x 1/16th note
    float qNote = 60/dBpm;
    float eNote = qNote/2;
    float sNote = eNote/2;
    bDelay_Left.setDelaySync(qNote, eNote,sNote);
    bDelay_Right.setDelaySync(qNote, eNote,sNote);
     */
    
    int numSamples = buffer.getNumSamples(); //THIS IS NUM SAMPLES PER CHANNEL
       
    float* channelDataLeft = buffer.getSampleData(0);  //buffer.getSampleData(0);
    float* channelDataRight = buffer.getSampleData(1); 

    for(int i = 0; i < numSamples; i+=2){
        //float in = channelDataLeft[i], in_1 = channelDataRight[i], out=0.0f;
        float in = channelDataLeft[i], in_1 = channelDataRight[i+1], out=0.0f;
                 
        out = bDelay_Left.next(in);                
        channelDataLeft[i] = out;
        
        //MONO-IN, Stereo Out
        if(getNumInputChannels() == 1 && getNumOutputChannels() == 2){
            channelDataRight[i+1] = channelDataLeft[i]; //copy mono
        }
                
        //Stereo In , Stereo Out
        if(getNumInputChannels() == 2 && getNumOutputChannels() == 2){
            channelDataRight[i+1] = bDelay_Right.next(in_1);
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


void SyncedTapDelayAudioProcessor::processBlockBypassed (AudioSampleBuffer& buffer, MidiBuffer& midiMessages){
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
bool SyncedTapDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SyncedTapDelayAudioProcessor::createEditor()
{
    return new SyncedTapDelayAudioProcessorEditor (this);
}

//==============================================================================
void SyncedTapDelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    XmlElement root("Root");
    XmlElement *el;
    el = root.createNewChildElement("MasterBypass");
    el->addTextElement(String(UserParams[MasterBypass]));
    el = root.createNewChildElement("Delay");
    el->addTextElement(String(UserParams[Delay]));    
    el = root.createNewChildElement("Feedback");
    el->addTextElement(String(UserParams[Feedback]));
    el = root.createNewChildElement("Mix");
    el->addTextElement(String(UserParams[Mix]));    
    el = root.createNewChildElement("Tap1Delay");
    el->addTextElement(String(UserParams[Tap1Delay]));
    el = root.createNewChildElement("Tap1Level");
    el->addTextElement(String(UserParams[Tap1Level])); 
    el = root.createNewChildElement("Tap2Delay");
    el->addTextElement(String(UserParams[Tap2Delay]));
    el = root.createNewChildElement("Tap2Level");
    el->addTextElement(String(UserParams[Tap2Level])); 
    el = root.createNewChildElement("Tap3Delay");
    el->addTextElement(String(UserParams[Tap3Delay]));
    el = root.createNewChildElement("Tap4Delay");
    el->addTextElement(String(UserParams[Tap4Delay]));     
    el = root.createNewChildElement("Tap4Level");
    el->addTextElement(String(UserParams[Tap4Level]));     
    copyXmlToBinary(root, destData);
}

void SyncedTapDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
            if(pChild->hasTagName("Delay")){
                String text = pChild->getAllSubText();
                setParameter(Delay, text.getFloatValue());
            }            
            if(pChild->hasTagName("Feedback")){
                String text = pChild->getAllSubText();
                setParameter(Feedback, text.getFloatValue());
            }
            if(pChild->hasTagName("Mix")){
                String text = pChild->getAllSubText();
                setParameter(Mix, text.getFloatValue());
            }            
            if(pChild->hasTagName("Tap1Delay")){
                String text = pChild->getAllSubText();
                setParameter(Tap1Delay, text.getFloatValue());
            }
            if(pChild->hasTagName("Tap1Level")){
                String text = pChild->getAllSubText();
                setParameter(Tap1Level, text.getFloatValue());
            }
            if(pChild->hasTagName("Tap2Delay")){
                String text = pChild->getAllSubText();
                setParameter(Tap2Delay, text.getFloatValue());
            }
            if(pChild->hasTagName("Tap2Level")){
                String text = pChild->getAllSubText();
                setParameter(Tap2Level, text.getFloatValue());
            }
            if(pChild->hasTagName("Tap3Delay")){
                String text = pChild->getAllSubText();
                setParameter(Tap3Delay, text.getFloatValue());
            }
            if(pChild->hasTagName("Tap3Level")){
                String text = pChild->getAllSubText();
                setParameter(Tap3Level, text.getFloatValue());
            }
            if(pChild->hasTagName("Tap4Delay")){
                String text = pChild->getAllSubText();
                setParameter(Tap4Delay, text.getFloatValue());
            }
            if(pChild->hasTagName("Tap4Level")){
                String text = pChild->getAllSubText();
                setParameter(Tap4Level, text.getFloatValue());
            }            
        }
        delete pRoot;
    }
    UIUpdateFlag = true; //Request UI update
}

//-------------------------------------------------------------------------
// calculateDelayTap
//
// function that calculates the Tap for given note values
// 1 = 1/2 note
// 2 = 1/4 note
// 3 = 1/8 note
// 4 = 1/16 note
// then sends the result back
//-------------------------------------------------------------------------
float SyncedTapDelayAudioProcessor::calculateDelayTap(int tap)
{
    float tmp;
    float bpm;
    bpm = this->hostBPM;
    
    if(tap == 0){
        tmp = 0;
    }
    else if(tap == 1){
        tmp = (120/bpm)*1000;
    }
    else if(tap == 2){
        tmp = (60/bpm)*1000;
    }
    else if(tap == 3){
        tmp = (30/bpm)*1000;
    }
    else if(tap == 4){
        tmp = (15/bpm)*1000;
    }
    float result = tmp;
    
    return result;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SyncedTapDelayAudioProcessor();
}
