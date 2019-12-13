// Task9-Spike_GameStateManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "state_manager.h"
#include "item.h"
#include "inventory.h"
#include "Player.h"
#include <iostream>

using namespace std;

int main()
{
	int input;
	state_manager manager;
	state_mainmenu mainmenu;
	/*
	//----------Iventory and Items--------
	inventory a;

	item* _sword = new item("Sword", "Weapon");
	item* _bow = new item("Bow", "Weapon");
	item* _cookedMeat = new item("Cooked Meat", "Food");
	item* _apple = new item("Apple", "Food");
	item* _armor = new item("Armor", "Cloth");

	a.store_item(*_sword);
	a.store_item(*_bow);
	a.store_item(*_cookedMeat);
	a.store_item(*_apple);
	a.show_inventory();
	*/
	cout << "Welcome to Zorkish: Void World" << endl;
	cout << "This world is simple and pointless. Used it to test Zorkish phase 1 spec.\n" << endl;
	

	mainmenu.handle();

	while (cin >> input)
	{
		system("cls");
		manager.state_selector(input);
	}
	
	/*
	a.show_inventory();

	if (a.checkfor_item(*_armor))
	{
		cout << "\nYou have '" << _armor->item_name << "' in your invetory.\n"<< endl;
	}else
		cout << "\nYou don't have anything called '" << _armor->item_name << "' in your invetory.\n" << endl;

	a.takeOut_item(*_cookedMeat);
	a.show_inventory();
	*/

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
