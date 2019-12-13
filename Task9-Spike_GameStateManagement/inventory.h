#pragma once

#include <iostream>
#include <vector>
#include "game_object.h"

using namespace std;

class inventory
{
public:
	static inventory* Instance();
	static vector<game_object> xinventory;

	void store_item(game_object& x);
	void takeOut_item(game_object& x);
	bool checkfor_item(string x);
	void show_inventory();
private:
	static inventory* _instance;
};

