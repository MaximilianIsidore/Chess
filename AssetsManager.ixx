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