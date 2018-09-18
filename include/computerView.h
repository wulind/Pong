#ifndef COMPUTERVIEW_H
#define COMPUTERVIEW_H  

#include <SFML/Graphics.hpp>

class ComputerView{
    
    private:
        sf::RenderWindow *App;
        sf::Sprite computerPaddle;
        sf::Texture texture;
        
    public:
        ComputerView(sf::RenderWindow *App, sf::Texture texture); //Also pass in a pointer to whatever the state of the current game is
        sf::Vector2f getSpritePosition();
        void drawSprite();
        void resetSprite();
        void updateSprite(sf::Vector2f ballPosition);//-1 if going up, 1 if going down
    
};

#endif 
 
