#ifndef USERVIEW_H
#define USERVIEW_H  

#include <SFML/Graphics.hpp>

class UserView{
    
    private:
        sf::Text title;
        
        sf::RenderWindow *App;
        sf::Sprite userPaddle;
        sf::Text userScore;
        sf::Text winLose;
        
    public:
        
        UserView(sf::RenderWindow *App);
        
        void setSpriteTexture(sf::Texture *texture);
        void setScore(std::string score, sf::Font *font);
        void setScore(std::string score);
        
        sf::Vector2f getSpritePosition();
        
        void draw();
        
        void resetSprite();
        void updateSprite(sf::Event event);
        
        void showTitle(sf::Font *font);
        void hideTitle();
        
        void win(sf::Font *font);
        void lose(sf::Font *font);
        void reset();
        
};

#endif 
