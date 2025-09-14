module;

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

export module game;
import board;

export class Game{
    public:
        Game() : window(sf::VideoMode({static_cast<unsigned int>((Board::WIDTH + 3) * Board::BLOCK_SIZE)
                    , static_cast<unsigned int>((Board::HEIGHT + 2) * Board::BLOCK_SIZE)}), "Chess", 
                    sf::Style::Titlebar | sf::Style::Close),
                    font("arial.ttf"),
                    board(){

            window.setFramerateLimit(60);

            auto image = sf::Image{};
            if (!image.loadFromFile("assets/icon.png"))
            {
                std::cout<<"Cant load the icon\n";
            }

            window.setIcon(image.getSize(), image.getPixelsPtr());
            
        }

        void run(){
            while(window.isOpen()){
                handle_events();
                update();
                render();
            }
        }
    private:
        void handle_events(){
            while(const std::optional event = window.pollEvent()){
                if(event->is<sf::Event::Closed>()){
                    window.close();
                } 
            }
        }

        void update(){

        }

        void render(){
            window.clear();
            board.draw(window);
            window.display();
        }
    
    private:
        sf::RenderWindow window;
        sf::Font font;

        Board board;
};