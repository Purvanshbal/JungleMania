#include "game_simulation_app.h"

namespace junglemania {
JungleManiaApp::JungleManiaApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
  game_engine_ = GameEngine(1);
}

void JungleManiaApp::draw() {
  // Default initialization of the background
  ci::Color background_color("green");
  ci::gl::clear(background_color);
  game_engine_.Display();
}


void JungleManiaApp::keyDown(cinder::app::KeyEvent event) {
  if (event.getCode() == cinder::app::KeyEvent::KEY_RIGHT) {
    game_engine_.HandlePlayerMovement(kRightArrow);
  } else if (event.getCode() == cinder::app::KeyEvent::KEY_LEFT) {
    game_engine_.HandlePlayerMovement(kLeftArrow);
  } else if (event.getCode() == cinder::app::KeyEvent::KEY_UP){
    game_engine_.HandlePlayerMovement(kUpArrow);
  } else if (event.getCode() == cinder::app::KeyEvent::KEY_RETURN) {
    game_engine_.HandlePlayerMovement(kEnter);
  } else {
    game_engine_.HandlePlayerMovement(event.getChar());
  }
}

void JungleManiaApp::update() {
  if (!game_engine_.IsGameWon()) {
    game_engine_.AdvanceOneFrame();
  }
}

}