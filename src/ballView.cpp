#include "../include/ballView.h" 
#include <SFML/Graphics.hpp>
#include<iostream>
#include <typeinfo>

BallView::BallView(sf::RenderWindow *App, sf::Texture texture){
    this -> App = App;
    
    this -> texture = texture;
    this -> ball.setTexture(texture);
    ball.setTextureRect(sf::IntRect(0, 0, 10, 10));
    ball.setPosition(this -> App -> getSize().x/2, this -> App -> getSize().y/2);//TODO: put in middle of screen
    
    this -> direction = -1;//direction is 1 if going right (towards computer), -1 if going left (towards user) TODO: coin flip
    
    this -> angle[0] = -0.1;
    this -> angle[1] = 0.0;
}

void BallView::drawSprite(){
    (this -> App) -> draw(this -> ball);
}

/* Moves ball across screen
 * Before ball moves, detect whether or not there is a collision, and whether or not the ball is on screen
 * @paddleLocation: x & y coordinates of paddle that ball is headed towards
 */
void BallView::updateSprite(sf::Vector2f paddleLocation){
    if(this -> detectCollision(paddleLocation) == 1){
        this -> findAngle();
    }
    
    if(ball.getPosition().x < 0 || ball.getPosition().y > this -> App -> getSize().x){//if ball is off screen
        //TODO: make get position a function?
        ball.setPosition(400.0, 300.0);
        
    }
    
    this -> ball.move(this -> angle[0], this -> angle[1]);
    
}

/* Finds angle that ball travels at if there is a collision between ball & paddle
 */
void BallView::findAngle(){   
    this -> angle[0] = 0.1 * this -> direction;
}

/* Detects collision between ball & paddle
 * @paddleLocation: x & y coordinates of paddle that ball is headed towards
 */
int BallView::detectCollision(sf::Vector2f paddleLocation){
    sf::Vector2f ballLocation = this -> ball.getPosition();
    
    if (ballLocation.y > paddleLocation.y -5 && ballLocation.y < paddleLocation.y + 80){//If ball is on track to collide with paddle
        
        if(this -> direction > 0 && ballLocation.x >= 780){//If ball collides with computer's paddle
            this -> direction = -1;
            return 1;
        
        }else if (this -> direction < 0 && ballLocation.x <= 20){//If ball collides with user's paddle
            this -> direction = 1;
            return 1;
            
        }else{
            return 0;
            
        }
    }
    return 0; //If ball is not on track for collision
}
