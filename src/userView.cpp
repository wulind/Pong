#include "../include/userView.h" 
#include <SFML/Graphics.hpp>

/* @param App: pointer to Render Window application
 */
UserView::UserView(sf::RenderWindow *App){
    this -> App = App;
}

/* Sets texture of paddle (among other things that are set values)
 * @param texture: pointer to the desired texture
 */
void UserView::setSpriteTexture(sf::Texture *texture){
    this -> userPaddle.setTexture(*texture);
    this -> userPaddle.setTextureRect(sf::IntRect(0, 0, 10, 80));
    this -> userPaddle.setPosition(10.0, this -> App -> getSize().y/2 - 40);
}

/* Sets font of score text (among other things that are set values)
 * Sets current score value
 * @param score: current score for user
 * @param font: pointer to the desired font
 */
void UserView::setScore(std::string score, sf::Font *font){
    this -> userScore.setFont(*font);
    this -> userScore.setString(score);
    this -> userScore.setFillColor(sf::Color::White);
    this -> userScore.setPosition(100, 50);
}

/* Updates user score value
 * @param score: current user score
 */
void UserView::setScore(std::string score){
    this -> userScore.setString(score);
}

/* Returns current position of user user Paddle
 */
sf::Vector2f UserView::getSpritePosition(){
    return this -> userPaddle.getPosition();
}

/* Resets user paddle position
 */
void UserView::resetSprite(){
    this -> userPaddle.setPosition(10.0, this -> App -> getSize().y/2 - 40);
}

/* Moves user paddle as dictated by user key input
 * @param event: key push event
 */
void UserView::updateSprite(sf::Event event){
    switch (event.key.code){
        
        case sf::Keyboard::Up:
        
            if(this -> getSpritePosition().y > 0){
                this -> userPaddle.move(0.0, -11.0);
            }
            break;
        
        case sf::Keyboard::Down:
            
            if(this -> getSpritePosition().y < this -> App -> getSize().y - 80){
                this -> userPaddle.move(0.0, 11.0);
            }
            
            break;
    }
}

/* Draws user paddle, score text, and title if applicable
 */
void UserView::draw(){
    (this -> App) -> draw(this -> userPaddle);
    (this -> App) -> draw(this -> userScore);
    (this -> App) -> draw(this -> title);
}

/* Sets pong title text to show when drawn
 * @param font: pointer to the desired font 
 */
void UserView::showTitle(sf::Font *font){
    this -> title.setFont(*font);
    this -> title.setString("Pong (To pause, press 'p')");
    this -> title.setCharacterSize(50);
    this -> title.setFillColor(sf::Color::White);
    this -> title.setPosition((this -> App -> getSize()).x/2 - 275, (this -> App -> getSize()).y/2 - 20);

}

/* Hides pong title text if playing
 */
void UserView::hideTitle(){
    this -> title.setString("");
}

/* Sets winning text to show when drawn
 * @param font: pointer to the desired font 
 */
void UserView::win(sf::Font *font){
    this -> winLose.setFont(*font);
    this -> winLose.setString("Winner (To restart press 'r')");
    this -> winLose.setCharacterSize(50);
    this -> winLose.setFillColor(sf::Color::White);
    this -> winLose.setPosition((this -> App -> getSize()).x/2 - 250, (this -> App -> getSize()).y/2 - 20);
    
    this -> App -> draw(this -> winLose);
}

/* Sets losing text to show when drawn
 * @param font: pointer to the desired font 
 */
void UserView::lose(sf::Font *font){
    this -> winLose.setFont(*font);
    this -> winLose.setString("Loser (To restart press 'r')");
    this -> winLose.setCharacterSize(50);
    this -> winLose.setFillColor(sf::Color::White);
    this -> winLose.setPosition((this -> App -> getSize()).x/2 - 250, (this -> App -> getSize()).y/2 - 20);
    
    this -> App -> draw(this -> winLose);
}

/* Resets entire user game
 */
void UserView::reset(){
    this -> userScore.setString("0");
    this -> winLose.setString("");
}
