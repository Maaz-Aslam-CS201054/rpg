//#include <iostream>
//
//class enemy
//{
//public:
//	int health = 0;
//	int dmg = 0;
//
//	void heal()
//	{
//		health += 10;
//		std::cout << "my health is now" << health << std::endl;
//
//	}
//};
//
//int main()
//{
//	enemy gol;
//	gol.health = 100;
//	gol.heal();
//
//	return 0;
//}
//
//
//
//





//#include <iostream>
//
//void player(std::string name, int mag, int str, int spd, int luck);
//void enemy(std::string name, int mag, int str, int spd, int luck);
//int main()
//{
//	player("King", 13, 24, 11, 40);
//	std::cout << std::endl;
//	enemy("golem", 4, 44, 6, 0);
//	return 0;
//}
//
//
//void player(std::string name, int mag, int str, int spd, int luck)
//{
//	std::cout << "PLAYER STATS ARE AS FOLLOWS" << std::endl;
//	std::cout << "Name:      " << name << std::endl;
//	std::cout << "magic:     " << mag << std::endl;
//	std::cout << "strength: " << str << std::endl;
//	std::cout << "speed:     " << spd << std::endl;
//	std::cout << "luck:      " << luck << std::endl;
//}
//void enemy(std::string name, int mag, int str, int spd, int luck)
//{
//	std::cout << "ENEMY STATS ARE AS FOLLOWS" << std::endl;
//	std::cout << "Name:      " << name << std::endl;
//	std::cout << "magic:     " << mag << std::endl;
//	std::cout << "strength: " << str << std::endl;
//	std::cout << "speed:     " << spd << std::endl;
//	std::cout << "luck:      " << luck << std::endl;
//}



// //circle
//sf::CircleShape shape(50.0f);
//shape.setFillColor(sf::Color::Red);
//shape.setPosition(sf::Vector2f(100, 100));
//shape.setOutlineThickness(10);
//shape.setOutlineColor(sf::Color::Green);
////rectangle
//sf::RectangleShape rect(sf::Vector2f(120.0f, 40.0f));
//rect.setFillColor(sf::Color::Green);
//rect.setPosition(sf::Vector2f(200.f, 200.f));
//rect.setOutlineThickness(5);
//rect.setOutlineColor(sf::Color::Yellow);
//rect.setRotation(32.6f);
//rect.setOrigin(rect.getSize() / 2.f);
////polygon
//float s;
//int p;
//std::cout << "Enter the size and no of points you want" << std::endl;
//std::cout << "3 points is triangle, 4 points is square and so on..." << std::endl;
//std::cout << "Enter Size: ";
//std::cin >> s;
//std::cout << std::endl;
//std::cout << "Enter No of Points: ";
//std::cin >> p;
//
//sf::CircleShape poly(s, p);
//poly.setFillColor(sf::Color::Magenta);
//poly.setOutlineThickness(10.f);
//poly.setOutlineColor(sf::Color::Yellow);
////Line
//sf::RectangleShape line(sf::Vector2f(150.f, 1.f));
//line.setFillColor(sf::Color::Red);
//line.setPosition(sf::Vector2f(240, 300));
// 
 ////window.draw(shape);
  ////window.draw(rect);
 //window.draw(poly);
 //window.draw(line);