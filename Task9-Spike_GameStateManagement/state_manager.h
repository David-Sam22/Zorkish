#pragma once

#include <iostream>
#include <string>

#include "state_mainmenu.h"
#include "state_adventure.h"
#include "state_HOF.h"
#include "state_highscore.h"
#include "state_help.h"
#include "state_about.h"


using namespace std;

class state_manager
{
public:
	void state_selector(int input);
	string current_state;
};

