#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;
using std::vector;

namespace junglemania {
/**
 * Enum that stores the possible collision among various entities
 */
enum CollisionResult {
  kNone,
  kTop,
  kBottom,
  kLeft,
  kRight,
};

// Class representing all objects except platforms in the game simulation.
// Will be inherited by all game objects
class Entity {
 public:
  /**
   * Default Constructor
   */
  Entity();

  /**
   * Constructor to initialize an entity object using top_left and bottom
   * right vectors
   * @param top_left top_left vector
   * @param bottom_right bottom right vector
   */
  Entity(const glm::vec2& top_left, const glm::vec2& bottom_right);

  /**
   * Function that sub-classes will override to Draw an entity
   */
  virtual void Draw() const;

  /**
   * Override destructor
   */
  virtual ~Entity();

  /**
   * Gets the approximate position of the entity object
   * @return the position of the entity object as glm::vec2
   */
  glm::vec2 GetPosition() const;

  /**
   * Returns the top_left_vector of the entity object
   * @return the top left corner as glm::vec2
   */
  glm::vec2 GetTopLeft() const;

  /**
   * Returns the bottom_right vector of the entity object
   * @return the bottom right corner as glm::vec2
   */
  glm::vec2 GetBottomRight() const;

  /**
   * Checks for collision between two entities.
   * Returns the edge of the other entity object that collides with this entity
   * object
   * @param other the other entity object
   * @return CollisionResult object from the enum depending on the type of
   * collision
   */
  CollisionResult DetectCollision(const Entity& other);

  /**
   * Operator to load an entity object from an instream
   * @param is the instream
   * @param entity the new entity object
   * @return empty stream
   */
  friend std::istream& operator>>(std::istream& is, Entity& entity);

 private:
 protected:
  glm::vec2 top_left_;
  glm::vec2 bottom_right_;
  glm::vec2 position_;
};

}  // namespace junglemania