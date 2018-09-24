#include "../include/gameLogic.h" 
#include <iostream>

GameLogic::GameLogic(sf::RenderWindow *_App){
    
    this -> App = _App;
    
    this -> pageState = 1;
    
    //Scores start at 0
    this -> userScore = 0;
    this -> computerScore = 0;
    
    //Creating view classes
    this -> userView = new UserView(_App);
    this -> computerView = new ComputerView(_App);
    this -> ballView = new BallView(_App);
}

GameLogic::~GameLogic(){
    delete this -> userView;
    delete this -> computerView;
    delete this -> ballView;
}

int GameLogic::gameLoop(){
    float timeElapsed;
    
    sf::Texture texture;
    //Creating white texture
    if(!texture.loadFromFile("../data/white.png"))
        return EXIT_FAILURE;
    
    sf::Font font;
    if (!font.loadFromFile("../data/arial.ttf"))
        return EXIT_FAILURE;
    
    this -> userView -> setSpriteTexture(&texture);
    this -> computerView -> setSpriteTexture(&texture);
    this -> ballView -> setSpriteTexture(&texture);
    
    this -> userView -> showTitle(&font);
    
    this -> userView -> setScore(std::to_string(this -> userScore), &font);
    this -> computerView -> setScore(std::to_string(this -> computerScore), &font);
    this -> clock.restart();
    
    
    // start main loop
    while(this -> App -> isOpen()){
        
        if(this -> pageState == 1){
            this -> pageState = 0;
        }
        
        //Process events
        sf::Event Event;
        while(this -> App -> pollEvent(Event)){
            
            switch (Event.type){
                
                case sf::Event::Closed:
                    
                    this -> App -> close();
                    break;
            
                case sf::Event::KeyPressed:
                    if (Event.key.code == sf::Keyboard::R){
                        this -> pageState = 1;
                        this -> userScore = 0;
                        this -> computerScore = 0;
                        this -> userView -> reset();
                        this -> computerView -> reset();
                        
                        this -> ballView -> direction = -1;
                        
                        this -> userView -> showTitle(&font);
                        break;
                    }
                    
                    if (Event.key.code == sf::Keyboard::P){
                        if (this -> pageState == 2){
                            this -> pageState = 0;
                        }else{
                            this -> pageState = 2;
                        }
                        break;
                    }
                    
                    this -> userView -> hideTitle();
                    
                    this -> userView -> updateSprite(Event); //Accesses exact key pressed
                    break;
                
                case sf::Event::LostFocus:
                    this -> pageState = 2;
                    break;
                    
                case sf::Event::GainedFocus:
                    this -> pageState = 0;
                    break;
            }
        }

        
        if(this -> pageState == 0){//Playing game
            this -> detectCollision();
            this -> pageState = this -> ballView -> updateSprite(timeElapsed);
            
            //Match ball height with computer paddle height as ball approaches
            if(this -> ballView -> direction > 0){
                this -> computerView -> updateSprite(this -> ballView -> getSpritePosition(), timeElapsed);
            }
        }

        if(this -> pageState == 1){//someone scored
            this -> updateScore(); 
            
            this -> ballView -> resetSprite();
            this -> userView -> resetSprite();
            this -> computerView -> resetSprite();
        }
        
        //Clear screen and fill with black
        this -> App -> clear(sf::Color::Black);
        
        if(this -> userScore >= 11){
            
            this -> userView -> win(&font);
            this -> pageState = 2;
        }else if(this -> computerScore >= 11){
            
            this -> userView -> lose(&font);
            this -> pageState = 2;
        }
            
        this -> computerView -> draw();
        this -> userView -> draw();
        this -> ballView -> draw();
            
        //Display
        this -> App -> display();
        
        timeElapsed = (this -> clock.getElapsedTime()).asMicroseconds();
        this -> clock.restart();
    }
}


/* Detects collision between ball & paddle
 * Returns 1 if collision detected, else returns 0
 * @paddleLocation: x & y coordinates of paddle that ball is headed towards
 */
int GameLogic::detectCollision(){
    
    sf::Vector2f ballLocation = this -> ballView -> getSpritePosition();
    sf::Vector2f paddleLocation;
    if(this -> ballView -> direction < 0){
        paddleLocation = this -> userView -> getSpritePosition();
    }else{
        paddleLocation = this -> computerView -> getSpritePosition();
    }
        

    if (ballLocation.y > paddleLocation.y - 10 && ballLocation.y < paddleLocation.y + 80){//If ball is on track to collide with paddle

        if(this -> ballView -> direction > 0 && ballLocation.x >= 780){//If ball collides with computer's paddle
            this -> ballView -> direction = -1;
            
            this -> findBallAngle(ballLocation, paddleLocation);
            
            return 1;
        
        }else if (this -> ballView -> direction < 0 && ballLocation.x <= 20){//If ball collides with user's paddle
            this -> ballView -> direction = 1;
            
            this -> findBallAngle(ballLocation, paddleLocation);
            
            return 1;
            
        }
    }
    return 0; //If ball is not on track for collision
}


/* Finds angle that ball travels at if there is a collision between ball & paddle
 */
void GameLogic::findBallAngle(sf::Vector2f ballLocation, sf::Vector2f paddleLocation){
    
    //Normalize interception point between -4, 4
    int normalIntercept = floor((ballLocation.y - paddleLocation.y)/10) - 4; //TODO: change paddle size to have balanced intercepts
    //TODO: do this better
    switch(normalIntercept){
        case -4:
            this -> ballView -> angle[1] = -0.002;
            break;
        case -3:
            this -> ballView -> angle[1] = -0.001;
            break;
        case -2:
            this -> ballView -> angle[1] = -0.00063;
            break;
        case -1:
            this -> ballView -> angle[1] = -0.00052;
            break;
        case 0:
            this -> ballView -> angle[1] = 0.0;
            break;
        case 1:
            this -> ballView -> angle[1] = 0.00063;
            break;
        case 2:
            this -> ballView -> angle[1] = 0.00089;
            break;
        case 3:
            this -> ballView -> angle[1] = 0.0019;
            break;
    }

    this -> ballView -> angle[0] = 0.0005 * this -> ballView -> direction;
}

/*Updates score when someone scores
 */
void GameLogic::updateScore(){
    if(this -> userScore < 11 && this -> computerScore < 11){
        
        if(this -> ballView -> direction == 1){
            ++this -> userScore;
            this -> userView -> setScore(std::to_string(this -> userScore));
        
        }else{
            ++this -> computerScore;
            this -> computerView -> setScore(std::to_string(this -> computerScore));
        
        }
    }
    
}
