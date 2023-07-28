#pragma once

#include "cinder/gl/gl.h"
#include "entity.h"

using glm::vec2;
using std::vector;

namespace junglemania {
constexpr int power_up_width = 10;

class PowerUp : public Entity {
 public:
  /**
   * default constructor
   */
  PowerUp();

  /**
   * Constructor that initializes the coin using the specified top left and
   * bottom right vectors
   * @param position
   */
  PowerUp(const glm::vec2& top_left, const glm::vec2& bottom_right);

  /**
   * draws the coin
   */
  void Draw() const override;
};
}  // namespace junglemania
