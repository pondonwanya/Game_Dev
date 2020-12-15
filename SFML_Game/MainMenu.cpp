#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	sf::Font font;
	font.loadFromFile("karmatic/ka1.ttf");
	printf("Yoooooooooooooooooooooooo");
	//Play
	mainMenu1.setFont(font);
	mainMenu1.setFillColor(sf::Color::Black);
	mainMenu1.setString("PLAY");
	mainMenu1.setCharacterSize(40);
	mainMenu1.setPosition(100, 100);

	//Score
	mainMenu2.setFont(font);
	mainMenu2.setFillColor(sf::Color::Black);
	mainMenu2.setString("SCORE");
	mainMenu2.setCharacterSize(40);
	mainMenu2.setPosition(100, 200);

	//Play
	mainMenu3.setFont(font);
	mainMenu3.setFillColor(sf::Color::Black);
	mainMenu3.setString("QUIT");
	mainMenu3.setCharacterSize(40);
	mainMenu3.setPosition(100, 300);

	mainMenuSelected = 0;
}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu1);
	}
}

void MainMenu::moveUp()
{
	/*if (mainMenuSelected - 1 >= -1)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}*/
}

void MainMenu::moveDown()
{
	/*if (mainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected++;
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}*/
}

MainMenu::~MainMenu()
{
}
