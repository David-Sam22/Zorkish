#include "pch.h"
#include "game_object.h"

game_object::game_object()
{
}

game_object::game_object(string cloc,string name, string desc)
{
	_name = name;
	_desc = desc;
	_cloc = cloc;
}

void game_object::add_component(string name, component* componentname)
{
	componentList[name] = componentname;
}

void game_object::remove_component(string name)
{
	componentList.erase(name);
}

bool game_object::has_component(string name)
{
	if (componentList.find(name) == componentList.end()) {
		return false;
	}
	else {
		return true;
	}
}

component* game_object::getcomponent(string name)
{
	return componentList[name];
}