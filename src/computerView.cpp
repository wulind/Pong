#include "../include/computerView.h" 
#include <SFML/Graphics.hpp>

/*@param App: pointer to Render Window application
 */
ComputerView::ComputerView(sf::RenderWindow *App){
    this -> App = App;
}

/* Sets texture of paddle (among other things that are set values)
 * @param texture: pointer to the desired texture
 */
void ComputerView::setSpriteTexture(sf::Texture *texture){
    this -> computerPaddle.setTexture(*texture);
    this -> computerPaddle.setTextureRect(sf::IntRect(0, 0, 10, 80));
    this -> computerPaddle.setPosition(780.0, this -> App -> getSize().y/2 - 40);   
}

/* Sets font of score text (among other things that are set values)
 * Sets current score value
 * @param score: current score for computer
 * @param font: pointer to the desired font
 */
void ComputerView::setScore(std::string score, sf::Font *font){
    this -> computerScore.setFont(*font);
    this -> computerScore.setString(score);
    this -> computerScore.setFillColor(sf::Color::White);
    this -> computerScore.setPosition(700, 50);
}

/* Updates user score value
 * @param score: current computer score
 */
void ComputerView::setScore(std::string score){
    this -> computerScore.setString(score);
}

/* Returns current position of user computer Paddle
 */
sf::Vector2f ComputerView::getSpritePosition(){
    return this -> computerPaddle.getPosition();
}

void ComputerView::draw(){
    (this -> App) -> draw(this -> computerPaddle);
    
    (this -> App) -> draw(this -> computerScore);
}

/* Resets user paddle position
 */
void ComputerView::resetSprite(){
    this -> computerPaddle.setPosition(780.0, this -> App -> getSize().y/2 - 40);
}

/* Moves user paddle as dictated by ball movement
 * @param ballPosition: location of ball
 * @param deltaMs: miliseconds that have gone by since last loop (make up for computer speeds)
 */
void ComputerView::updateSprite(sf::Vector2f ballPosition, float deltaMs){//-1 if going up, 1 if going down
    sf::Vector2f paddlePosition = this -> getSpritePosition();
    
    if(paddlePosition.y > 1 && paddlePosition.y < this -> App -> getSize().y - this -> computerPaddle.getGlobalBounds().width - 1){ //keeps paddle inside App bounds
        
        if(ballPosition.y < paddlePosition.y - 10 || ballPosition.y > paddlePosition.y + 90){ //Made area of paddle that detects ball a little bigger than the actual paddle to make it easier to win
            
            int direction = (int)(paddlePosition.y - ballPosition.y);
            int multiplier = (~(direction >> 31) == 0) ? 1 : -1; //Isolates sign bit, returns -1 if ball is going up & 1 if ball is going down
            
            this -> computerPaddle.move(0.0, 0.02 * multiplier * deltaMs);
            
        }
        
    }else{//paddle moved outside bounds
        if(paddlePosition.y <= 0){
            this -> computerPaddle.move(0.0, 1);
        }else{
            this -> computerPaddle.move(0.0, -1);
        }
    }
    
}

/* Resets entire computer View
 */
void ComputerView::reset(){
    this -> computerScore.setString("0");
}

