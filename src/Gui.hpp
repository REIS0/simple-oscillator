#include <wx/wx.h>
#include "GUI/Slider.hpp"
#include "Oscillator.hpp"

const int BUTTON_ID = 101;
const int VOLUME_ID = 102;
const int FREQ_ID = 103;

class Gui : public wxFrame {
    public:
    Gui();
    private:
    Oscillator *osc;
    Slider *freq;
    Slider *volume;

    wxButton *playButton;
    bool play;

    void onFreqChange(wxScrollEvent &event);
    void onVolChange(wxScrollEvent &event);
    void onButtonPress(wxCommandEvent &event);
};