#include "pch.h"
#include "state_adventure.h"
#include "location.h"
#include "Player.h"


void state_adventure::handle()
{
	cout << "Zorkish :: Select Adventure" << endl << "--------------------------------\n" << endl;
	cout << "Choose your adventure:" << endl;

	cout << "1. Mountain World" << endl;
	cout << "2. Water World" << endl;
	cout << "3. Box World" << endl;

	cout << "\nSelect 1-3: ";

	select();
}

void state_adventure::select()
{
	int selector;
	world_mountain mountainWorld;
	world_water	waterWorld;
	world_box boxWorld;
	cin >> selector;

	switch (selector)
	{
	case 1:
		system("cls");
		mountainWorld.load();
		break;
	case 2:
		system("cls");
		waterWorld.load();
		break;
	case 3:
		system("cls");
		boxWorld.load();
		break;
	default:
		handle();
		break;
	}

	
}

/*
void state_adventure::show_state()
{
	cout << currentstate;
}*/
