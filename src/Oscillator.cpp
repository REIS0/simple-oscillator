#include "Oscillator.hpp"
#include <cstdio>
#include <iostream>
#include <stk/RtAudio.h>
#include <stk/SineWave.h>
#include <stk/Stk.h>

// !! workaround because the stk api don't like class methods
int play(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, unsigned int status, void *dataPointer);

Oscillator::Oscillator(int initFreq) {
  stk::Stk::setSampleRate(48000.0);
  RtAudio::StreamParameters parameters;

  parameters.deviceId = this->dac.getDefaultOutputDevice();
  parameters.nChannels = 1;
  RtAudioFormat format = RTAUDIO_FLOAT64;
  unsigned int bufferSize = stk::RT_BUFFER_SIZE;

  this->setSineFreq(initFreq);

  try {
    dac.openStream(&parameters, nullptr, format,
                   (unsigned int)stk::Stk::sampleRate(), &bufferSize, &play,
                   (void*)&this->sine);
  } catch (RtAudioError &error) {
    std::cerr << "Error creating Oscillator class." << std::endl;
    error.printMessage();
  }
}

// ------------- PUBLIC -------------
void Oscillator::setSineFreq(int freq) {
  this->sine.setFrequency((stk::StkFloat)freq);
}

void Oscillator::playStream() {
  try {
    this->dac.startStream();
  } catch (RtAudioError &error) {
    std::cerr << "Error starting the stream." << std::endl;
    error.printMessage();
  }
}

void Oscillator::stopStream() {
  try {
    this->dac.stopStream();
  } catch (RtAudioError &error) {
    std::cerr << "Error stoping the stream." << std::endl;
    error.printMessage();
  }
}

// ------------ PRIVATE ------------
// !! DON'T WORK, USE THE (ugly) WORKAROUND INSTEAD
// int Oscillator::play(void *outputBuffer, void *inputBuffer,
//                      unsigned int nBufferFrames, double streamTime,
//                      unsigned int status, void *dataPointer) {
//   stk::StkFloat *samples = (stk::StkFloat *)outputBuffer;

//   for (size_t i = 0; i < nBufferFrames; i++) {
//     *samples++ = this->sine.tick();
//   }
//   return 0;
// }

// ----------- OTHER --------------
// !! workaround because the stk api don't like class methods
int play(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, unsigned int status, void *dataPointer) {
  stk::SineWave *sine = (stk::SineWave *)dataPointer;
  stk::StkFloat *samples = (stk::StkFloat *)outputBuffer;

  for (unsigned int i = 0; i < nBufferFrames; i++) {
    *samples++ = sine->tick();
  }

  return 0;
}