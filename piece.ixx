#include <optional>
module;

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <pair>
#include <cstdint>

export module piece;

class White{

    public:

        white(){
            intialize();
        }

        void intialize(){
            //create pawn
            pwans.resize(8,{"", Bishop(base_path + assets_path[0])});
            for(int i=0; i<8; i++){
                pwans[i].first = std::string(1,'a'+i) + std::to_string(2);
            }

            //create king
            king.first = "e1";
            king.second = King(base_path + assets_path[1]);

            queens.emblace_back({"d1", })
            bishops.resize(2, {"", Bishop(base_path + assets_path[3])});
            bishops.resize(2, {"", Bishop(base_path + assets_path[3])});
            bishops.resize(2, {"", Bishop(base_path + assets_path[3])});
        }


    private:
        std::string base_path = "assets/path/"
        std::vector<std::string> assets_path{"w_pawn.png", "w_king.png", "w_queen.png", "w_bishop.png", "w_rook.png", "w_knight.png"};
        std::vector<std::pair<std::string, Pawn>> pawns;
        std::vector<std::pair<std::string, Bishop>> bishops;
        std::vector<std::pair<std::string, Knight>> knights;
        std::vector<std::pair<std::string, Rook>> rooks;
        std::vector<std::pair<std::string, Queen>> queens;
        std::pair<std::string, King> King;
};

class Black{

    public:

     private:
        std::string base_path = "assets/path/"
        std::vector<std::string> assets_path{"b_pawn.png", "b_king.png", "b_queen.png", "b_bishop.png", "b_rook.png", "b_knight.png"};
        std::vector<std::pair<std::string, Pawn>> pawns;
        std::vector<std::pair<std::string, Bishop>> bishops;
        std::vector<std::pair<std::string, Knight>> knights;
        std::vector<std::pair<std::string, Rook>> rooks;
        std::vector<std::pair<std::string, Queen>> queens;
        std::pair<std::string, King> King;

};

class Piece{
    public:
        unit8_t getPieceValue();
        std::optional<std::vector<std::pair<unit8_t, unit8_t>>> getValidMoves();

};

class Pawn : public Piece{
    public:
        Pawn(string path) : tex(path), sprite(tex){

        }

        unit8_t getPieceValue(){
            return 1;
        }

        std::optional<std::vector<std::pair<unit8_t, unit8_t>>> getValidMoves(){

            return std::nullopt;
        }
    
    private:
        sf::Texture tex;
        sf::Sprite sprite;

};

class King : public Piece{
    public:
        King(string path) : tex(path), sprite(tex){

        }

        unit8_t getPieceValue(){
            return 255;
        }

        std::optional<std::vector<std::pair<unit8_t, unit8_t>>> getValidMoves(){

            return std::nullopt;
        }
    
    private:
        sf::Texture tex;
        sf::Sprite sprite;

};

class Queen : public Piece{
    public:
        Queen(string path) : tex(path), sprite(tex){

        }

        unit8_t getPieceValue(){
            return 9;
        }

        std::optional<std::vector<std::pair<unit8_t, unit8_t>>> getValidMoves(){

            return std::nullopt;
        }
    
    private:
        sf::Texture tex;
        sf::Sprite sprite;
};

class Bishop : public Piece{
    public:
        Bishop(string path) : tex(path), sprite(tex){

        }

        unit8_t getPieceValue(){
            return 3;
        }

        std::optional<std::vector<std::pair<unit8_t, unit8_t>>> getValidMoves(){

            return std::nullopt;
        }
    
    private:
        sf::Texture tex;
        sf::Sprite sprite;
};

class Rook : public Piece{
    public:
        Rook(string path) : tex(path), sprite(tex){

        }

        unit8_t getPieceValue(){
            return 5;
        }

        std::optional<std::vector<std::pair<unit8_t, unit8_t>>> getValidMoves(){

            return std::nullopt;
        }
    
    private:
        sf::Texture tex;
        sf::Sprite sprite;
};

class Knight : public Piece{
    public:
        Knight(string path) : tex(path), sprite(tex){

        }

        unit8_t getPieceValue(){
            return 3;
        }

        std::optional<std::vector<std::pair<unit8_t, unit8_t>>> getValidMoves(){

            return std::nullopt;
        }
    
    private:
        sf::Texture tex;
        sf::Sprite sprite;
};