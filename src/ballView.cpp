#include "../include/ballView.h" 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

BallView::BallView(sf::RenderWindow *App, sf::Texture texture){
    this -> App = App;
    
    this -> texture = texture;
    this -> ball.setTexture(texture);
    ball.setTextureRect(sf::IntRect(0, 0, 10, 10));
    ball.setPosition(this -> App -> getSize().x/2, this -> App -> getSize().y/2);
    
    this -> direction = -1;//direction is 1 if going right (towards computer), -1 if going left (towards user) TODO: coin flip
    
    this -> angle[0] = -0.1;
    this -> angle[1] = 0.0;
}

sf::Vector2f BallView::getSpritePosition(){
    return this -> ball.getPosition();
}

void BallView::drawSprite(){
    (this -> App) -> draw(this -> ball);
}

void BallView::resetSprite(){
    ball.setPosition(this -> App -> getSize().x/2, this -> App -> getSize().y/2);
}

/* Moves ball across screen
 * Before ball moves, detect whether or not there is a collision, and whether or not the ball is on screen
 * @paddleLocation: x & y coordinates of paddle that ball is headed towards
 */
int BallView::updateSprite(sf::Vector2f paddleLocation){
    if(this -> detectCollision(paddleLocation) == 1){
        this -> findAngle(paddleLocation);
    }
    
    if(ball.getPosition().x < 0 || ball.getPosition().x > this -> App -> getSize().x){//if ball is off screen
        //TODO: make get position a function?
        
        this -> angle[0] = -0.1;
        this -> angle[1] = 0.0;
        
        return 1;
    }
    
    this -> ball.move(this -> angle[0], this -> angle[1]);
    
    return 2;
    
}

/* Finds angle that ball travels at if there is a collision between ball & paddle
 */
void BallView::findAngle(sf::Vector2f paddleLocation){
    //Normalize interception point between -4, 4
    int normalIntercept = floor((this -> ball.getPosition().y - paddleLocation.y)/10) - 4; //TODO: change paddle size to have balanced intercepts
    //TODO: do this better
    switch(normalIntercept){
        case -4:
            this -> angle[1] = -0.042;
            break;
        case -3:
            this -> angle[1] = -0.034;
            break;
        case -2:
            this -> angle[1] = -0.027;
            break;
        case -1:
            this -> angle[1] = -0.013;
            break;
        case 0:
            this -> angle[1] = 0.0;
            break;
        case 1:
            this -> angle[1] = 0.013;
            break;
        case 2:
            this -> angle[1] = 0.027;
            break;
        case 3:
            this -> angle[1] = 0.042;
            break;
    }

    this -> angle[0] = 0.1 * this -> direction;
}

/* Detects collision between ball & paddle
 * @paddleLocation: x & y coordinates of paddle that ball is headed towards
 */
int BallView::detectCollision(sf::Vector2f paddleLocation){
    sf::Vector2f ballLocation = this -> ball.getPosition();

    if (ballLocation.y > paddleLocation.y - 10 && ballLocation.y < paddleLocation.y + 80){//If ball is on track to collide with paddle

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
