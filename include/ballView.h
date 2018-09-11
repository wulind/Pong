#ifndef BALLVIEW_H
#define BALLVIEW_H  

#include <SFML/Graphics.hpp>

class BallView{
    
    private:
        sf::RenderWindow *App;
        sf::Sprite ball;
        sf::Texture texture;
        int getDirection();
        
    public:
        int direction;//1 if going towards computer, -1 if going towards user
        BallView(sf::RenderWindow *App, sf::Texture texture); //Also pass in a pointer to whatever the state of the current game is
        void drawSprite();
        void updateSprite(float angle[]);
        float* findAngle(sf::Vector2f paddleOrigin);
    
};

#endif 
 
