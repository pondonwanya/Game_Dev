#include "background.h"

background::background()
{
	rect.setSize(sf::Vector2f(800, 600));
	rect.setPosition(sf::Vector2f(0, 0));
	sprite.setSize(sf::Vector2f(800, 600));
}

void background::update()
{
	sprite.setPosition(rect.getPosition());
}
