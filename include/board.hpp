#pragma once
#include "../src/piece.cpp"
#include <vector>
#include <utility>

class Board {
private:
  friend void setup_board(Board& board);
  friend void draw_board(sf::RenderWindow& window, const Board& board);
  std::vector<Piece> pieces;
  std::vector<std::vector<Piece*>> square{9, std::vector<Piece*>(9, nullptr)};

public:
  bool is_white(short x, short y) const;
  bool is_black(short x, short y) const;
  bool has_piece(short x, short y) const;

private:
  bool out_of_bounds(short x, short y) const;
  Piece* get_piece_at(short x, short y) const;
  std::vector<std::pair<short, short>> can_move_to(Piece& piece) const;

public:

  void move(Piece& piece, short to_x, short to_y);
  void take(Piece& attacker, Piece& target);
};