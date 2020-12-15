#include "background2.h"
#include "background3.h"

background3::background3()
{
	rect.setSize(sf::Vector2f(800, 600));
	rect.setPosition(sf::Vector2f(0, 0));
	sprite.setSize(sf::Vector2f(800, 600));
	//sprite.setScale(0.5, 0.5);
}

void background3::update()
{
	sprite.setPosition(rect.getPosition());
}
