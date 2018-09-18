#include "../include/computerView.h" 
#include <SFML/Graphics.hpp>
#include <iostream>

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

void ComputerView::updateSprite(sf::Vector2f ballPosition){//-1 if going up, 1 if going down
    sf::Vector2f paddlePosition = this -> getSpritePosition();
    
    if(paddlePosition.y > -1 && paddlePosition.y < this -> App -> getSize().y - 81){ //keeps paddle inside App bounds
        
        if(ballPosition.y < paddlePosition.y || ballPosition.y > paddlePosition.y + 80){
            
            int direction = (int)(paddlePosition.y - ballPosition.y);
            int multiplier = (~(direction >> 31) == 0) ? 1 : -1; //Isolates sign bit, returns -1 if ball is going up & 1 if ball is going down
            std::cout << multiplier << std::endl;
            
            this -> computerPaddle.move(0.0, 0.1 * multiplier);
            
        }
        
    }
    
}
