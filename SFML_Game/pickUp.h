#pragma once
#include "entity.h"

class pickUp : public entity
{
public:

	int counterRunning = 0;
	int power = 3;
	bool isPower = true;
	bool isPotion = true;
	bool isChest = true;
	bool isPowerup = false;
	bool chest = true;
	bool destroy = false;
	bool destroy3 = false;
	bool destroy4 = false;
	int potionValue = 5;

	pickUp();
	void update();
	void updateMovement();
	void updateMovement01();
	void updateMovement02();
	void updateMovement03();
	void updateMovement3();
	void updateMovement04();
};
