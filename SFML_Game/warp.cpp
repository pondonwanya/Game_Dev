#include "warp.h"

warp::warp()
{
	rect.setSize(sf::Vector2f(46, 32));
	rect.setPosition(50, 200);
	rect.setFillColor(sf::Color::Black);
	sprite.setSize(sf::Vector2f(96, 64));
	sprite.setOrigin(sprite.getSize() / 5.f);
	sprite.setTextureRect(sf::IntRect(0, 0, 96, 64));
}

void warp::update()
{
	sprite.setPosition(rect.getPosition());
}

