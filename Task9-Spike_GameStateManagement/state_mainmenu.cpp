#include "pch.h"
#include "state_mainmenu.h"


using namespace std;

void state_mainmenu::handle()
{
	cout << "Zorkish :: Main Menu" << endl << "--------------------------------\n" << endl << "Welcome to Zorkish Adventures\n" << endl;
	cout << "1. Select Adventure and Play" << endl;
	cout << "2. Hall of Fame" << endl;
	cout << "3. Help" << endl;
	cout << "4. About" << endl;
	cout << "5. Quit" << endl;

	cout << "\nSelect 1-5: ";

	select();
	//currentstate = "Main Menu";
}

void state_mainmenu::select()
{
	int selector;
	state_adventure adv;
	state_HOF hof;
	state_help help;
	state_about about;
	state_highscore hscore;

	cin >> selector;
	switch (selector)
	{
	case 1:
		adv.handle();
		break;
	case 2:		
		hof.handle();
		break;
	case 3:		
		help.handle();
		break;
	case 4:		
		about.handle();
	case 5:
		cout << ">> Quitting. \nYour adventure has ended without fame or furtune." << endl;
		exit(0);
	case 6:		
		hscore.handle();
		break;
	default:
		handle();
		break;
	}
}

/*
void state_mainmenu::show_state()
{
	cout << currentstate;
}
*/