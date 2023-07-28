#include <coin.h>
#include <player.h>

#include <catch2/catch.hpp>

// Testing Move and gravity functions on the Player
TEST_CASE("Testing Move functions on the player") {
  junglemania::Player player =
      junglemania::Player(glm::vec2(500, 500), glm::vec2(520, 520));

  SECTION("Checking MoveUp() Function") {
    player.MoveUp();
    REQUIRE(player.GetPosition() == glm::vec2(510, 500));
  }

  SECTION("Checking MoveDown() Function") {
    player.MoveDown();
    REQUIRE(player.GetPosition() == glm::vec2(510, 520));
  }

  SECTION("Checking MoveRight() Function") {
    player.MoveRight();
    REQUIRE(player.GetPosition() == glm::vec2(520, 510));
  }

  SECTION("Checking MoveLeft() Function") {
    player.MoveLeft();
    REQUIRE(player.GetPosition() == glm::vec2(500, 510));
  }
}

TEST_CASE("Testing Implementation of Gravity") {
  junglemania::Player player =
      junglemania::Player(glm::vec2(500, 500), glm::vec2(520, 520));
  SECTION("Checking PushDown() Function") {
    player.PushDown();
    REQUIRE(player.GetPosition() == glm::vec2(510, 510.5));
  }
}

// Testing health and coin functions on the player
TEST_CASE("Testing health functions on Player Class") {
  junglemania::Player player =
      junglemania::Player(glm::vec2(500, 500), glm::vec2(520, 520));

  SECTION("Testing Player Health before any health reductions") {
    REQUIRE(player.GetHealth() == 100);
  }

  SECTION("Testing Player health after calling ReduceHealth() function") {
    player.ReduceHealth();
    REQUIRE(player.GetHealth() == Approx(99.8));
  }

  SECTION("Testing Player health after calling IncreaseHealth() function") {
    player.IncreaseHealth();
    REQUIRE(player.GetHealth() == 110);
  }
}

TEST_CASE("Testing Coin Pickup Coin Function") {
  junglemania::Player player =
      junglemania::Player(glm::vec2(500, 500), glm::vec2(520, 520));
  junglemania::Coin coin =
      junglemania::Coin(glm::vec2(500, 500), glm::vec2(505, 505));
  player.PickupCoin(coin);
  REQUIRE(player.GetCoins().size() == 1);
}

TEST_CASE("Testing Score Functions") {
  junglemania::Player player =
      junglemania::Player(glm::vec2(500, 500), glm::vec2(520, 520));
  SECTION("Testing Score After Score Update with Positive Number") {
    player.UpdateScore(100);
    REQUIRE(player.GetScore() == 100);
  }
  SECTION("Testing Score After Score Update with Negative Number") {
    player.UpdateScore(-20);
    REQUIRE(player.GetScore() == 0);
  }
}