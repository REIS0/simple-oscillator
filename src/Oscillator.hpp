/*
  This class handles the audio stuff.
*/

#include <stk/RtAudio.h>
#include <stk/SineWave.h>


class Oscillator {
public:
  Oscillator(int initFreq);
  void setSineFreq(int freq);
  void playStream();
  void stopStream();

private:
  stk::SineWave sine;
  RtAudio dac;
  // callback function
  // int play(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
  //           double streamTime, RtAudioStreamStatus status, void *dataPointer);
};