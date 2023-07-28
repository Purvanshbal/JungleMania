#include <layout.h>
#include <catch2/catch.hpp>

TEST_CASE("Testing operartor overloading for the layout object") {
  std::string inputfilepath = "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_layout";
  std::ifstream inputfile(inputfilepath);
  junglemania::Layout layout;
  if (inputfile.is_open()) {
    inputfile >> layout;
    inputfile.close();
  }

  SECTION("Checking the top_left_corner of the layout") {
    REQUIRE(layout.GetTopLeftCorner() == glm::vec2(100, 100));
  }

  SECTION("Checking the bottom_right_corner of the layout") {
    REQUIRE(layout.GetBottomRightCorner() == glm::vec2(700, 700));
  }

  SECTION("Checking the number of platforms") {
    REQUIRE(layout.GetPlatforms().size() == 1);
  }

  SECTION("Checking the top_left_corner of the platform") {
    REQUIRE(layout.GetPlatforms()[0].GetTopLeft() == glm::vec2(300, 500));
  }

  SECTION("Checking the bottom_right_corner of the platform") {
    REQUIRE(layout.GetPlatforms()[0].GetBottomRight() == glm::vec2(400, 550));
  }

  SECTION("Checking the number of coins") {
    REQUIRE(layout.GetCoins().size() == 1);
  }

  SECTION("Checking the top_left_corner of the coin") {
    REQUIRE(layout.GetCoins()[0].GetTopLeft() == glm::vec2(330, 485));
  }

  SECTION("Checking the bottom_right_corner of the coin") {
    REQUIRE(layout.GetCoins()[0].GetBottomRight() == glm::vec2(335, 490));
  }

  SECTION("Checking the number of powerUps") {
    REQUIRE(layout.GetPowerUp().size() == 1);
  }

  SECTION("Checking the top_left_corner of the powerUp") {
    REQUIRE(layout.GetPowerUp()[0].GetTopLeft() == glm::vec2(350, 480));
  }

  SECTION("Checking the bottom_right_corner of the powerUp") {
    REQUIRE(layout.GetPowerUp()[0].GetBottomRight() == glm::vec2(360, 490));
  }

  SECTION("Checking the number of Enemies") {
    REQUIRE(layout.GetEnemies().size() == 1);
  }

  SECTION("Checking the top_left_corner of the Enemy") {
    REQUIRE(layout.GetEnemies()[0].GetTopLeft() == glm::vec2(400, 570));
  }

  SECTION("Checking the bottom_right_corner of the Enemy") {
    REQUIRE(layout.GetEnemies()[0].GetBottomRight() == glm::vec2(420, 590));
  }

  SECTION("Checking the top_left_corner of the start block") {
    REQUIRE(layout.GetStartBlock().GetTopLeft() == glm::vec2(610, 620));
  }
  SECTION("Checking the bottom_right_corner of the start block") {
    REQUIRE(layout.GetStartBlock().GetBottomRight() == glm::vec2(660, 670));
  }
  SECTION("Checking the top_left_corner of the end block") {
    REQUIRE(layout.GetExitBlock().GetTopLeft() == glm::vec2(300, 150));
  }
  SECTION("Checking the bottom_right_corner of the start block") {
    REQUIRE(layout.GetExitBlock().GetBottomRight() == glm::vec2(350, 200));
  }
}

TEST_CASE("Testing operator overloading using bad file") {
  std::string filepath =
      "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_bad";
  std::ifstream image_stream(filepath);
  std::istream& is = image_stream;
  junglemania::Layout layout;
  REQUIRE_THROWS_AS(is >> layout, std::invalid_argument);
}