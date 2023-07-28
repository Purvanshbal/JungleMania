#include "entity.h"

namespace junglemania {
Entity::Entity() = default;

Entity::Entity(const vec2& top_left, const vec2& bottom_right) {
  top_left_ = top_left;
  bottom_right_ = bottom_right;
  position_ = glm::vec2((top_left_.x + bottom_right_.x) / 2,
                        (top_left_.y + bottom_right_.y) / 2);
}

void Entity::Draw() const {
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(ci::Rectf(top_left_, bottom_right_));
}

Entity::~Entity() {
}

glm::vec2 Entity::GetPosition() const {
  return position_;
}

glm::vec2 Entity::GetTopLeft() const {
  return top_left_;
}

glm::vec2 Entity::GetBottomRight() const {
  return bottom_right_;
}

CollisionResult Entity::DetectCollision(const Entity& other) {
  float x = position_.x;
  float y = position_.y;
  float height = bottom_right_.y - top_left_.y;
  float width = bottom_right_.x - top_left_.x;

  if (x <= other.GetBottomRight().x && x >= other.GetTopLeft().x &&
      other.GetTopLeft().y - y <= height && other.GetTopLeft().y - y >= 0) {
    return kTop;
  } else if (y - other.GetBottomRight().y >= 0 &&
             y - other.GetBottomRight().y < height &&
             x <= other.GetBottomRight().x && x >= other.GetTopLeft().x) {
    return kBottom;
  } else if (y <= other.GetBottomRight().y && y >= other.GetTopLeft().y &&
             other.GetTopLeft().x - x < width &&
             other.GetTopLeft().x - x >= 0) {
    return kLeft;
  } else if (y <= other.GetBottomRight().y && y >= other.GetTopLeft().y &&
             x - other.GetBottomRight().x < width &&
             x - other.GetBottomRight().x >= 0) {
    return kRight;
  } else {
    return kNone;
  }
}

std::istream& operator>>(std::istream& is, Entity& entity) {
  if (is.bad()) {
    throw std::invalid_argument("Invalid file path or file didn't open");
  }
  std::string line;
  getline(is, line);
  int top_x = stoi(line);
  getline(is, line);
  int top_y = stoi(line);
  getline(is, line);
  int bottom_x = stoi(line);
  getline(is, line);
  int bottom_y = stoi(line);

  entity.top_left_ = glm::vec2(top_x, top_y);
  entity.bottom_right_ = glm::vec2(bottom_x, bottom_y);

  entity.position_ = glm::vec2((top_x + bottom_x) / 2, (top_y + bottom_y) / 2);
  return is;
}
}  // namespace junglemania