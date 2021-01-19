#include "main.hpp"
#include "Gui.hpp"

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  Gui *gui = new Gui();
  gui->Show(true);
  return true;
}