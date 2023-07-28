#include "game_simulation_app.h"

using junglemania::JungleManiaApp;


void prepareSettings(JungleManiaApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(JungleManiaApp, ci::app::RendererGl, prepareSettings);
