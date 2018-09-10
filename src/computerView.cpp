#include "../include/computerView.h" 
#include <SFML/Graphics.hpp>

ComputerView::ComputerView(sf::RenderWindow *App, sf::Texture texture){
    this -> App = App;
    
    this -> texture = texture;
    this -> computerPaddle.setTexture(texture);
    computerPaddle.setTextureRect(sf::IntRect(0, 0, 10, 80));
    computerPaddle.setPosition(780.0, 245.0);//TODO: put in middle of screen
}

void ComputerView::drawSprite(){
    (this -> App) -> draw(this -> computerPaddle);
}
