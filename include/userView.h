#ifndef USERVIEW_H
#define USERVIEW_H  

#include <SFML/Graphics.hpp>

class UserView{
    
    private:
        sf::RenderWindow *App;
        sf::Sprite userPaddle;
        sf::Texture texture;
        
    public:
        UserView(sf::RenderWindow *App, sf::Texture texture); //Also pass in a pointer to whatever the state of the current game is
        sf::Vector2f getSpritePosition();
        void drawSprite();
        void updateSprite(sf::Event event);
        
};

#endif 
