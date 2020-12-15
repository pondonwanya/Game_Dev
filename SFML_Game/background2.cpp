#include "background2.h"

background2::background2()
{
	rect.setSize(sf::Vector2f(800, 600));
	rect.setPosition(sf::Vector2f(0, 0));
	sprite.setSize(sf::Vector2f(800, 600));
	//sprite.setScale(0.5, 0.5);
}

void background2::update()
{
	sprite.setPosition(rect.getPosition());
}
