#include "pch.h"
#include "world_Mountain.h"
#include "location.h"
#include "Player.h"
#include "cmd_manager.h"
#include "inventory.h"
#include "Blackboard.h"

using namespace std;

Blackboard* board = Blackboard::Instance();
location* loc = location::Instance();
Player* pl = Player::Instance();

void world_mountain::load()
{
	pl->setHP(10);
	pl->setLocation("gate");
	update();
}

void world_mountain::update()
{
	cmd_manager cmd;
	string input;
	bool isProcceed = false;

	loc->printScene(pl->getLocation());
	loc->printItem(pl->getLocation());
	while (getline(cin,input))
	{
		if (cmd.checkList(input))
		{
			system("cls");
			cmd.process_input();
			isProcceed = true;
		}

		board->Update();
		if (isProcceed)
		{
			loc->printScene(pl->getLocation());
			loc->printItem(pl->getLocation());
			isProcceed = false;
		}
	}

}
