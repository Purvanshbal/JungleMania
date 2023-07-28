#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_engine.h"

namespace junglemania {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
class JungleManiaApp : public ci::app::App {
 public:
  JungleManiaApp();

  /**
   * Draws the simulation after every update
   */
  void draw() override;

  /**
   * Updates the simulation every second
   */
  void update() override;

  /**
   * Handles user input
   * @param event a keyboard click
   */
  void keyDown(cinder::app::KeyEvent event) override;

 private:
  GameEngine game_engine_;
};
}  // namespace junglemania