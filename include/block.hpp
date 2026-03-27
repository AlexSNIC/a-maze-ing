#pragma once
#include "point.hpp"
#include <SFML/Graphics.hpp>
#include <tuple>

class Block {
private:
  Point pos{0,0};
  float len{0};
  float color[3]{0,0,0};

public:
  const Point& get_pos() const;
  const float& get_len() const;

  void set_pos(const float& x, const float& y);
  void set_pos(const Point& point);
  void set_len(const float& length);
  void set_color(const float& R, const float& G, const float& B);

  void draw(sf::RenderWindow& window) const;

  Block() {};
  Block(float x, float y);
  Block(float x, float y, float len);
};