#include "pickUp.h"

pickUp::pickUp()
{
	rect.setSize(sf::Vector2f(200, 200));
	rect.setPosition(500, 500);
	rect.setFillColor(sf::Color::Red);
	sprite.setSize(sf::Vector2f(63, 64));
	sprite.setTextureRect(sf::IntRect(0, 0, 65.3, 64));
	sprite.setScale(0.5, 0.5);
}

void pickUp::update()
{
	sprite.setPosition(rect.getPosition());
}

void pickUp::updateMovement()
{
	counterRunning++;
	sprite.setTextureRect(sf::IntRect(counterRunning * 63, 0, 63, 64));
	if (counterRunning == 7)
	{
		counterRunning = 0;
	}
}

void pickUp::updateMovement3()
{
	counterRunning++;
	sprite.setTextureRect(sf::IntRect(counterRunning * 48, 48, 48, 48));
	if (counterRunning == 4)
	{
		counterRunning = 3;
	}
}

void pickUp::updateMovement01()
{
	sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));

}

void pickUp::updateMovement02()
{
	sprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
}

void pickUp::updateMovement03()
{
	sprite.setTextureRect(sf::IntRect(0, 96, 32, 32));
}

void pickUp::updateMovement04()
{
	sprite.setTextureRect(sf::IntRect(0, 96, 190, 190));
}

