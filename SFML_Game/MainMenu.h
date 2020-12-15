#pragma once

#include <SFML\Graphics.hpp>
#define Max_main_menu 3

class MainMenu
{
public:

	sf::Text mainMenu1;
	sf::Text mainMenu2;
	sf::Text mainMenu3;
	MainMenu(float width, float height);

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();

	int mainMenuPressed()
	{
		return mainMenuSelected;
	}
	~MainMenu();




private:
	int mainMenuSelected;
	sf::Font font;

};

