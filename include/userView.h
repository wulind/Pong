#ifndef USERVIEW_H
#define USERVIEW_H  

#include <SFML/Graphics.hpp>

class UserView{
    
    private:
        sf::RenderWindow *App;
        sf::Sprite userPaddle;
        sf::Text userScore;
        
    public:
        
        UserView(sf::RenderWindow *App);
        
        void setSpriteTexture(sf::Texture texture);
        void setScore(std::string score, sf::Font *font);
        void setScore(std::string score);
        
        sf::Vector2f getSpritePosition();
        
        void draw();
        void resetSprite();
        void updateSprite(sf::Event event);
        
};

#endif 
