#include <SFML/Graphics.hpp>
#include <optional>
#include "block.cpp"
#include <vector>

const int vw = 1600;
const int vh = 900;

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode({vw, vh}), "SFML Square");
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        vector<vector<int>> mat(9, vector<int>(16, 0));
        mat.at(5).at(5) = 1;
        mat.at(5).at(6) = 1;
        mat.at(5).at(7) = 1;
        mat.at(6).at(6) = 1;

        const Block rect;
        for(const auto& vec : mat){
            for(const int& i : vec){
                
            }
        }
        
    }

    return 0;
}