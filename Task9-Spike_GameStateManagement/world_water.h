#pragma once
#include "world.h"


class world_water : public world
{
public:
	void load() override;
	void update();
};

