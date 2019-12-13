#pragma once
#include "world.h"

class world_box : public world
{
public:
	void load() override;
	void update();
};
