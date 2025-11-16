module;

#include <SFML/Graphics.hpp>
export module assetsmanager;

export class BoardAssetsManager{
    private:
        sf::Texture dark_tex;
        sf::Texture light_tex;
    
    public:
        BoardAssetsManager() : dark_tex("assets/board/dark_square.png") , light_tex("assets/board/light_square.png")
        {

        }

        sf::Texture& getDarkTexture(){
            return dark_tex;
        }

        sf::Texture& getLightTexture(){
            return light_tex;
        }
};


export class BlackPieceAssetsManager(){
    private:
        sf::Texture king_tex;
        sf::Texture queen_tex;
        sf::Texture rook_tex;
        sf::Texture bishop_tex;
        sf::Texture knight_tex;
        sf::Texture pawn_tex;

    public:
        pieceAssetsManager() : king_tex("assets/pieces/b_king.png"), queen_tex("assets/pieces/b_queen.png"), 
                               rook_tex("assets/pieces/b_rook.png"),bishop_tex("assets/pieces/b_bishop.png"), 
                               knight_tex("assets/pieces/b_knight.png"), pawn_tex("assets/pieces/b_pawn.png")
        {

        }

          sf::Texture& getKingTex(){
            return king_tex;
        }

        sf::Texture& getQueenTex(){
            return queen_tex;
        }

        sf::Texture& getBishopTex(){
            return bishop_tex;
        }

        sf::Texture& getKnightTex(){
            return knight_tex;
        }

        sf::Texture& getRookTex(){
            return rook_tex;
        }

        sf::Texture& getPawnTex(){
            return pawn_tex;
        }
};

export class WhitePieceAssetsManager(){
    private:
        sf::Texture king_tex;
        sf::Texture queen_tex;
        sf::Texture rook_tex;
        sf::Texture bishop_tex;
        sf::Texture knight_tex;
        sf::Texture pawn_tex;

    public:
        pieceAssetsManager() : king_tex("assets/pieces/w_king.png"), queen_tex("assets/pieces/w_queen.png"), 
                               rook_tex("assets/pieces/w_rook.png"),bishop_tex("assets/pieces/w_bishop.png"), 
                               knight_tex("assets/pieces/w_knight.png"), pawn_tex("assets/pieces/w_pawn.png")
        {

        }

        sf::Texture& getKingTex(){
            return king_tex;
        }

        sf::Texture& getQueenTex(){
            return queen_tex;
        }

        sf::Texture& getBishopTex(){
            return bishop_tex;
        }

        sf::Texture& getKnightTex(){
            return knight_tex;
        }

        sf::Texture& getRookTex(){
            return rook_tex;
        }

        sf::Texture& getPawnTex(){
            return pawn_tex;
        }
};

export class AssetsManager{
    private:
        BoardAssetsManager boardAssets;

    public:
        AssetsManager() : boardAssets(){

        }

        BoardAssetsManager& getBoardAssetsManager(){
            return boardAssets;
        }
};