#pragma once

#include <cstddef>

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/gl.h"
#include "door.h"
#include "enemy.h"
#include "platform.h"
#include "powerup.h"

namespace junglemania {
using glm::vec2;

class Layout {
 public:
  /**
   * Constructor to initialize a constructor
   * @param set_top_margin to set the top margin
   * @param set_bottom_margin to set the bottom margin
   * @param set_left_margin to set the left margin
   * @param set_right_margin to set the right margin
   */
  Layout(const glm::vec2& top_left_corner,
         const glm::vec2& bottom_right_corner);
  /**
   * Default Constructor
   */
  Layout();

  /**
   * Displays the container walls and the current positions of the particles.
   */
  void Display() const;

  /**
   * Gets the top left corner of the layout object
   * @return the top left corner of the layout
   */
  glm::vec2 GetTopLeftCorner() const;

  /**
   * Gets the bottom right corner of the layout object
   * @return the bottom right corner of the layout
   */
  glm::vec2 GetBottomRightCorner() const;

  /**
   * Returns the list of platform in the layout object
   * @return a vector of platforms
   */
  std::vector<Platform> GetPlatforms() const;

  /**
   * Returns the vector of coins in the layout
   * @return coins_
   */
  std::vector<Coin> GetCoins() const;

  /**
   * Updates the vector of coins in the layout
   * @param coins new vector of coins
   */
  void SetCoins(const std::vector<Coin>& coins);

  /**
   * Returns the vector of powerups in the layout
   * @return powerups_
   */
  std::vector<PowerUp> GetPowerUp() const;

  /**
   * Updates the vector of powerUps in the game
   * @param powerups the new vector of powerUps
   */
  void SetPowerUps(const std::vector<PowerUp>& powerups);

  /**
   * Returns the vector of enemies  in the layout
   * @return enemies_
   */
  std::vector<Enemy> GetEnemies() const;

  /**
   * Updates the vector of enemies in the layout
   * @param enemies  new vector of enemies
   */
  void SetEnemies(const std::vector<Enemy>& enemies);

  /**
   * Updates the vector of platforms in the layout
   * @param platforms new list of platforms
   */
  void SetPlatforms(const std::vector<Platform>& platforms);

  /**
   * Returns the exit platform of the layout object
   * @return the exit platform object
   */
  Door GetExitBlock() const;

  /**
   * Returns the start platform of the layout object
   * @return the start platform object
   */
  Door GetStartBlock() const;

  /**
   * Operator to load the layout from a file
   * @param is the instream
   * @param Layout object
   * @return empty stream
   */
  friend std::istream& operator>>(std::istream& is, Layout& Layout);

 private:
  std::vector<Platform> platforms_;
  std::vector<Coin> coins_;
  std::vector<PowerUp> powerUps_;
  std::vector<Enemy> enemies_;

  glm::vec2 top_left_corner_;
  glm::vec2 bottom_right_corner_;

  Door start_block_;
  Door exit_block_;
};
}  // namespace junglemania
