#pragma once

#include "entity.h"
#include <string>

class textDisplay : public entity
{
public:
	float movementSpeed = 2;
	std::string myString = "Default";
	int counter = 0;
	int lifeTime = 100;
	bool destroy = false;

	textDisplay();
	void update();
};

