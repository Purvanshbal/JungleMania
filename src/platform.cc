#include "platform.h"

namespace junglemania {

Platform::Platform() = default;

Platform::Platform(const vec2& top_left, const glm::vec2 bottom_right)
    : Entity(top_left, bottom_right) {
}

void Platform::Draw() const {
  ci::gl::color(ci::Color("brown"));
  ci::gl::drawSolidRect(ci::Rectf(top_left_, bottom_right_));
}
}  // namespace junglemania
