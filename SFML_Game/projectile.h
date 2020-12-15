#pragma once

#include "entity.h"

class projectile :public entity
{

public:
	int movementSpeed = 10;
	int attactDamage = 1;
	int lifeTime = 50;  //  Projectile Lifetime before being destroyed

	int direction = 0;   //  1-up , 2-down 3-left , 4-right
	bool destroy = false;
	int counterLifetime = 0;

	projectile();
	void update();
	void update1();

};

