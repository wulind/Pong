#include <SFML/Graphics.hpp>
#include "../include/gameLogic.h"
#include <iostream>

int main(int argc, char** argv)
{
  //Create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong"); //Style doesn't allow for resizing
  
  GameLogic *gameLogic = new GameLogic(&App);
  
  gameLogic -> gameLoop();
  //Done.
  return 0;
}
