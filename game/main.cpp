#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizedVector(sf::Vector2f vector)
{
    //magnitude
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f NormalizedVector;

    NormalizedVector.x = vector.x / m;
    NormalizedVector.y = vector.y / m;

    return NormalizedVector;
}

int main()
{
   
    //------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game" ,sf::Style::Default, settings);
    //------------------INITIALIZE-------------------------------
    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 5.0f;
    sf::Vector2f bulletDirection;


    //------------------LOAD-------------------------------
    //---------- enemy ----------
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;

    if (enemyTexture.loadFromFile("Assets/enemy/Textures/enemysheet.png"))
    {
        std::cout << "enemy Texture loaded" << std::endl;
        enemySprite.setTexture(enemyTexture);
        enemySprite.setPosition(sf::Vector2f(1640, 400));
        //x, y, width, height
        int Xindex = 0;
        int Yindex = 2;
        enemySprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
        enemySprite.scale(sf::Vector2f(3, 3));
    }
    else
    {
        std::cout << "enemy Texture failed to load!!" << std::endl;
    }
    //---------- enemy ----------

    //---------- player ----------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player Texture loaded!!" << std::endl;
        playerSprite.setTexture(playerTexture);
        //x, y, width, height
        int Xindex = 0;
        int Yindex = 0;
        playerSprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
        playerSprite.scale(sf::Vector2f(3, 3));
        playerSprite.setPosition(sf::Vector2f(100, 100));
    }
    else
    {
        std::cout << "Player Texture failed to load!!" << std::endl;
    }
    //---------- player ----------
    //------------------LOAD-------------------------------
  
    //-----------Calculate Direction of Bullet--------------
 /*   sf::Vector2f bulletDirection = enemySprite.getPosition() - bullet.getPosition();
    bulletDirection = NormalizedVector(bulletDirection);*/
    //-----------Calculate Direction of Bullet--------------

    while (window.isOpen()) //game loop
    {
        //------------------UPDATING------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed);

        sf::Vector2f position = playerSprite.getPosition();
        //move left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-2, 0));

        //move right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(2, 0));
        
        //move up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0, -2));

        //move down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 2));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25))); 
            int i = bullets.size() - 1; //i is last element
            bullets[i].setPosition(playerSprite.getPosition()) ;

            /*sf::RectangleShape newBullet(sf::Vector2f(50, 25));
            bullets.push_back(newBullet);*/
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
            bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
            bulletDirection = NormalizedVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);

        }
        //------------------UPDATING------------------------


        //--------------------Draw--------------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite); //cannot ever draw texture
        window.draw(enemySprite);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        window.display();
        //--------------------Draw--------------------------
    }
    
    return 0;
}