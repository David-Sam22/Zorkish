#include "pch.h"
#include "state_help.h"


void state_help::handle()
{
	cout << "Zorkish :: Main Menu" << endl << "--------------------------------\n" << endl << "Welcome to Zorkish Adventures\n" << endl;
	cout << "The following commands are supported:" << endl;
	
	//phase 1
	cout << "\t- Quit," << endl;
	cout << "\t- High Score" << endl;

	//phase 2
	cout << "\t- [Go]_," << endl;
	cout << "\t- Look at_" << endl;
	cout << "\t- Look in_," << endl;
	cout << "\t- Inventory_," << endl;
	cout << "\t- Open_[with_]," << endl;
	cout << "\t- close_," << endl;
	cout << "\t- attacl_[with_]," << endl;
	cout << "\t- take_[from_]," << endl;
	cout << "\t- put_in_," << endl;
	cout << "\t- drop_," << endl;
	cout << "\t- quit_" << endl;
	cout << "\t- [up arrow] to repeat last command" << endl;

	cout << "Press Enter to return to the Main Menu" << endl;


	//currentstate = "Help";
}

/*
void state_help::show_state()
{
	cout << currentstate;
}
*/