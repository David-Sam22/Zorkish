#pragma once
#include "state.h"

#include "state_mainmenu.h"
#include "state_adventure.h"
#include "state_HOF.h"
#include "state_highscore.h"
#include "state_help.h"
#include "state_about.h"

class state_mainmenu: public state
{
public:
	void handle() override;
	void select();
	//void show_state() override;
	//string currentstate;
};

