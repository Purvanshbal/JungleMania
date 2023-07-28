#include "powerup.h"

namespace junglemania {

PowerUp::PowerUp() = default;

PowerUp::PowerUp(const vec2& top_left, const vec2& bottom_right)
    : Entity(top_left, bottom_right) {
}

void PowerUp::Draw() const {
  ci::gl::color(ci::Color("blue"));
  ci::gl::drawSolidRect(ci::Rectf(top_left_, bottom_right_));
}

}  // namespace junglemania
