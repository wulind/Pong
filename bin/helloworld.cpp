#include <SFML/Graphics.hpp>
#include "../include/userView.h"
#include "../include/computerView.h"
#include "../include/ballView.h"
#include <iostream>

int main(int argc, char** argv)
{
  //Create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong", {sf::Style::Close|sf::Style::Titlebar}); //Style doesn't allow for resizing

  //Game state
  //0: not playing
  //1: initializing
  //2: playing
  int gameState = 0; //Game not playing
  
  //Creating white texture
  sf::Texture texture;
  if(!texture.loadFromFile("../img/white.png"))
      
      return EXIT_FAILURE;
  
  //Creating view classes
  UserView *userView = new UserView(&App, texture);
  ComputerView *computerView = new ComputerView(&App, texture);
  BallView *ballView = new BallView(&App, texture);
  
  // start main loop
  while(App.isOpen())
  {
      
    //Process events
    sf::Event Event;
    while(App.pollEvent(Event)){
        
        switch (Event.type){
            
            case sf::Event::Closed:
                gameState = 0; //TODO: why is this necessary?
                App.close();
                break;
          
            case sf::Event::KeyPressed:
                userView -> updateSprite(Event); //Accesses exact key pressed
                break;
        }
    }

    if(ballView -> direction < 0){
        
        gameState = ballView -> updateSprite(userView -> getSpritePosition());
        
    }else{
        
        gameState = ballView -> updateSprite(computerView -> getSpritePosition());
        
        //Match ball height with computer paddle height as ball approaches
        computerView -> updateSprite(ballView -> getSpritePosition());
    }
    
    if(gameState == 1){
        
        ballView -> resetSprite();
        userView -> resetSprite();
        computerView -> resetSprite();
    }
    
    //Clear screen and fill with black
    App.clear(sf::Color::Black);
    
    //Draw paddles & ball
    computerView -> drawSprite();
    userView -> drawSprite();
    ballView -> drawSprite();
    
    //Display
    App.display();
    
  }
  
  //Done.
  return 0;
}
