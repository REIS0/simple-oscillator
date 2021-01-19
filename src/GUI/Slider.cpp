#include "Slider.hpp"
#include "wx/defs.h"

// ? Slider as wxPanel instead of wxBoxSizer

Slider::Slider(wxWindow *parent, const wxString &title, const int sliderID,
               int startValue, int minValue, int maxValue)
    // : wxBoxSizer(wxVERTICAL) {
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
              wxTAB_TRAVERSAL, wxT("Slider Panel")) {

  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

  this->text = new wxStaticText(parent, wxID_ANY, title);
  this->slider = new wxSlider(parent, sliderID, startValue, minValue, maxValue,
                              wxDefaultPosition, wxSize(200, -1),
                              wxSL_HORIZONTAL, wxDefaultValidator, title);
  this->s_value = new wxStaticText(parent, wxID_ANY,
                                   wxString::Format(wxT("%d"), startValue));

  // Connect(sliderID, wxEVT_COMMAND_SLIDER_UPDATED,
  // wxScrollEventHandler(Slider::updateTextValue));

  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
  hbox->Add(slider, 0);
  hbox->Add(s_value, 0);

  vbox->Add(text, 0, wxALIGN_CENTER | wxBOTTOM, 10);
  vbox->Add(hbox, 0, wxALIGN_CENTER | wxBOTTOM, 10);
  // this->Add(text, 0, wxBOTTOM, 2);
  // this->Add(hbox, 0, wxBOTTOM, 2);

  this->SetSizer(vbox);
}

// ----- PUBLIC ------
int Slider::getValue() { return this->slider->GetValue(); }

void Slider::updateTextValue(int value) {
  this->s_value->SetLabel(wxString::Format(wxT("%d"), value));
  Refresh();
}

// ----- PRIVATE -----
// void Slider::updateTextValue(wxScrollEvent &event) {
//   int value = this->slider->GetValue();
//   this->s_value->SetLabel(wxString::Format(wxT("%d"), value));
//   Refresh();
// }