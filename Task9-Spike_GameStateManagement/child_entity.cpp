#include "pch.h"
#include "child_entity.h"

child_entity::child_entity()
{
}

void child_entity::add_childentity(string child_name, game_object * child)
{
	childentity[child_name] = child;
}

void child_entity::show_child()
{
	cout << "\Inside this item has:\n" << endl;
	for (it = childentity.begin(); it != childentity.end(); it++)
	{
		cout << "\t- " << it->second->_name << endl;
	}
	cout << "--------------------------------\n" << endl;
}


void child_entity::update()
{
}
