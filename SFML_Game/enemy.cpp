#include "enemy.h"
#include <iostream>
using namespace std;

enemy::enemy()
{
	rect.setSize(sf::Vector2f(29, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Black);



	sprite.setSize(sf::Vector2f(29, 32));
	sprite.setTextureRect(sf::IntRect(0, 0, 29, 32));

	rectHp.setSize(sf::Vector2f(100, 10));
	rectHp.setFillColor(sf::Color::Red);

	rectHpBack = rectHp;
	rectHpBack.setFillColor(sf::Color(25, 25, 25, 255));
}


void enemy::update()
{
	sprite.setPosition(rect.getPosition());
	rectHp.setPosition(rect.getPosition().x + 12, rect.getPosition().y + 35);
}

void enemy::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	rectHp.setSize(sf::Vector2f(60.f * hpPercent, rectHp.getSize().y));
}

void enemy::updateMovement()
{
	r = rand() % 4;

	cout << "%d " << r << endl;

	if (r == 0)
	{
		rect.move(-movementSpeed, 0.0f);   //left
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 1, 32, 32));
	}
	if (r == 1)
	{
		rect.move(movementSpeed, 0.0f);   //Right
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 2, 32, 32));
	}
	if (r == 2)
	{
		rect.move(0.0f, -movementSpeed);   //Up
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 3, 32, 32));
	}
	if (r == 3)
	{
		rect.move(0.0f, movementSpeed);   //Down
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 0, 32, 32));
	}
	counterRunning++;
	if (counterRunning == 3)
	{
		counterRunning = 0;
	}
}

void enemy::updateMovement2()
{
	r = rand() % 4;

	cout << "%d " << r << endl;

	if (r == 0)
	{
		rect.move(-movementSpeed2, 0.0f);   //left
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 5, 32, 32));
	}
	if (r == 1)
	{
		rect.move(movementSpeed2, 0.0f);   //Right
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 6, 32, 32));
	}
	if (r == 2)
	{
		rect.move(0.0f, -movementSpeed2);   //Up
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 7, 32, 32));
	}
	if (r == 3)
	{
		rect.move(0.0f, movementSpeed2);   //Down
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 4, 32, 32));
	}
	counterRunning++;
	if (counterRunning == 8)
	{
		counterRunning = 6;
	}
}

void enemy::updateMovement3()
{
	r = rand() % 4;

	cout << "%d " << r << endl;

	if (r == 0)
	{
		rect.move(-movementSpeed, 0.0f);   //left
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 5, 32, 32));
	}
	if (r == 1)
	{
		rect.move(movementSpeed, 0.0f);   //Right
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 6, 32, 32));
	}
	if (r == 2)
	{
		rect.move(0.0f, -movementSpeed);   //Up
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 7, 32, 32));
	}
	if (r == 3)
	{
		rect.move(0.0f, movementSpeed);   //Down
		sprite.setTextureRect(sf::IntRect(counterRunning * 32, 32 * 4, 32, 32));
	}
	counterRunning++;
	if (counterRunning == 5)
	{
		counterRunning = 3;
	}
}
