#pragma once
#include "../include/board.hpp"

bool Board::is_white(short x, short y) const{
  if(square.at(y).at(x) == nullptr) return false;
  Color color = square.at(y).at(x)->get_color();
  return color == Color::WHITE;
}
bool Board::is_black(short x, short y) const{
  if(square.at(y).at(x) == nullptr) return false;
  Color color = square.at(y).at(x)->get_color();
  return color == Color::BLACK;
}

bool Board::has_piece(short x, short y) const{
  return square.at(y).at(x) != nullptr;
}

bool Board::out_of_bounds(short x, short y) const {
  if(x < 1 || x > 8 || y < 1 || y > 8) return true;
  return false;
}
Piece* Board::get_piece_at(short x, short y) const{
  if(out_of_bounds(x, y)) return nullptr;
  return square.at(y).at(x);
}
std::vector<std::pair<short, short>> Board::can_move_to(Piece& piece) const {
  // TBA: if(!can_take)...
  std::vector<std::pair<short, short>> spaces;
  short piece_x = piece.get_x();
  short piece_y = piece.get_y();
  if(!piece.is_king()){
    if(get_piece_at(piece_x - 1, piece_y + 1) == nullptr && !out_of_bounds(piece_x - 1, piece_y + 1)){
      spaces.push_back(std::make_pair(piece_x - 1, piece_y + 1));
    };
    if(get_piece_at(piece_x + 1, piece_y + 1) == nullptr && !out_of_bounds(piece_x + 1, piece_y + 1)){
      spaces.push_back(std::make_pair(piece_x + 1, piece_y + 1));
    };
    return spaces;
  }
  short x = piece_x + 1, 
        y = piece_y + 1;
  while(!out_of_bounds(x, y) && get_piece_at(x, y) == nullptr){
    spaces.push_back(std::make_pair(x, y));
    x++;
    y++;
  }

  x = piece_x + 1;
  y = piece_y - 1;
  while(!out_of_bounds(x, y) && get_piece_at(x, y) == nullptr){
    spaces.push_back(std::make_pair(x, y));
    x++;
    y--;
  }

  x = piece_x - 1;
  y = piece_y + 1;
  while(!out_of_bounds(x, y) && get_piece_at(x, y) == nullptr){
    spaces.push_back(std::make_pair(x, y));
    x--;
    y++;
  }

  x = piece_x - 1;
  y = piece_y - 1;
  while(!out_of_bounds(x, y) && get_piece_at(x, y) == nullptr){
    spaces.push_back(std::make_pair(x, y));
    x--;
    y--;
  }
  return spaces;
}

void Board::move(Piece& piece, short to_x, short to_y){
  // TBA
}