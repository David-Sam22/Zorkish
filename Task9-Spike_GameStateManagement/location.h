#pragma once
#include <string>
#include <map>
#include <list>
#include "game_object.h"
using namespace std;

class location
{
public:
	static location* Instance();

	static multimap<string, string> locations;
	static multimap<string, string> connections;
	static multimap<string, string> paths;
	static multimap<string, string> leads;
	static map<string, game_object*> objects;
	static list<string> sequences;

	void showPlayer();

	string getDestination(string input, string playerpos);

	void printItem(string player_pos);

	void printScene(string player_pos);

	void printConnection(string player_pos);

	bool checkObject(string input);

	bool checkConnection(string input);

//	void getNextLocation();

	static void load_desc();
	static void load_loc();

	void load_entity();

	location() { load_desc(); load_loc(); load_entity(); };

private:
	static location* _instance;
};