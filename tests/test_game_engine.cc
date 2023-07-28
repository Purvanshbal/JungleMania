#include <game_engine.h>
#include <layout.h>
#include <player.h>
#include <catch2/catch.hpp>


TEST_CASE("Testing Gravity Logic in the GameEngine Class") {
  std::string inputfilepath = "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_layout";
  std::ifstream inputfile(inputfilepath);
  junglemania::Layout layout;
  if (inputfile.is_open()) {
    inputfile >> layout;
    inputfile.close();
  }

  SECTION("Testing Gravity Implementation when Player is not on Platform") {
    junglemania::Player player(glm::vec2(500, 500), glm::vec2(520, 520));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetPosition() == glm::vec2(510, 510.5));
  }

  SECTION("Testing Gravity Implementation when Player is on Platform") {
    junglemania::Player player(glm::vec2(320, 470), glm::vec2(340, 490));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetPosition() == glm::vec2(330,480));
  }
}
TEST_CASE("Testing Coin Collision Logic in the GameEngine Class") {
  std::string inputfilepath = "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_layout";
  std::ifstream inputfile(inputfilepath);
  junglemania::Layout layout;
  if (inputfile.is_open()) {
    inputfile >> layout;
    inputfile.close();
  }

  SECTION("Testing Player Inventory after Coin Collision") {
    junglemania::Player player(glm::vec2(320, 480), glm::vec2(340, 500));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetCoins().size() == 1);
  }

  SECTION("Testing Layout Coin Inventory after Coin Collision") {
    junglemania::Player player(glm::vec2(320, 480), glm::vec2(340, 500));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetLayout().GetCoins().size() == 0);
  }

  SECTION("Testing Player Score after Coin Collision") {
    junglemania::Player player(glm::vec2(320, 480), glm::vec2(340, 500));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetScore() == 100);
  }
}

TEST_CASE("Testing Enemy Collision Logic in the GameEngine Class") {
  std::string inputfilepath = "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_layout";
  std::ifstream inputfile(inputfilepath);
  junglemania::Layout layout;
  if (inputfile.is_open()) {
    inputfile >> layout;
    inputfile.close();
  }

  SECTION("Testing Enemy inventory after Enemy Side Collision") {
    junglemania::Player player(glm::vec2(410, 570), glm::vec2(430, 590));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetLayout().GetEnemies().size() == 1);
  }

  SECTION("Testing Player health after Enemy Top Collision") {
    junglemania::Player player(glm::vec2(400, 550), glm::vec2(420, 570));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetHealth() == Approx(100));
  }

  SECTION("Testing Enemy inventory after Enemy Top Collision") {
    junglemania::Player player(glm::vec2(400, 550), glm::vec2(420, 570));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetLayout().GetEnemies().size() == 0);
  }

  SECTION("Testing Player score after Enemy Top Collision") {
    junglemania::Player player(glm::vec2(400, 550), glm::vec2(420, 570));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetScore() == 500);
  }
}
TEST_CASE("Testing PowerUp Collision Logic in the GameEngine Class") {
  std::string inputfilepath = "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_layout";
  std::ifstream inputfile(inputfilepath);
  junglemania::Layout layout;
  if (inputfile.is_open()) {
    inputfile >> layout;
    inputfile.close();
  }
  SECTION("Testing Player health after PowerUp Collision when health is full") {
    junglemania::Player player(glm::vec2(350, 460), glm::vec2(370, 480));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetHealth() == Approx(100));
  }

  SECTION("Testing Powerup Inventory after PowerUp Collision when health is full") {
    junglemania::Player player(glm::vec2(350, 460), glm::vec2(370, 480));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetLayout().GetPowerUp().size() == 0);
  }

  SECTION("Testing Player health after PowerUp Collision when health is not full") {
    junglemania::Player player(glm::vec2(350, 460), glm::vec2(370, 480));
    //Reducing the health of the player
    for (int i = 0; i < 100; i++) {
      player.ReduceHealth();
    }
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetHealth() == Approx(90));
  }

  SECTION("Testing Powerup Inventory after PowerUp Collision when health is not full") {
    junglemania::Player player(glm::vec2(350, 460), glm::vec2(370, 480));
    //Reducing the health of the player
    for (int i = 0; i < 100; i++) {
      player.ReduceHealth();
    }
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetLayout().GetPowerUp().size() == 0);
  }
}

TEST_CASE("Testing Platform Side Collision") {
  std::string inputfilepath = "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_layout";
  std::ifstream inputfile(inputfilepath);
  junglemania::Layout layout;
  if (inputfile.is_open()) {
    inputfile >> layout;
    inputfile.close();
  }

  SECTION("Testing player collision after collision with platform bottom edge") {
    junglemania::Player player(glm::vec2(350, 550), glm::vec2(370, 570));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetPosition() == glm::vec2(360, 570.5));
  }

    //0.5 increase in y position accounts for gravity
  SECTION("Testing player collision after collision with platform right edge") {
    junglemania::Player player(glm::vec2(400, 510), glm::vec2(420, 530));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetPosition() == glm::vec2(420, 520.5));
  }

  SECTION("Testing player collision after collision with platform left edge") {
    junglemania::Player player(glm::vec2(280, 510), glm::vec2(300, 530));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetPosition() == glm::vec2(280, 520.5));
  }
}

TEST_CASE("Testing Logic On Reaching Exit door") {
  std::string inputfilepath = "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_layout";
  std::ifstream inputfile(inputfilepath);
  junglemania::Layout layout;
  if (inputfile.is_open()) {
    inputfile >> layout;
    inputfile.close();
  }

  SECTION("Testing player score after player reaches exit door") {
    junglemania::Player player(glm::vec2(325, 200), glm::vec2(345, 220));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetPlayer().GetScore() == 1000);
  }

  SECTION("Testing current level after player reaches exit door") {
    junglemania::Player player(glm::vec2(325, 200), glm::vec2(345, 220));
    junglemania::GameEngine gameEngine(layout, player);
    gameEngine.AdvanceOneFrame();
    REQUIRE(gameEngine.GetLevel() == 1);
  }
}
