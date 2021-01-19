#include <stk/SineWave.h>
#include <stk/RtAudio.h>

// TODO: Create Processing.cpp and functions
// ! USING THE OSCILLATOR CLASS INSTEAD

class Processing {
public:
  Processing();
  void setSineFreq(float freq);
  void playStream();
  void stopStream();

private:
  stk::SineWave sine;
  RtAudio *dac;
};