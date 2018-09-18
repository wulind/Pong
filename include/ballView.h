#ifndef BALLVIEW_H
#define BALLVIEW_H  

#include <SFML/Graphics.hpp>

class BallView{
    
    private:
        sf::RenderWindow *App;
        sf::Sprite ball;
        sf::Texture texture;
        float angle[2];
        int detectCollision(sf::Vector2f paddleOrigin);
        
    public:
        int direction;//1 if going towards computer, -1 if going towards user
        
        BallView(sf::RenderWindow *App, sf::Texture texture); //Also pass in a pointer to whatever the state of the current game is
        sf::Vector2f getSpritePosition();
        void drawSprite();
        void resetSprite();
        int updateSprite(sf::Vector2f paddleLocation);
        void findAngle(sf::Vector2f paddleLocation);
    
};

#endif 
 
