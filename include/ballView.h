#ifndef BALLVIEW_H
#define BALLVIEW_H  

#include <SFML/Graphics.hpp>

class BallView{
    
    private:
        sf::RenderWindow *App;
        sf::Sprite ball;
        sf::String ballScore; 
        
    public:
        int direction; //1 if going towards computer, -1 if going towards user,
        float angle[2]; //Angle at which ball is traveling
        
        BallView(sf::RenderWindow *App); //Also pass in a pointer to whatever the state of the current game is
        
        void setSpriteTexture(sf::Texture texture);
        sf::Vector2f getSpritePosition();
        
        void drawSprite();
        void resetSprite();
        int updateSprite(float deltaMs);
    
        void displayScore(int score);
};

#endif 
 
