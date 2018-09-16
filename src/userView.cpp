#include "../include/userView.h" 
#include <SFML/Graphics.hpp>
#include <iostream>

UserView::UserView(sf::RenderWindow *App, sf::Texture texture){
    this -> App = App;
    
    this -> texture = texture;
    this -> userPaddle.setTexture(texture);
    userPaddle.setTextureRect(sf::IntRect(0, 0, 10, 80));
    userPaddle.setPosition(10.0, this -> App -> getSize().y/2 - 40);
}

sf::Vector2f UserView::getSpritePosition(){
    return this -> userPaddle.getPosition();
}

void UserView::drawSprite(){
    (this -> App) -> draw(this -> userPaddle);
}

void UserView::updateSprite(sf::Event event){//TODO: make so that key is passed?
    switch (event.key.code){
        case sf::Keyboard::Up:
            if(this -> userPaddle.getPosition().y > 0){
                this -> userPaddle.move(0.0, -10.0);
            }
            break;
        case sf::Keyboard::Down:
            if(this -> userPaddle.getPosition().y < 516){//TODO: make this so that it compares to the window and not a hardcoded value
                this -> userPaddle.move(0.0, 10.0);
            }
            
            break;
    }
}
