#pragma once
#include "../include/piece.hpp"
#include <stdexcept>
short Piece::get_x() const {
  return x;
}
short Piece::get_y() const {
  return x;
}
bool Piece::is_king() const {
  return king;
}
Color Piece::get_color() const {
  return color;
}
void Piece::make_king() {
  king = true;
}
void Piece::set_position(short x, short y) {
  if(x < 1 || x > 8 || y < 1 || y > 8) throw std::out_of_range("Invalid position: " + std::to_string(x) + ", " + std::to_string(y)+ "\nCalled at " + __PRETTY_FUNCTION__);
  this->x = x;
  this->y = y;
}

void Piece::draw(sf::RenderWindow& window) const {
  sf::CircleShape circle;
  float rad = rv/2;
  float centerX = rv*(x-1);
  float centerY = rv*(y-1);
  float offset = rad/4;
  circle.setPosition(sf::Vector2f(centerX + offset, centerY + offset));
  circle.setRadius(rad - offset);
  circle.setFillColor(color == Color::WHITE? sf::Color(127, 127, 127) : sf::Color(50, 50, 50));
  window.draw(circle);
  
  offset = rad/4 + 2;
  circle.setPosition(sf::Vector2f(centerX + offset, centerY + offset));
  circle.setRadius(rad - offset);
  circle.setFillColor(color == Color::WHITE? sf::Color(180, 180, 180) : sf::Color(30, 30, 30));
  window.draw(circle);  window.draw(circle);
};
Piece::Piece(short x, short y, Color color) : x{x}, y{y}, color{color} {};