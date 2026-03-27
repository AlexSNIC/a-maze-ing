#pragma once
#include "../include/block.hpp"

Block::Block(float x, float y) : pos(x,y) {}
Block::Block(float x, float y, float len) : pos(x,y), len(len) {};

const Point& Block::get_pos() const {
  return pos;
}
const float& Block::get_len() const {
  return len;
}
void Block::set_pos(const float& x, const float& y){
  pos.x = x;
  pos.y = y;
}
void Block::set_pos(const Point& p){
  pos = p;
}
void Block::set_len(const float& l){
  len = l;
}
void Block::set_color(const float& R, const float& G, const float& B){
  if(R < 0 || R > 255) throw "R must be between 0 and 255";
  if(G < 0 || G > 255) throw "G must be between 0 and 255";
  if(B < 0 || B > 255) throw "B must be between 0 and 255";

  color[0] = R;
  color[1] = G;
  color[2] = B;
};
void Block::draw(sf::RenderWindow& window) const {
  sf::RectangleShape rect;
  rect.setFillColor(sf::Color(color[0], color[1], color[2]));
  rect.setPosition(sf::Vector2f(pos.x, pos.y));
  rect.setSize(sf::Vector2f(len, len));
  window.draw(rect);
}