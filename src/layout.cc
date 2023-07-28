#include "layout.h"

namespace junglemania {
Layout::Layout() = default;

Layout::Layout(const vec2& top_left_corner, const vec2& bottom_right_corner) {
  top_left_corner_ = top_left_corner;
  bottom_right_corner_ = bottom_right_corner;
}

void Layout::Display() const {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(top_left_corner_), vec2(bottom_right_corner_)));
  for (const Platform& p : platforms_) {
    p.Draw();
  }
  for (const Coin& c : coins_) {
    c.Draw();
  }
  for (const PowerUp& u : powerUps_) {
    u.Draw();
  }
  for (const Enemy& e : enemies_) {
    e.Draw();
  }
  start_block_.Draw();
  exit_block_.Draw();
}

glm::vec2 Layout::GetTopLeftCorner() const {
  return top_left_corner_;
}
glm::vec2 Layout::GetBottomRightCorner() const {
  return bottom_right_corner_;
}
std::vector<Platform> Layout::GetPlatforms() const {
  return platforms_;
}
std::vector<Coin> Layout::GetCoins() const {
  return coins_;
}
std::vector<PowerUp> Layout::GetPowerUp() const {
  return powerUps_;
}
std::vector<Enemy> Layout::GetEnemies() const {
  return enemies_;
}
Door Layout::GetExitBlock() const {
  return exit_block_;
}
Door Layout::GetStartBlock() const {
  return start_block_;
}

void Layout::SetCoins(const std::vector<Coin>& coins) {
  coins_ = coins;
}

void Layout::SetPowerUps(const std::vector<PowerUp>& powerups) {
  powerUps_ = powerups;
}

void Layout::SetEnemies(const std::vector<Enemy>& enemies) {
  enemies_ = enemies;
}
void Layout::SetPlatforms(const std::vector<Platform>& platforms) {
  platforms_ = platforms;
}

std::istream& operator>>(std::istream& is, Layout& Layout) {
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

  Layout.top_left_corner_ = glm::vec2(top_x, top_y);
  Layout.bottom_right_corner_ = glm::vec2(bottom_x, bottom_y);

  getline(is, line);
  int num_platforms = stoi(line);

  for (int i = 0; i < num_platforms; i++) {
    Platform plat;
    is >> plat;
    Layout.platforms_.push_back(plat);
  }

  getline(is, line);
  int num_powerups = stoi(line);
  for (int i = 0; i < num_powerups; i++) {
    PowerUp p;
    is >> p;
    Layout.powerUps_.push_back(p);
  }

  getline(is, line);
  int num_enemies = stoi(line);
  for (int i = 0; i < num_enemies; i++) {
    Enemy e;
    is >> e;
    Layout.enemies_.push_back(e);
  }

  getline(is, line);
  int num_coins = stoi(line);
  for (int i = 0; i < num_coins; i++) {
    Coin c;
    is >> c;
    Layout.coins_.push_back(c);
  }
  is >> Layout.start_block_;
  is >> Layout.exit_block_;

  return is;
}
}  // namespace junglemania
