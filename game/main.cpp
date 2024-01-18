#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    //------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game" ,sf::Style::Default, settings);
    //------------------INITIALIZE-------------------------------
    
    //------------------LOAD-------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player Images loaded!!" << std::endl;
        playerSprite.setTexture(playerTexture);
        //x, y, width, height
        int Xindex = 0;
        int Yindex = 0;
        playerSprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
        playerSprite.scale(sf::Vector2f(3, 3));
    }
    else
    {
        std::cout << "Player Image failed to load!!" << std::endl;
    }
    //------------------LOAD-------------------------------
  
    while (window.isOpen()) //game loop
    {
        //------------------UPDATING------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        sf::Vector2f position = playerSprite.getPosition();
        //move left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        //move right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        
        //move up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));

        //move down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));

        //------------------UPDATING------------------------


        //--------------------Draw--------------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite); //cannot ever draw texture
        window.display();
        //--------------------Draw--------------------------
    }
    
    return 0;
}