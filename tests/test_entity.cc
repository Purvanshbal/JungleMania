#include <entity.h>

#include <catch2/catch.hpp>

//Testing Collision between two entities
TEST_CASE("Testing Collisions between two entities") {
  junglemania::Entity entity_one = junglemania::Entity(glm::vec2(500, 500), glm::vec2(540, 540));
  SECTION("Testing Top Collision") {
    junglemania::Entity entity_two = junglemania::Entity(glm::vec2(520, 520), glm::vec2(560, 560));
    REQUIRE(entity_one.DetectCollision(entity_two) == junglemania::CollisionResult::kTop);
  }

  SECTION("Testing Bottom Collision") {
    junglemania::Entity entity_two = junglemania::Entity(glm::vec2(500, 480), glm::vec2(540, 500));
    REQUIRE(entity_one.DetectCollision(entity_two) == junglemania::CollisionResult::kBottom);
  }

  SECTION("Testing Left Collision") {
    junglemania::Entity entity_two = junglemania::Entity(glm::vec2(540, 500), glm::vec2(580, 540));
    REQUIRE(entity_one.DetectCollision(entity_two) == junglemania::CollisionResult::kLeft);
  }

  SECTION("Testing Right Collision") {
    junglemania::Entity entity_two = junglemania::Entity(glm::vec2(460, 500), glm::vec2(500, 540));
    REQUIRE(entity_one.DetectCollision(entity_two) == junglemania::CollisionResult::kRight);
  }

  SECTION("Testing No Collision") {
    junglemania::Entity entity_two = junglemania::Entity(glm::vec2(0, 0), glm::vec2(10, 40));
    REQUIRE(entity_one.DetectCollision(entity_two) == junglemania::CollisionResult::kNone);
  }
}

//Testing loading entity from a file
TEST_CASE("Testing loading entity from a file using >> operator") {
  std::string filepath =
      "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_file_entity_overload";
  std::ifstream image_stream(filepath);
  std::istream& is = image_stream;
  junglemania::Entity entity;
  is >> entity;

  SECTION("Testing for the top left vector of the entity") {
    REQUIRE(entity.GetTopLeft() == glm::vec2(300, 500));
  }
  SECTION("Testing for the bottom right vector of the entity") {
    REQUIRE(entity.GetBottomRight() == glm::vec2(400, 550));
  }
  SECTION("Testing for the position of the entity object") {
    REQUIRE(entity.GetPosition() == glm::vec2(350, 525));
  }
}

TEST_CASE("Testing loading using >> operator for bad file") {
  std::string filepath =
      "/Users/purvanshbal/Desktop/Cinder/my-projects/final-project-Purvanshbal/data/test_bad";
  std::ifstream image_stream(filepath);
  std::istream& is = image_stream;
  junglemania::Entity entity;
  REQUIRE_THROWS_AS(is >> entity, std::invalid_argument);
}