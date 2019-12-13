#include "pch.h"
#include "state_manager.h"
#include "cmd_manager.h"


void state_manager::state_selector(int input)
{
	state_mainmenu mainmenu;
	state_adventure adventure;
	state_HOF hof;
	state_highscore highscore;
	state_help help;
	state_about about;

	switch (input)
	{
	case 1:
		system("cls");
		adventure.handle();
		break;
	case 2:
		system("cls");
		hof.handle();
		break;
	case 3:
		system("cls");
		help.handle();
		break;
	case 4:
		system("cls");
		about.handle();
		break;
	case 5:
		system("cls");
		cout << ">> Quitting. \nYour adventure has ended without fame or furtune." << endl;
		exit(0);
		break;
	/*case 6:
		cout << "You have entred the magic word and will now see the 'New High Score' screen."<< endl;
		highscore.handle();
		current_state = highscore.currentstate;
		break;*/
	default:
		system("cls");
		mainmenu.handle();
		break;
	}



}
