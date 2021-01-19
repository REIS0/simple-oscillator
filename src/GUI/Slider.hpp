/*
  Events should be handled by the class that is creating the sliders.
*/

#include <wx/sizer.h>
#include <wx/wx.h>

// ? Slider as wxPanel instead of wxBoxSizer
// * wxPanel don't align as it should, but wxBoxSizer don't work well with slider

// class Slider : public wxBoxSizer {
class Slider : public wxPanel {
public:
  Slider(wxWindow *parent, const wxString &title, const int sliderID,
         int startValue, int minValue, int maxValue);
  int getValue();
  // * this should be private but idk why using the other way don't work
  void updateTextValue(int value);

private:
  wxSlider *slider;
  wxStaticText *s_value;
  wxStaticText *text;

  // void updateTextValue(wxScrollEvent &event);
};