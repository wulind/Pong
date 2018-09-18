#include "../include/computerView.h" 
#include <SFML/Graphics.hpp>

ComputerView::ComputerView(sf::RenderWindow *App, sf::Texture texture){
    this -> App = App;
    
    this -> texture = texture;
    this -> computerPaddle.setTexture(texture);
    this -> computerPaddle.setTextureRect(sf::IntRect(0, 0, 10, 80));
    this -> computerPaddle.setPosition(780.0, this -> App -> getSize().y/2 - 40);
}

sf::Vector2f ComputerView::getSpritePosition(){
    return this -> computerPaddle.getPosition();
}

void ComputerView::drawSprite(){
    (this -> App) -> draw(this -> computerPaddle);
}

void ComputerView::resetSprite(){
    this -> computerPaddle.setPosition(780.0, this -> App -> getSize().y/2 - 40);
}

void ComputerView::updateSprite(float ballHeight){
    this -> computerPaddle.setPosition(780.0, ballHeight);
}
