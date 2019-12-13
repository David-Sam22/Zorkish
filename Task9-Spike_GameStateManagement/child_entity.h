#pragma once
#include "component.h"
#include "game_object.h"
#include <map>
#include <string>

class child_entity : public component
{
public:
	child_entity();
	void add_childentity(string child_name,game_object* child);
	map<string, game_object*> childentity;
	map<string, game_object*>::iterator it;
	void show_child();
	virtual void update();
};