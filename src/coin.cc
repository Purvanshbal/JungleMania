#include "coin.h"

namespace junglemania {
Coin::Coin() = default;

Coin::Coin(const vec2& top_left, const vec2& bottom_right)
    : Entity(top_left, bottom_right) {
}

void Coin::Draw() const {
  ci::gl::color(ci::Color("yellow"));
  ci::gl::drawSolidCircle(position_, kCoinWidth);
}
}  // namespace junglemania
