#include <SFML/Graphics.hpp>
#include "../include/userView.h"
#include "../include/computerView.h"

int main(int argc, char** argv)
{
  //Create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong", {sf::Style::Close|sf::Style::Titlebar}); //Style doesn't allow for resizing

  //Creating white texture
  sf::Texture texture;
  if(!texture.loadFromFile("../img/white.png"))
      return EXIT_FAILURE;
  
  //Creating view classes
  UserView *userView = new UserView(&App, texture);
  ComputerView *computerView = new ComputerView(&App, texture);
  
  //Creating ball
  sf::Sprite ball;
  ball.setTexture(texture);
  ball.setTextureRect(sf::IntRect(0, 0, 10, 10));
  ball.setPosition(400.f, 300.f);//TODO: put in middle of screen
  
  // start main loop
  while(App.isOpen())
  {
      
    //Process events
    sf::Event Event;
    while(App.pollEvent(Event)){
        switch (Event.type){
            
            case sf::Event::Closed:
                App.close();
                break;
          
            case sf::Event::KeyPressed:
                userView -> updateSprite(Event); //Accesses exact key pressed
                break;
        }
    
    }

    //Clear screen and fill with blue
    App.clear(sf::Color::Black);
    
    //Draw paddles & ball
    computerView -> drawSprite();
    userView -> drawSprite();
    App.draw(ball);
    
    //Display
    App.display();
  }

  //Done.
  return 0;
}
