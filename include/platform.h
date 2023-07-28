#pragma once

#include "coin.h"
#include "entity.h"

namespace junglemania {
class Platform : public Entity {
 public:
  /**
   * Constructor to initialize the platform object using the top left
   * and bottom right coordinates and the color
   * @param top_left_corner the top left corner of the platform object
   * @param bottom_right_corner the bottom right corner of the platform object
   * @param color the color of the platform object
   */
  Platform(const glm::vec2& top_left, const glm::vec2 bottom_right);

  /**
   * Default constructor for the platform object
   */
  Platform();

  /**
   * Function to Draw the platform object
   */
  void Draw() const override;
};
}  // namespace junglemania