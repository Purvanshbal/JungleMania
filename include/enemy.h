#pragma once

#include "cinder/gl/gl.h"
#include "entity.h"




namespace junglemania {
using glm::vec2;
constexpr int kEnemyRadius = 20;
enum Direction {
  kForward,
  kBackward,
};

class Enemy : public Entity {
 public:
  /**
   * default constructor
   */
  Enemy();

  /**
   * Constructor that initializes the enemy using the specified top left and
   * bottom right vectors
   * @param position
   */
  Enemy(const glm::vec2& top_left, const glm::vec2& bottom_right);

  /**
   * Constructor that initializes the enemy using vectors and a direction object
   * @param top_left vector
   * @param bottom_right vector
   * @param direction the direction object
   */
  Enemy(const vec2& top_left, const vec2& bottom_right, Direction direction);

  /**
   * Draws the enemy using the entity class function
   */
  void Draw() const override;

  /**
   * Returns the direction of movement associated with the enemy object
   * @return direction_
   */
  Direction GetDirection();

  /**
   * Sets the direction of movement of the enemy object
   * @param direction
   */
  void SetDirection(Direction direction);

 private:
  Direction direction_;
};
}  // namespace junglemania