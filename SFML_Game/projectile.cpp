#include "projectile.h"

projectile::projectile()
{
	rect.setSize(sf::Vector2f(5, 10));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Green);
	sprite.setSize(sf::Vector2f(20, 20));
	sprite.setOrigin(sprite.getSize() / 3.f);
}

void projectile::update()
{
	if (direction == 1)    // Up
	{
		rect.move(0, -movementSpeed);
	}
	if (direction == 2)    // Down
	{
		rect.move(0, movementSpeed);
	}
	if (direction == 3)    // Left
	{
		rect.move(-movementSpeed, 0);
	}
	if (direction == 4)    // Right
	{
		rect.move(movementSpeed, 0);
	}

	counterLifetime++;
	if (counterLifetime >= lifeTime)
	{
		destroy = true;
	}

	// Sprite set at Rect
	sprite.setPosition(rect.getPosition());

}

void projectile::update1()
{
	if (direction == 1 )    // Up
	{
		rect.move(0, -movementSpeed);
		rect.move(0, movementSpeed);
		rect.move(-movementSpeed, 0);
		rect.move(movementSpeed, 0);
	}
	if (direction == 2)    // Down
	{
		rect.move(0, -movementSpeed);
		rect.move(0, movementSpeed);
		rect.move(-movementSpeed, 0);
		rect.move(movementSpeed, 0);
	}
	if (direction == 3)    // Left
	{
		rect.move(0, -movementSpeed);
		rect.move(0, movementSpeed);
		rect.move(-movementSpeed, 0);
		rect.move(movementSpeed, 0);
	}
	if (direction == 4)    // Right
	{
		rect.move(0, -movementSpeed);
		rect.move(0, movementSpeed);
		rect.move(-movementSpeed, 0);
		rect.move(movementSpeed, 0);
	}

	counterLifetime++; 
	if (counterLifetime >= lifeTime)
	{
		destroy = true;
	}

	// Sprite set at Rect
	sprite.setPosition(rect.getPosition());

}
