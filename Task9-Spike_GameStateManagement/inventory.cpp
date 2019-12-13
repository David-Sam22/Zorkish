#include "pch.h"
#include "inventory.h"
#include "game_object.h"
#include <vector>

using namespace std;

inventory* inventory::_instance;
inventory* inventory::Instance()
{
	if (_instance == NULL) {
		_instance = new inventory;
	}

	return _instance;
}

vector<game_object> inventory::xinventory;

void inventory::store_item(game_object& x)
{
	xinventory.push_back(x);
}

void inventory::takeOut_item(game_object& x)
{
	for (int i = 0; i < xinventory.size(); i++)
	{
		if (xinventory.at(i)._name == x._name)
		{
			xinventory.erase(xinventory.begin() + i);
		}
	}
}

bool inventory::checkfor_item(string x)
{
	for (auto i : xinventory)
	{
		if (i._name == x)
		{
			return true;
		}
	}
	return false;
}

void inventory::show_inventory()
{
	cout << "\nInventory:\n" << endl;
	for (auto i : xinventory)
	{
		cout << "\t" << i._name << " - " << i._desc << endl;
	}
	cout << "--------------------------------\n" << endl;
}
