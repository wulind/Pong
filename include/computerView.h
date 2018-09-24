#ifndef COMPUTERVIEW_H
#define COMPUTERVIEW_H  

#include <SFML/Graphics.hpp>

class ComputerView{
    
    private:
        sf::RenderWindow *App;
        sf::Sprite computerPaddle;
        sf::Text computerScore; 
        
    public:
        ComputerView(sf::RenderWindow *_App);
        
        void setSpriteTexture(sf::Texture *texture);
        void setScore(std::string score, sf::Font *font);
        void setScore(std::string score);
        sf::Vector2f getSpritePosition();
        
        void draw();
        void resetSprite();
        void updateSprite(sf::Vector2f ballPosition, float deltaMs);//-1 if going up, 1 if going down

        void reset();
};

#endif
