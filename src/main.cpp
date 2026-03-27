#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include <iostream>
#include "block.cpp"
#include "board.cpp"

using namespace std;

void draw_table(sf::RenderWindow& window);
void draw_board(sf::RenderWindow& window, const Board& board);
void setup_board(Board& board);
int main()
{
  Board board;
  try{
  sf::RenderWindow window(sf::VideoMode({vw, vh}), "Checkers");
  while (window.isOpen()){
    while (const std::optional event = window.pollEvent()){
      if (event->is<sf::Event::Closed>())
        window.close();
    }
    setup_board(board);
    draw_table(window);
    draw_board(window, board);
    window.display();
  }

  }
  catch(const exception& e){
  cout << e.what() << endl;
  }
return 0;
}

void draw_table(sf::RenderWindow& window){
  Block def_block{0.f, 0.f, 100.f};
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if ((i + j) % 2 == 0)
        def_block.set_color(255, 255, 255);
      else
        def_block.set_color(80, 80, 80);
      def_block.set_pos(j * vw / 8, i * vh / 8);
      def_block.draw(window);
    }
  }
}
void setup_board(Board& board){
  Block def_block{0.f, 0.f, 100.f};
  for (int i = 1; i <= 8; i++){
    for (int j = 1; j <= 8; j++){
      if ((i + j) % 2 == 1){
        if(i >= 6){
          board.pieces.push_back(Piece(j, i, Color::WHITE));
          board.square.at(j).at(i) = &board.pieces.back();
        }
        else if (i <= 3){
          board.pieces.push_back(Piece(j, i, Color::BLACK));
          board.square.at(j).at(i) = &board.pieces.back();
        }
      }
    }
  }
}
void draw_board(sf::RenderWindow& window, const Board& board){
  for(const Piece& piece : board.pieces){
    piece.draw(window);
  }
}