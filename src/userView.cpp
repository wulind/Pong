#include "../include/userView.h" 
#include <SFML/Graphics.hpp>
#include <iostream>

UserView::UserView(sf::RenderWindow *App){
    this -> App = App;
}

void UserView::setSpriteTexture(sf::Texture texture){
    this -> userPaddle.setTexture(texture);
    this -> userPaddle.setTextureRect(sf::IntRect(0, 0, 10, 80));
    this -> userPaddle.setPosition(10.0, this -> App -> getSize().y/2 - 40);
}

void UserView::setScore(std::string score, sf::Font *font){
    this -> userScore.setFont(*font);
    this -> userScore.setString(score);
    this -> userScore.setFillColor(sf::Color::White);
    this -> userScore.setPosition(100, 50);
}

void UserView::setScore(std::string score){
    this -> userScore.setString(score);
}

sf::Vector2f UserView::getSpritePosition(){
    return this -> userPaddle.getPosition();
}

void UserView::draw(){
    (this -> App) -> draw(this -> userPaddle);
    (this -> App) -> draw(this -> userScore);
}

void UserView::resetSprite(){
    this -> userPaddle.setPosition(10.0, this -> App -> getSize().y/2 - 40);
}

void UserView::updateSprite(sf::Event event){//TODO: make so that key is passed?
    switch (event.key.code){
        
        case sf::Keyboard::Up:
        
            if(this -> getSpritePosition().y > 0){
                this -> userPaddle.move(0.0, -11.0);
            }
            break;
        
        case sf::Keyboard::Down:
            
            if(this -> getSpritePosition().y < this -> App -> getSize().y - 80){//TODO: make this so that it compares to the window and not a hardcoded value
                this -> userPaddle.move(0.0, 11.0);
            }
            
            break;
    }
}
