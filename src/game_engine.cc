#include "game_engine.h"

namespace junglemania {
GameEngine::GameEngine() = default;

GameEngine::GameEngine(int level) {
  level_ = level;
  player_ = Player();
  NewGame(level_);
}

GameEngine::GameEngine(Layout layout, Player player) {
  level_ = 0;
  layout_ = layout;
  player_ = player;
}

void GameEngine::AdvanceOneFrame() {
  if (IsCurrentLevelFinished() && !IsGameWon()) {
    player_.UpdateScore(kScoreLevel);
    NewGame(++level_);
  } else {
    if (!IsPlayerOnAnyPlatform()) {
      player_.PushDown();
    }
    HandlePlatformCollisions();
    CollectCoins();
    CollectPowerUps();
    UpdateEnemyLocations();
    HandleEnemyCollisions();
    HandleWallCollisions();
  }
}

void GameEngine::Display() {
  if (IsGameWon()) {
    ci::Color8u background_color(255, 246, 148);  // light yellow
    ci::gl::clear(background_color);
    ci::gl::drawStringCentered("Game Won Press Enter to begin a new game ",
                               glm::vec2(kWindowSize/2, kWindowSize/2), ci::Color("black"));
  } else if (IsGameLost()) {
    ci::gl::clear(ci::Color("red"));
    ci::gl::drawStringCentered("Game Lost! Press Enter to begin a new game",
                               glm::vec2(kWindowSize/2, kWindowSize/2), ci::Color("white"));
  } else {
    layout_.Display();
    player_.Draw();
    DisplayStats();
  }
}

void GameEngine::HandlePlayerMovement(char key_character) {
  if (key_character == kRightArrow) {
    player_.MoveRight();
  } else if (key_character == kLeftArrow) {
    player_.MoveLeft();
  } else if (key_character == kUpArrow) {
    player_.MoveUp();
  } else if ((key_character == kEnter && IsGameLost()) ||
             (key_character == kEnter && IsGameWon())) {
    player_ = Player();
    level_ = 1;
    NewGame(1);
  }
}

Layout GameEngine::GetLayout() { return layout_;}
Player GameEngine::GetPlayer() { return player_;}
int GameEngine::GetLevel() { return level_;}

bool GameEngine::IsGameWon() {
  return level_ == kMaxLevel && IsCurrentLevelFinished();
}

bool GameEngine::IsPlayerOnAnyPlatform() {
  if (player_.DetectCollision(layout_.GetStartBlock()) != kNone) {
    return true;
  }
  std::vector<Platform> platforms = layout_.GetPlatforms();
  for (const Platform& platform : platforms) {
    if (player_.DetectCollision(platform) == kTop) {
      return true;
    }
  }
  return false;
}

void GameEngine::HandlePlatformCollisions() {
  std::vector<Platform> platforms = layout_.GetPlatforms();
  for (const Platform& p : platforms) {
    if (player_.DetectCollision(p) == kBottom) {
      player_.MoveDown();
    } else if (player_.DetectCollision(p) == kLeft) {
      player_.MoveLeft();
    } else if (player_.DetectCollision(p) == kRight) {
      player_.MoveRight();
    }
  }
}

void GameEngine::CollectCoins() {
  std::vector<Coin> coins = layout_.GetCoins();
  for (int i = 0; i < coins.size(); i++) {
    Coin coin = coins[i];
    if (player_.DetectCollision(coin)) {
      player_.PickupCoin(coin);
      player_.UpdateScore(kScoreCoin);
      std::cout << player_.GetScore();
      coins.erase(coins.begin() + i);
    }
  }
  layout_.SetCoins(coins);
}

bool GameEngine::IsGameLost() {
  return player_.GetPosition().y > layout_.GetStartBlock().GetBottomRight().y ||
         player_.GetHealth() < kMinEnergy;
}


bool GameEngine::IsCurrentLevelFinished() {
  return player_.DetectCollision(layout_.GetExitBlock()) != kNone;
}


void GameEngine::CollectPowerUps() {
  std::vector<PowerUp> powerUps = layout_.GetPowerUp();
  for (int i = 0; i < powerUps.size(); i++) {
    PowerUp powerup = powerUps[i];
    if (player_.DetectCollision(powerup)) {
      if (player_.GetHealth() < kMaxHealth) {
        player_.IncreaseHealth();
      }
     powerUps.erase(powerUps.begin() + i);
    }
  }
  layout_.SetPowerUps(powerUps);
}

void GameEngine::HandleEnemyCollisions() {
  std::vector<Enemy> enemies = layout_.GetEnemies();
  for (int i = 0; i < enemies.size(); i++) {
    Enemy enemy = enemies[i];
    if (player_.DetectCollision(enemy) == kTop) {
      enemies.erase(enemies.begin() + i);
      player_.UpdateScore(kScoreEnemy);
    } else if (player_.DetectCollision(enemy) != kNone) {
      player_.ReduceHealth();
    }
  }
  layout_.SetEnemies(enemies);
}

void GameEngine::HandleWallCollisions() {
  glm::vec2 current_position = player_.GetPosition();
  int player_dimension = kPlayerRadius;

  // Checks for collision with the left wall of the layout
  if ((abs(current_position.x - layout_.GetTopLeftCorner().x) <
       player_dimension)) {
    player_.MoveRight();
  }

  // Checks for collision with the right wall of the layout
  if ((abs(current_position.x - layout_.GetBottomRightCorner().x) <
       player_dimension)) {
    player_.MoveLeft();
  }

  // Checks for collision with the top wall of the layout
  if ((abs(current_position.y - layout_.GetTopLeftCorner().y) <
       player_dimension)) {
    player_.MoveDown();
  }

  // Checks for collision with the bottom wall of the layout
  if ((abs(current_position.y - layout_.GetBottomRightCorner().y) <
       player_dimension)) {
    player_.MoveUp();
  }
}

void GameEngine::NewGame(int level) {
  std::string inputfilepath;
  switch (level) {
    case 1:
      inputfilepath =
          "/Users/purvanshbal/Desktop/Cinder/my-projects/"
          "final-project-Purvanshbal/"
          "data/layout1";
      break;
    case 2:
      inputfilepath =
          "/Users/purvanshbal/Desktop/Cinder/my-projects/"
          "final-project-Purvanshbal/"
          "data/layout2";
      break;
    case 3:
      inputfilepath =
          "/Users/purvanshbal/Desktop/Cinder/my-projects/"
          "final-project-Purvanshbal/"
          "data/layout3";
      break;
  }
  std::ifstream inputfile(inputfilepath);
  Layout layout;
  if (inputfile.is_open()) {
    inputfile >> layout;
    inputfile.close();
  }
  layout_ = layout;
  glm::vec2 player_left = layout.GetStartBlock().GetTopLeft() +
                          glm::vec2(kPlayerRadius, -kPlayerRadius);
  glm::vec2 player_right =
      player_left + glm::vec2(kPlayerRadius, kPlayerRadius);
  player_.SetPosition(player_left, player_right);
}


void GameEngine::UpdateEnemyLocations() {
  std::vector<Enemy> enemies = layout_.GetEnemies();
  std::vector<Platform> platforms = layout_.GetPlatforms();
  for (int i = 0; i < enemies.size(); i++) {
    Enemy enemy = enemies[i];

    //Checking for platform edge collisions
    for (Platform platform : platforms) {
      if (platform.GetBottomRight().x - enemy.GetPosition().x < kEnemyRadius && enemy.DetectCollision(platform) == kTop) {
        enemy.SetDirection(junglemania::Direction::kBackward);
      } else if (enemy.GetPosition().x - platform.GetTopLeft().x < kEnemyRadius && enemy.DetectCollision(platform) == kTop) {
        enemy.SetDirection(junglemania::Direction::kForward);
      }
    }

    //Changing the velocity dependent on the direction of the enemy
    glm::vec2 left;
    glm::vec2 right;
    if (enemy.GetDirection() == junglemania::Direction::kForward) {
       left = enemy.GetTopLeft() + kVelocityIncrease;
       right = enemy.GetBottomRight() + kVelocityIncrease;
      Enemy newPosition(left, right, kForward);
      enemies[i] = newPosition;
    } else if (enemy.GetDirection() == junglemania::Direction::kBackward) {
      left = enemy.GetTopLeft() + kVelocityDecrease;
      right = enemy.GetBottomRight() + kVelocityDecrease;
      Enemy newPosition(left, right, kBackward);
      enemies[i] = newPosition;
    }
  }
  layout_.SetEnemies(enemies);
}
void GameEngine::DisplayStats() {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidRect(ci::Rectf(kDisplayBoardLeft, kDisplayBoardRight));

  ci::gl::drawStringCentered("PLAYER STATS", kPlayerStats,
                             ci::Color("BLUE"));

  ci::gl::color(ci::Color("black"));
  ci::gl::drawLine(kLineLeft, kLineRight);
  ci::gl::drawStringCentered(
      "No. of Coins: " + (std::to_string(player_.GetCoins().size())),
      kNumCoins, ci::Color("black"));
  ci::gl::drawStringCentered("Player Score: " + (std::to_string(player_.GetScore())),
                             kPlayerScore, ci::Color("black"));
  ci::gl::drawStringCentered("Health: ", kHealth,
                             ci::Color("black"));

  ci::gl::drawStrokedRect(ci::Rectf(kHealthMeterLeft, kHealthMeterRight));
  ci::gl::color(ci::Color("green"));
  ci::gl::drawSolidRect(
      ci::Rectf(kHealthMeterLeft, vec2(player_.GetHealth() + kHealthMeterLeft.x, kHealthMeterRight.y)));
}
}  // namespace junglemania
