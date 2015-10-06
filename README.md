# VSTPlugins
A number of VST plugins developed using the JUCE framework and C++ in Xcode.

The following VST plugins were coded as part of a final project for Bachelors Degree in Audio Production.
The focus of the project was reviewing the earliest designs of digital reverb from Schroeder and Moorer.

The intention was to produce some of these early designs in VST format by stripping the designs back to first principles and using 
an iterative approach. The VSTs presented in this repository can be considered building blocks with each building on previous designs in 
order to produce the Schroeder and Moorer reverbs.

This design approach is reflected historically in the adaptations of reverberation since the 1960’s.
The main designs are Schroeder and Moorer designs from their respective seminal papers from 1962 and 1979. 
Since these early reverb designs were predominantly based around delay lines, the following features a number
of delay implementations that contain design aspects of the Schroeder Reverb.

Assumptions for development:
* Plugin design and framework created using the JUCE framework available at: [JUCE] (http://www.juce.com/)
* The Steinberg VST 3 SDK is needed in order to build these, the path to this will need to be adjusted in each of the .jucer files
* Subsequent implementation and DSP programmed in Xcode using C++
* all sample rates fixed at 44.1KHz.
* all VSTs are 32bit versions
* stereo versions designed for stereo interleaved format

The order of VSTs in the design approach is :

1. Simple Mono Delay (BasicMonDelayLine)
2. Stereo Delay (StereoDelayLine)
3. Synced Tap Delay (SyncedTapDelayLine)
4. Crossed Feedback Delay (CrossStereoDelayLine)
5. Ping Pond Delay (PingPonDelayLine)
6. Mono Schroeder Reverb (SchroederReverb)
7. Stereo Schroeder Reverb (SchroederReverbStereo)
8. Mono Moorer Reverb (MoorerReverb)
9. Stereo Moorer Reverb (MoorerReverbStereo)


Acknowledgements:

The following sources were used extensively in referencing design and development steps for this project

Manfred R. Schroeder (1962), Natural-sounding artificial reverberation, Journal of the Audio Engineering Society, vol. 10, no. 3, pp. 219-223. [ONLINE] Available at: http://www.ece.rochester.edu/~zduan/teaching/ece472/reading/Schroeder_1962.pdf. 

James A. Moorer, (1979), About This Reverberation Business, Computer Music Journal, vol. 3, no. 2, MIT Press [ONLINE] Available at: http://www.music.mcgill.ca/~gary/courses/papers/Moorer-Reverb-CMJ-1979.pdf.

Richard Boulanger, 2000. The Csound Book: Perspectives in Software Synthesis, Sound Design, Signal Processing,and Programming. Edition. The MIT Press.

Will Pirkle (2012), Designing Audio Effect Plug-Ins in C++: With Digital Audio Signal Processing Theory. 1 Edition. Focal Press.

Steven W. Smith, (1997), The Scientist & Engineer's Guide to Digital Signal Processing. 1st Edition. California Technical Pub.



