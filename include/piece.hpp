#pragma once
#include "helper.hpp"
class Piece {
  
private:
  short x, y;
  Color color;
  bool king = false;

public:
  short get_x() const;
  short get_y() const;
  bool is_king() const;
  Color get_color() const;

  void make_king();
  void set_position(short to_x, short to_y);
  void draw(sf::RenderWindow& window) const;

  Piece(short x, short y, Color color);
};