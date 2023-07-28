#pragma once

#include "cinder/gl/gl.h"
#include "entity.h"

namespace junglemania {
using glm::vec2;
class Door : public Entity {
 public:
  /**
   * default constructor
   */
  Door();

  /**
   * Constructor that initializes the enemy using the specified top left and
   * bottom right vectors
   * @param position
   */
  Door(const glm::vec2& top_left, const glm::vec2& bottom_right);

  /**
   * draws the enemy
   */
  void Draw() const override;
};
}  // namespace junglemania