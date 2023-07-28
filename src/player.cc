#include "player.h"

namespace junglemania {

Player::Player() {
  health_ = kMaxHealth;
  score_ = kInitScore;
}

Player::Player(const vec2& top_left, const glm::vec2 bottom_right)
    : Entity(top_left, bottom_right) {
  health_ = kMaxHealth;
  score_ = kInitScore;
}

void Player::Draw() const {
  ci::gl::color(ci::Color("pink"));
  ci::gl::drawSolidCircle(position_, kPlayerRadius);
  ci::gl::color(ci::Color("red"));
  ci::gl::drawSolidCircle(position_, 5);
  ci::gl::color(ci::Color("Black"));
  ci::gl::drawSolidCircle(position_ - glm::vec2(5, 5), 3);
  ci::gl::drawSolidCircle(position_ - glm::vec2(-5, 5), 3);
  ci::gl::drawSolidCircle(position_ - glm::vec2(0, -10), 6);
}

void Player::MoveUp() {
  position_.y -= kMoveConstant;
}
void Player::MoveDown() {
  position_.y += kMoveConstant;
}

void Player::MoveLeft() {
  position_.x -= kMoveConstant;
}

void Player::MoveRight() {
  position_.x += kMoveConstant;
}
void Player::PushDown() {
  position_.y += kGravityConstant;
}

float Player::GetHealth() {
  return health_;
}

void Player::IncreaseHealth() {
  health_ += kIncreaseHealth;
}
void Player::ReduceHealth() {
  health_ -= kDecreaseHealth;
}

void Player::PickupCoin(const Coin& coin) {
  coins_.push_back(coin);
}

std::vector<Coin> Player::GetCoins() {
  return coins_;
}

void Player::SetPosition(const vec2& top_left, const glm::vec2 bottom_right) {
  top_left_ = top_left;
  bottom_right_ = bottom_right;
  position_ = glm::vec2((top_left_.x + bottom_right_.x) / 2,
                        (top_left_.y + bottom_right_.y) / 2);
}

int Player::GetScore() const {
  return score_;
}
void Player::UpdateScore(int to_add) {
  if (score_ == 0 && to_add < 0) {
    score_ = 0;
  } else {
    score_ += to_add;
  }
}

}  // namespace junglemania