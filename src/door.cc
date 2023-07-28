#include "door.h"

namespace junglemania {

Door::Door() = default;

Door::Door(const vec2& top_left, const vec2& bottom_right)
    : Entity(top_left, bottom_right) {
}

void Door::Draw() const {
  ci::gl::color(ci::Color("grey"));
  ci::gl::drawSolidRect(ci::Rectf(top_left_, bottom_right_));
}

}  // namespace junglemania
