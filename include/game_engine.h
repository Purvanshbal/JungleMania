#pragma once

#include "cinder/gl/gl.h"
#include "layout.h"
#include "player.h"

namespace junglemania {
constexpr int kScoreCoin = 100;
constexpr int kScoreEnemy = 500;
constexpr int kScoreLevel = 1000;
constexpr int kWindowSize = 1100;
constexpr int kMaxLevel = 3;
constexpr int kMinEnergy = 10;
const glm::vec2 kVelocityIncrease = glm::vec2(0.5, 0);
const glm::vec2 kVelocityDecrease = glm::vec2(-0.5, 0);
const glm::vec2 kDisplayBoardLeft = glm::vec2(800, 100);
const glm::vec2 kDisplayBoardRight = glm::vec2(1000, 260);
const glm::vec2 kLineLeft = glm::vec2(800, 140);
const glm::vec2 kLineRight = glm::vec2(1000, 140);
const glm::vec2 kPlayerStats = glm::vec2(900, 120);
const glm::vec2 kNumCoins = glm::vec2(900, 160);
const glm::vec2 kPlayerScore = glm::vec2(900, 180);
const glm::vec2 kHealth = glm::vec2(900, 200);
const glm::vec2 kHealthMeterLeft = glm::vec2(850, 220);
const glm::vec2 kHealthMeterRight = glm::vec2(950, 240);
constexpr char kUpArrow = '^';
constexpr char kLeftArrow = '<';
constexpr char kRightArrow = '>';
constexpr char kEnter = '&';

class GameEngine {
 public:
  /**
   * Default Constructor for GameEngine
   */
  GameEngine();

  /**
   * Constructor that takes in the level numnber and initializes the game
   * accordingly
   * @param level
   */
  GameEngine(int level);

  /**
  * Constructor for testing
  */
  GameEngine(Layout layout, Player player);

  /**
   * Updates the Position of the player every second (accounts for user input)
   */
  void AdvanceOneFrame();

  /**
   * Displays the layout and the player object
   */
  void Display();

  /**
   * Handles the movement of the player object according to user input
   * @param key_character corresponding character to the key pressed
   */
  void HandlePlayerMovement(char key_character);

  /**
   * Returns the Layout object
   */
   Layout GetLayout();


   /**
    * Returns the player object in the game
    * @return player_
    */
   Player GetPlayer();

   /**
    * Return the current level in the game
    * @return level_
    */
   int GetLevel();

  /**
   * Checks if the user has won the game
   * @return true if game has been won, false otherwise
   */
  bool IsGameWon();

 private:
  Layout layout_;
  Player player_;
  int level_;

  /**
   * Checks if the player is currently on any platform object
   * @return true if the player is on a platform
   */
  bool IsPlayerOnAnyPlatform();

  /**
   * Handles the collision of the player object with player edges
   */
  void HandlePlatformCollisions();

  /**
   * Collects the coins in the ga,e
   */
  void CollectCoins();

  /**
   * Checks if the user has lost the game
   * @return true if game has been lost, false otherwise
   */
  bool IsGameLost();

  /**
   * Collects the powerups in the layout
   */
  void CollectPowerUps();

  /**
   * Handles Enemy collisions
   */
  void HandleEnemyCollisions();

  /**
   * Handles Player Collision with Layout walls
   */
  void HandleWallCollisions();


  /**
   * Updates the layout object dependent on the level
   */
   void NewGame(int level);

   /**
    * Moves the enemy objects randomly
    */
  void UpdateEnemyLocations();

  /**
   * Checks if the current level is finished
   * @return true if the level is finished
   */
  bool IsCurrentLevelFinished();

  /**
   * Displays player stats in a side board
   */
  void DisplayStats();

};
}  // namespace junglemania