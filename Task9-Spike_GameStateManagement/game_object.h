#pragma once
#include <string>
#include "component.h"
#include <map>
using namespace std;

class game_object
{
public:
	string _name;
	string _desc;
	string _cloc;
	int id;
	game_object();
	game_object(string cloc,string name, string desc);
	void add_component(string name,component* componentname);
	void remove_component(string name);
	bool has_component(string name);
	component* getcomponent(string name);

private:
	map<string, component*> componentList;
};
