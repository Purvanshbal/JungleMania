#include "enemy.h"

namespace junglemania {

Enemy::Enemy() {
  direction_ = kForward;
}

Enemy::Enemy(const vec2& top_left, const vec2& bottom_right)
    : Entity(top_left, bottom_right) {
  direction_ = kForward;
}

Enemy::Enemy(const vec2& top_left, const vec2& bottom_right, Direction direction)
    : Entity(top_left, bottom_right) {
  direction_ = direction;
}

void Enemy::Draw() const {
  ci::gl::color(ci::Color("red"));
  ci::gl::drawSolidCircle(position_, kEnemyRadius);
}

Direction Enemy::GetDirection() {
  return direction_;
}

void Enemy::SetDirection(Direction direction) {
  direction_ = direction;
}
}  // namespace junglemania
