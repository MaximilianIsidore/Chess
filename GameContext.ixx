module;

#include <SFML/Graphics.hpp>

export module gamecontext;

export struct GameContext{
    private:
        sf::RenderWindow& window;
        sf::Font& font;
   
    public:
        GameContext(sf::RenderWindow& window, sf::Font& font) : window(window), font(font){

        }

        sf::RenderWindow& getWindow(){
            return window;
        }

        sf::Font& getFont(){
            return font;
        }
};