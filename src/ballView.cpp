#include "../include/ballView.h" 
#include <SFML/Graphics.hpp>

/*@param App: pointer to Render Window application
 */
BallView::BallView(sf::RenderWindow *App){
    
    this -> App = App;
    
    this -> direction = -1;//direction is 1 if going right (towards computer), -1 if going left (towards user)
    
    this -> angle[0] = -0.1;
    this -> angle[1] = 0.0;
}

/* Sets texture of ball (among other things that are set values)
 * @param texture: pointer to the desired texture
 */
void BallView::setSpriteTexture(sf::Texture *texture){
    
    this -> ball.setTexture(*texture);
    ball.setTextureRect(sf::IntRect(0, 0, 10, 10));
    ball.setPosition(this -> App -> getSize().x/2, this -> App -> getSize().y/2);
}

/* Returns current position of user user Paddle
 */
sf::Vector2f BallView::getSpritePosition(){
    
    return this -> ball.getPosition();
}

/* Draws user paddle, score text, and title if applicable
 */
void BallView::draw(){
    
    (this -> App) -> draw(this -> ball);
}

/* Resets ball direction and position
 */
void BallView::resetSprite(){
    
    this -> direction = -1;
    this -> ball.setPosition(this -> App -> getSize().x/2, this -> App -> getSize().y/2);
}

/* Moves ball across screen
 * @param paddleLocation: x & y coordinates of paddle that ball is headed towards
 */
int BallView::updateSprite(float deltaMs){
    
    if(ball.getPosition().x < 0 || ball.getPosition().x > this -> App -> getSize().x){//if ball is off side of screen
        
        this -> angle[0] = -0.0005;
        this -> angle[1] = 0.0;
        
        return 1;
    }
    
    if(ball.getPosition().y < 0 || ball.getPosition().y > this -> App -> getSize().y){//If ball is off top or bottom of screen
        this -> angle[1] *= -1;
    }
    
    this -> ball.move(this -> angle[0] * deltaMs, this -> angle[1] * deltaMs);
    
    return 0;
    
}



