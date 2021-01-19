#include "Gui.hpp"

// TODO: fix sliders positions and event handling

Gui::Gui()
    : wxFrame(nullptr, wxID_ANY, wxT("Oscillator"), wxDefaultPosition,
              wxSize(400, 400)) {
  wxPanel *panel = new wxPanel(this, wxID_ANY);
  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

  // wxBoxSizer *freq_box = new wxBoxSizer(wxHORIZONTAL);
  // wxBoxSizer *vol_box = new wxBoxSizer(wxHORIZONTAL);

  int initFreq = 440;

  // ? button as a class variable
  // wxButton *onOffButton = new wxButton(panel, BUTTON_ID, wxT("Play"));
  this->playButton = new wxButton(panel, BUTTON_ID, wxT("Play"));
  this->play = false;

  // Initialize sliders
  this->freq = new Slider(panel, wxT("Frequency"), FREQ_ID, initFreq, 50, 1000);
  // this->volume = new Slider(panel, wxT("Volume"), VOLUME_ID, 50, 0, 100);

  Connect(BUTTON_ID, wxEVT_COMMAND_BUTTON_CLICKED,
          wxCommandEventHandler(Gui::onButtonPress));
  Connect(FREQ_ID, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(Gui::onFreqChange));
  // Connect(VOLUME_ID, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(Gui::onVolChange));

  this->osc = new Oscillator(initFreq);

  // freq_box->Add(freq, 0);
  // vol_box->Add(volume, 0);

  vbox->Add(freq, 1,  wxALIGN_CENTER | wxALIGN_TOP | wxTOP | wxBOTTOM, 10);
  // vbox->Add(volume, 1, wxEXPAND | wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);
  // vbox->Add(onOffButton, 0, wxALIGN_CENTER | wxTOP | wxBottom, 20);
  vbox->Add(playButton, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 20);

  panel->SetSizer(vbox);

  Centre();
}

// ------- PRIVATE -------
void Gui::onFreqChange(wxScrollEvent &WXUNUSED(event)) {
  int value = freq->getValue();
  osc->setSineFreq(value);
  this->freq->updateTextValue(value);
}

void Gui::onVolChange(wxScrollEvent &WXUNUSED(event)) {
  int value = volume->getValue();
  this->volume->updateTextValue(value);
}

void Gui::onButtonPress(wxCommandEvent &WXUNUSED(event)) {
  if (play == true) {
    play = false;
    this->osc->stopStream();
  } else {
    play = true;
    this->osc->playStream();
  }
  std::cout << play << std::endl;
}