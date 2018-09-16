#include "../include/computerView.h" 
#include <SFML/Graphics.hpp>

ComputerView::ComputerView(sf::RenderWindow *App, sf::Texture texture){
    this -> App = App;
    
    this -> texture = texture;
    this -> computerPaddle.setTexture(texture);
    computerPaddle.setTextureRect(sf::IntRect(0, 0, 10, 80));
    computerPaddle.setPosition(780.0, this -> App -> getSize().y/2 - 40);//TODO: put in middle of screen
}

sf::Vector2f ComputerView::getSpritePosition(){
    return this -> computerPaddle.getPosition();
}

void ComputerView::drawSprite(){
    (this -> App) -> draw(this -> computerPaddle);
}
