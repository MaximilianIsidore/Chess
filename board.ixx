module;

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

export module board;

import gamecontext;
import assetsmanager;

export class Board{
    public:
        static constexpr int WIDTH = 8;
        static constexpr int HEIGHT = 8;
        static constexpr float BLOCK_SIZE = 85.0f;

        Board(GameContext& gamecontext): gamecontext(gamecontext)
                 {

            chess_board.resize(8, std::vector<std::pair<std::string,sf::Sprite>>(8, {"", sf::Sprite(boardAssets.getLightTexture())}));

            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {

                    std::string coordinate(1, 'a' + col);
                    coordinate += std::to_string(HEIGHT - row);
                    
                    chess_board[row][col].first = coordinate;
                    std::cout<<coordinate<<" ";

                    sf::Texture& tex = ((row + col) % 2 == 0) ? boardAssets.getLightTexture() : boardAssets.getDarkTexture();
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
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                sf::Vector2i pos = sf::Mouse::getPosition(gamecontext.getWindow());
                
                for (int row = 0; row < 8; ++row) {
                    for (int col = 0; col < 8; ++col) {
                        int left   = col * BLOCK_SIZE;
                        int right  = (col + 1) * BLOCK_SIZE;
                        int top    = row * BLOCK_SIZE;
                        int bottom = (row + 1) * BLOCK_SIZE;

                        if(pos.x >= left && pos.x <= right && pos.y >= top && pos.y <= bottom){
                            std::cout<<row<<" "<<col<<"clicked, coordinate : "<< chess_board[row][col].first<<std::endl;
                            pos.x = -1;
                            pos.y = -1;
                        }
                    }
                }


            }
        }
        
        void update(){
            recordClick();
        }

        void draw(){
            for (int row = 0; row < 8; ++row)
                for (int col = 0; col < 8; ++col)
                    gamecontext.getWindow().draw(chess_board[row][col].second);
        }
    
    private:
        BoardAssetsManager boardAssets;

        std::vector<std::vector<std::pair<std::string,sf::Sprite>>> chess_board;
        GameContext& gamecontext;
       
};

