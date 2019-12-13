#include "pch.h"
#include "Blackboard.h"
#include "health.h"
#include "location.h"

Blackboard* Blackboard::Instance()
{
	if (_instance == NULL) {
		_instance = new Blackboard;
	}

	return _instance;
}

list<game_object> Blackboard::registered;

map<game_object*, string> toDelete;
map<game_object*, string> Blackboard::MessageList;
map<game_object*, string>::iterator it;

Blackboard* Blackboard::_instance;

void Blackboard::Register(game_object obj)
{
	registered.push_back(obj);
}

void Blackboard::Update()
{
	for (it = MessageList.begin(); it != MessageList.end(); it++)
	{
		for (auto a : registered)
		{
			if (it->first->_name == a._name)
			{
				if (a.has_component("health"))
				{
					component* comp = a.getcomponent("health");
					health* hp = dynamic_cast<health*>(comp);

					if (hp->gethealth() > 0)
					{
						hp->reducedhealth(stoi(it->second));
						if (hp->gethealth() != 0)
						{
							cout << stoi(it->second) << " damage dealt. The monster has " << hp->gethealth() << " HP left." << endl;
						}
						else
						{
							cout << "The monster has been slained" << endl;
							location::objects.erase(a._name);
						}
					}
					else {
						cout << "The enemy is no longer exist in this area." << endl;
					}
				}
				/*
				else if (a.has_component("attack"))			// check for more components.
				{
					...
					...
					...
				}*/
				toDelete.insert(make_pair(it->first,it->second));
				break;
			}
		}
	}
	RemovePost();
}

void Blackboard::Post(game_object* sendTo, string msg)
{
	MessageList.insert(make_pair(sendTo, msg));
}

void Blackboard::RemovePost()
{
	for (auto i : toDelete)
	{
		MessageList.erase(i.first);
	}
}

Blackboard::Blackboard()
{
}
