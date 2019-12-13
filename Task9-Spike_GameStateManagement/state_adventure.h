#pragma once
#include "state.h"
#include "world_Mountain.h"
#include "world_water.h"
#include "world_box.h"

class state_adventure: public state
{
public:
	void handle() override;
	void select();
};

