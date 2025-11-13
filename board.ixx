module;

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

export module board;

import gamecontext;

export class Board{
    public:
        static constexpr int WIDTH = 8;
        static constexpr int HEIGHT = 8;
        static constexpr float BLOCK_SIZE = 85.0f;

        Board(GameContext& gamecontext): dark_tex("assets/board/dark_square.png"), light_tex("assets/board/light_square.png"),
                 gamecontext(gamecontext)
                 {

            chess_board.resize(8, std::vector<std::pair<std::string,sf::Sprite>>(8, {"", sf::Sprite(light_tex)}));

            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {

                    std::string coordinate(1, 'a' + col);
                    coordinate += std::to_string(HEIGHT - row);
                    
                    chess_board[row][col].first = coordinate;
                    std::cout<<coordinate<<" ";

                    sf::Texture& tex = ((row + col) % 2 == 0) ? light_tex : dark_tex;
                    chess_board[row][col].second = sf::Sprite(tex);
                    chess_board[row][col].second.setPosition({col * BLOCK_SIZE, row * BLOCK_SIZE});
                    chess_board[row][col].second.setScale({
                        BLOCK_SIZE / tex.getSize().x,
                        BLOCK_SIZE / tex.getSize().y
                    });
                }

                std::cout<<"\n";
            }

        }

        void recordClick(){
            
        }

        void draw(){
            for (int row = 0; row < 8; ++row)
                for (int col = 0; col < 8; ++col)
                    gamecontext.getWindow().draw(chess_board[row][col].second);
        }
    
    private:
        sf::Texture dark_tex;
        sf::Texture light_tex;

        std::vector<std::vector<std::pair<std::string,sf::Sprite>>> chess_board;
        GameContext& gamecontext;
       
};

