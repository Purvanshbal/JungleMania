#pragma once

#include "coin.h"
#include "entity.h"
#include "platform.h"

namespace junglemania {
constexpr int kPlayerRadius = 20;
constexpr int kMaxHealth = 100;
class Player : public Entity {
 private:
  static constexpr int kMoveConstant = 10;
  static constexpr float kGravityConstant = 0.5;
  static constexpr int kIncreaseHealth = 10;
  static constexpr float kDecreaseHealth = 0.2;
  static constexpr int kInitScore = 0;
  float health_;
  int score_;
  std::vector<Coin> coins_;

 public:
  /**
   * Default constructor
   */
  Player();

  /**
   * Constructor to initialize the player object using the top left
   * and bottom right coordinates and the color
   * @param top_left_corner the top left corner of the platform object
   * @param bottom_right_corner the bottom right corner of the platform object
   * @param color the color of the platform object
   */
  Player(const glm::vec2& top_left, const glm::vec2 bottom_right);

  /**
   * Function to set the coordinates of the player
   */
   void SetPosition(const glm::vec2& top_left, const glm::vec2 bottom_right);

  /**
   * Method to Draw the player object
   */
  void Draw() const override;

  /**
   * Getter to return the score of the player
   */
   int GetScore() const;


   /**
    * Function to increase the score by the int passed in the function
    */
    void UpdateScore(int to_add);

  // Move functions that help to move the player
  /**
   * Method to move the object up
   */
  void MoveUp();

  /**
   * Method to move the object up
   */
  void MoveDown();

  /**
   * Method to move the object left
   */
  void MoveLeft();

  /**
   * Method to move the object right
   */
  void MoveRight();

  /**
   * Method representing gravity, pushes the player downwards
   */
  void PushDown();

  // Functions to operate on the player's health
  /**
   * Returns the health of the player
   * @return the health of the player
   */
  float GetHealth();

  /**
   * Increase the health of the player
   */
  void IncreaseHealth();

  /**
   * Reduces the health of the player
   */
  void ReduceHealth();

  /**
   * Function to pickup the coin when the player collides with a coin
   * @param coin that player is on
   */
  void PickupCoin(const Coin& coin);

  /**
   * Returns the vector of coins that the player has
   */
   std::vector<Coin> GetCoins();
};

}  // namespace junglemania
