#pragma once
#include "entity.h"

class warp : public entity
{
public:
	bool isDoor = false;
	bool isDoor2 = false;
	int counterRunning = 0;

	warp();
	void update();
};

