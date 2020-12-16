#pragma once

#include "entity.h"
#include "random.h"

class enemy : public entity
{
public:
	int movementSpeed = 2;
	int movementSpeed2 = 1;
	int movementLength = 50;
	int attactDamage = 2;
	int counterRunning = 0;
	int counterRunning2 = 6;
	int counterRunning3 = 3;
	int direction = 0;   //  1-up , 2-down 3-left , 4-right
	int counter = 0;
	int hp = 3;
	bool alive = true;
	int enemyValue = 1;
	int hpMax = 30;
	int randomTime, r;
	sf::Vector2f posEnemy = rect.getPosition();

	enemy();

	void update();
	void updateHpBar();
	void updateMovement();
	void updateMovement2();
	void updateMovement3();
	void updateMovement4();
};

