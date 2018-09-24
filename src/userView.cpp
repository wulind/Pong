#include "../include/userView.h" 
#include <SFML/Graphics.hpp>
#include <iostream>

UserView::UserView(sf::RenderWindow *App){
    this -> App = App;
}

void UserView::setSpriteTexture(sf::Texture *texture){
    this -> userPaddle.setTexture(*texture);
    this -> userPaddle.setTextureRect(sf::IntRect(0, 0, 10, 80));
    this -> userPaddle.setPosition(10.0, this -> App -> getSize().y/2 - 40);
}

void UserView::setScore(std::string score, sf::Font *font){
    this -> userScore.setFont(*font);
    this -> userScore.setString(score);
    this -> userScore.setFillColor(sf::Color::White);
    this -> userScore.setPosition(100, 50);
}

void UserView::setScore(std::string score){
    this -> userScore.setString(score);
}

sf::Vector2f UserView::getSpritePosition(){
    return this -> userPaddle.getPosition();
}


void UserView::resetSprite(){
    this -> userPaddle.setPosition(10.0, this -> App -> getSize().y/2 - 40);
}

void UserView::updateSprite(sf::Event event){//TODO: make so that key is passed?
    switch (event.key.code){
        
        case sf::Keyboard::Up:
        
            if(this -> getSpritePosition().y > 0){
                this -> userPaddle.move(0.0, -11.0);
            }
            break;
        
        case sf::Keyboard::Down:
            
            if(this -> getSpritePosition().y < this -> App -> getSize().y - 80){//TODO: make this so that it compares to the window and not a hardcoded value
                this -> userPaddle.move(0.0, 11.0);
            }
            
            break;
    }
}

void UserView::draw(){
    (this -> App) -> draw(this -> userPaddle);
    (this -> App) -> draw(this -> userScore);
    (this -> App) -> draw(this -> title);
}

void UserView::showTitle(sf::Font *font){
    this -> title.setFont(*font);
    this -> title.setString("Pong (To pause, press 'p')");
    this -> title.setCharacterSize(50);
    this -> title.setFillColor(sf::Color::White);
    this -> title.setPosition((this -> App -> getSize()).x/2 - 275, (this -> App -> getSize()).y/2 - 20);

}

void UserView::hideTitle(){
    this -> title.setString("");
}

void UserView::win(sf::Font *font){
    this -> winLose.setFont(*font);
    this -> winLose.setString("Winner (To restart press 'r')");
    this -> winLose.setCharacterSize(50);
    this -> winLose.setFillColor(sf::Color::White);
    this -> winLose.setPosition((this -> App -> getSize()).x/2 - 250, (this -> App -> getSize()).y/2 - 20);
    
    this -> App -> draw(this -> winLose);
}

void UserView::lose(sf::Font *font){
    this -> winLose.setFont(*font);
    this -> winLose.setString("Loser (To restart press 'r')");
    this -> winLose.setCharacterSize(50);
    this -> winLose.setFillColor(sf::Color::White);
    this -> winLose.setPosition((this -> App -> getSize()).x/2 - 250, (this -> App -> getSize()).y/2 - 20);
    
    this -> App -> draw(this -> winLose);
}

void UserView::reset(){
    this -> userScore.setString("0");
    this -> winLose.setString("");
}
