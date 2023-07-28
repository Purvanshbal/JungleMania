#pragma once

#include "cinder/gl/gl.h"
#include "entity.h"

namespace junglemania {
using glm::vec2;
constexpr int kCoinWidth = 5;

class Coin : public Entity {
 public:
  /**
   * default constructor
   */
  Coin();

  /**
   * Constructor that initializes the coin using the specified top left and
   * bottom right vectors
   * @param position
   */
  Coin(const glm::vec2& top_left, const glm::vec2& bottom_right);

  /**
   * draws the coin
   */
  void Draw() const override;
};
}  // namespace junglemania