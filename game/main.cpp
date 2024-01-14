#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    //------------------INITIALIZE-------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game"
                           ,sf::Style::Default, settings);
            //circle
    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100,100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Green);
            //rectangle
    sf::RectangleShape rect(sf::Vector2f(120.0f,40.0f));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(sf::Vector2f(200.f,200.f));
    rect.setOutlineThickness(5);
    rect.setOutlineColor(sf::Color::Yellow);
    rect.setRotation(32.6f);
    rect.setOrigin(rect.getSize() / 2.f);
            //polygon
    float s;
    int p;
    std::cout << "Enter the size and no of points you want" << std::endl;
    std::cout << "3 points is triangle, 4 points is square and so on..." << std::endl;
    std::cout << "Enter Size: ";
    std::cin  >> s;
    std::cout << std::endl;
    std::cout << "Enter No of Points: ";
    std::cin  >> p;

    sf::CircleShape poly(s, p);
    poly.setFillColor(sf::Color::Magenta);
    poly.setOutlineThickness(10.f);
    poly.setOutlineColor(sf::Color::Yellow);
             //Line
    sf::RectangleShape line(sf::Vector2f(150.f, 1.f));
    line.setFillColor(sf::Color::Red);
    line.setPosition(sf::Vector2f(240, 300));


    //------------------INITIALIZE-------------------------------
    
    
    
    while (window.isOpen()) //game loop
    {
        //------------------UPDATING------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //------------------UPDATING------------------------


        //--------------------Draw--------------------------
        window.clear(sf::Color::Black);
        //window.draw(shape);
        //window.draw(rect);
        window.draw(poly);
        window.draw(line);
        window.display();
        //--------------------Draw--------------------------
    }
    
    return 0;
}