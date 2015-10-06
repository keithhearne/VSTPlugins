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
    //default values for plugin parameters, 3 second RT60 and 50% mix
    UserParams[MasterBypass] = 0.0f;
    UserParams[Mix] = 50.0f;
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
     //return the value of the parameter based on which indexed parameter is selected
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
    //set the parameter in the UI when user interacts and pass this
    //value back through to the underlying Delay classes left & right
    switch (index) {
        case MasterBypass:
            UserParams[MasterBypass] = newValue;
            sRevLeft.setBypass((bool)UserParams[MasterBypass]);
            sRevRight.setBypass((bool)UserParams[MasterBypass]);
            break;
        case Mix:
            UserParams[Mix] = newValue;
            break;
        case Decay:
            UserParams[Decay] = newValue;
            sRevLeft.setDecayFactor(UserParams[Decay]);
            sRevRight.setDecayFactor(UserParams[Decay]);
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

//  The I/O buffers are interleaved depending on the number of channels. If NumChannels = 2, then the
//	buffer is L/R/L/R/L/R etc...
void SchroederReverbAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    //if UI has bypass value then dont do any processing
    if(UserParams[MasterBypass])
            return;
            
    //THIS IS NUM SAMPLES PER CHANNEL        
    int numSamples = buffer.getNumSamples();
    
    // mix percentage coming from Mix UI parameter
    float mix = getParameter(Mix)/100;
    
    // audio processing...left and right channel inputs
    float* channelDataLeft = buffer.getSampleData(0);  //buffer.getSampleData(0);
    float* channelDataRight = buffer.getSampleData(1); 

    float outL=0.0f, outR=0.0f, outMatrixL=0.0f, outMatrixR=0.0f;
    
    //loop through the interleaved samples in increments of 2 
    for(int i = 0; i < numSamples; i+=2){
        float in = channelDataLeft[i], in_1 = channelDataRight[i+1];
        
        
        //here we have to create a mixing matrix as per Schroeders paper
        //  [ +1    +1 ]
        //  [ +1    -1 ]
        //  [ +1    +1 ]
        //  [ +1    -1 ]
        //
        //in the stereo version we tap the output of each filter seperately
        //so as wel can configure them in commutative fashion and extract
        //outputs to be summed
        
        //CIRCUIT IS : APF1 > APF2 > PARRALLEL COMBS 1-4 > SUMMING LEFT/RIGHT COMBS
        float apSummedLeft=0.0f, apSummedRight = 0.0f;
        float c1_l=0.0f, c2_l=0.0f, c3_l=0.0f, c4_l=0.0f, c1_r=0.0f, c2_r=0.0f, c3_r=0.0f, c4_r=0.0f;

        apSummedLeft = sRevLeft.getAllpassOutput(in,0);
        apSummedLeft += sRevLeft.getAllpassOutput(apSummedLeft,1);
        
        apSummedRight = sRevRight.getAllpassOutput(in_1,0);
        apSummedRight += sRevRight.getAllpassOutput(apSummedRight,1);
        
        c1_l = sRevLeft.getCombOutput(apSummedLeft*0.7,0);
        c1_r = sRevRight.getCombOutput(apSummedRight*0.7,0);

        c2_l = sRevLeft.getCombOutput(apSummedLeft*0.7,1);
        c2_r = sRevRight.getCombOutput(apSummedRight*-0.7,1);

        c3_l = sRevLeft.getCombOutput(apSummedLeft*0.7,2);
        c3_r = sRevRight.getCombOutput(apSummedRight*0.7,2);

        c4_l = sRevLeft.getCombOutput(apSummedLeft*0.7,3);
        c4_r = sRevRight.getCombOutput(apSummedRight*-0.7,3);

        //apply summing of individual comb ouputs
        outMatrixL = ((c1_l * 0.30f) - (c2_l * 0.30f) + (c3_l * 0.30f) - (c4_l * 0.30f));
        outMatrixR = ((c1_r * 0.30f) - (c2_r * 0.30f) + (c3_r * 0.30f) - (c4_r * 0.30f));
        
        //Scale outputs of left/right with the mix wet/dry ratio
        outL = mix * outMatrixL + (1.0f - mix) * in;
        outR = mix * outMatrixR + (1.0f - mix) * in_1;
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


void SchroederReverbAudioProcessor::processBlockBypassed (AudioSampleBuffer& buffer, MidiBuffer& midiMessages){
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
