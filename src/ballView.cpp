#include "../include/ballView.h" 
#include <SFML/Graphics.hpp>
#include<iostream>

BallView::BallView(sf::RenderWindow *App, sf::Texture texture){
    this -> App = App;
    
    this -> texture = texture;
    this -> ball.setTexture(texture);
    ball.setTextureRect(sf::IntRect(0, 0, 10, 10));
    ball.setPosition(400.0, 300.0);//TODO: put in middle of screen
    
    this -> direction = -1;//Ball starts out going towards user TODO: coin flip
}

void BallView::drawSprite(){
    (this -> App) -> draw(this -> ball);
}

void BallView::updateSprite(float angle[]){
    std::cout << angle[0] << angle[1] << std::endl;
    this -> ball.move(angle[0], angle[1]);
}

float* BallView::findAngle(sf::Vector2f paddleOrigin){//direction is 1 if going right (towards computer), -1 if going left (towards user)
    float angle[2] = {0.1, 0.0};
    this -> direction = this -> getDirection();
    angle[0] *= this -> direction;
    return angle;
}

//TODO: should this all be implemented in the state?
int BallView::getDirection(){//direction is 1 if going right (towards computer), -1 if going left (towards user)
    if(this -> direction > 0 && this -> ball.getPosition().x >= 780){
        return -1;
    }else if (this -> direction < 0 && this -> ball.getPosition().x <= 20){
        return 1;
    }else{
        return this -> direction;
    }
}
