#include "pch.h"
#include "location.h"
#include "game_object.h"
#include "damage.h"
#include "health.h"
#include "child_entity.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <list>
#include "inventory.h"
#include "Message.h"
#include "Blackboard.h"

using namespace std;


location* location::Instance()
{
	if (_instance == NULL) {
		_instance = new location;
	}

	return _instance;
}

multimap<string, string> location::locations;
multimap<string, string> location::connections;
multimap<string, string> location::paths;
multimap<string, string> location::leads;
map<string, game_object*> location::objects;
list<string> location::sequences;
location* location::_instance;


void location::showPlayer()
{
	Player* p = Player::Instance();
	location* loc = location::Instance();
	if (!loc->sequences.empty())
	{
		for (string l : loc->sequences)
		{
			if (l != "")
			{
				cout << l;
				if (l == p->getLocation())
				{
					cout << " - [You are Here]" << endl;
				}
				else
					cout << endl;
			}
		}
	}
}
string location::getDestination(string input, string playerpos)
{
	string result = "";
	multimap<string, string>::iterator it;
	multimap<string, string>::iterator it2;
	
	for (it = location::leads.begin(); it != location::leads.end(); ++it)
	{
		if (it->first == playerpos)
		{
			for (it2 = location::paths.begin(); it2 != location::paths.end(); ++it2)
			{
				if (it->second == it2->second)
				{
					if (input == it2->first)
					{
						result = it->second;
					}
				}
				
			}
		}
	}
	return result;
}

void location::printItem(string player_pos)
{
	inventory* inv = inventory::Instance();
	bool isFound = false;
	for (map<string, game_object*>::iterator it = location::objects.begin(); it != location::objects.end(); ++it)
	{
		if (player_pos == it->second->_cloc)
		{
			isFound = true;
		}
	}
	if (isFound)
	{
		cout << "\nthere are some objects in this area:" << endl;
		for (map<string, game_object*>::iterator it = location::objects.begin(); it != location::objects.end(); ++it)
		{
			if (player_pos == it->second->_cloc)
			{
				cout << " - " << it->first << endl;// << " - " << it->second->_cloc << " - " << it->second->_name << " - " << it->second->id << endl;
			}
		}
		cout << "--------------------------------\n" << endl;
	}
	else
	{
		//cout << "there aren't any objects in this area." << endl;
		cout << "\n--------------------------------\n" << endl;
	}

}

void location::printScene(string player_pos)
{
	multimap<string, string>::iterator it;

	for (it = location::locations.begin(); it != location::locations.end(); ++it)
	{
		if (it->first == player_pos)
		{
			cout << it->second << endl;// ", You are in " << pl->getLocation() << endl;
		}
	}
}

void location::printConnection(string player_pos)
{
	multimap<string, string>::iterator it;

	for (it = location::connections.begin(); it != location::connections.end(); ++it)
	{
		if (it->first == player_pos)
		{
			cout << " - " << it->second << endl;
		}
	}
}
bool location::checkObject(string input)
{
	bool isExist = false;
	for (map<string, game_object*>::iterator it = location::objects.begin(); it != location::objects.end(); ++it)
	{
		if (input == it->second->_name)
		{
			isExist = true;
		}
	}

	return isExist;
}

bool location::checkConnection(string input)
{
	bool isMatch = false;
	Player* p = Player::Instance();
	multimap<string, string>::iterator it;

	for (it = location::connections.begin(); it != location::connections.end(); ++it)
	{
		if (it->first == p->getLocation())
		{
			if (input == it->second)
			{
				isMatch = true;
				break;
			}
		}
	}
	return isMatch;
}
void location::load_desc()
{
	fstream locate("./worlds/location1.txt", ios::binary | ios::in | ios::out);
	string temp;
	string line;
	string first;
	string second;
	if (locate.is_open())
	{
		while (getline(locate, line))
		{
			for (auto a : line)
			{
				if (a == '\r')
				{
					second = temp;
					temp = "";
					continue;
				}
				else if (a == ':')
				{
					first = temp;
					temp = "";
					continue;
				}
				temp += a;
			}
			sequences.push_back(first);
			locations.insert(make_pair(first, second));
		}
		locate.close();
	}
}

void location::load_loc()
{
	fstream loc_file("./worlds/world1.txt", ios::binary | ios::in | ios::out);
	string temp;
	string line;
	string firstblock;
	string secondblock;
	string connect;

	if (loc_file.is_open())
	{
		while (getline(loc_file, line))
		{
			for (auto a : line)
			{
				if (a == '\r')
				{
					connect = temp;
					paths.insert(make_pair(secondblock, connect));
					leads.insert(make_pair(firstblock, connect));
					temp = "";
					continue;
				}
				else if (a == ':')
				{
					firstblock = temp;
					temp = "";
					continue;
				}
				else if (a == '%')
				{
					secondblock = temp;
					connections.insert(make_pair(firstblock, secondblock));
					temp = "";
					continue;
				}
				temp += a;
			}
		}
		loc_file.close();
	}
}

void location::load_entity()
{
	fstream locate("./worlds/entity1.txt", ios::binary | ios::in | ios::out);
	string temp;
	string line;
	string first;
	string second;
	string third;
	string fourth;

	if (locate.is_open())
	{
		while (getline(locate, line))
		{
			bool boolHealth = false;
			bool boolAttack = false;
			bool boolChild = false;
			bool boolLoc = false;
			bool boolMsg = false;

			for (auto a : line)
			{
				if (a == '\r')
				{
		//			second = temp;
		//			cout << second << " 2nd hahah" << endl;
					temp = "";
					continue;
				}
				else if (a == ':')
				{
					first = temp;
			//		cout << first << " firstt" << endl;
					temp = "";
					continue;
				}
				else if (a == '#')
				{
					boolAttack = true;
					temp = "";
					continue;
				}
				else if (a == '$')
				{
					boolHealth = true;
					temp = "";
					continue;
				}
				else if (a == '^')
				{
					boolChild = true;
					temp = "";
					continue;
				}
				else if (a == '/')
				{
					third = temp;
				//	cout << third << " thirrd" << endl;
					temp = "";
					continue;
				}
				else if (a == '@')
				{
				//	cout << temp << endl;
					second = temp;
				//	cout << second << " 2nd hahah" << endl;
					boolLoc = true;
					temp = "";
					continue;
				}
				else if (a == '+')
				{
					fourth = temp;
				//	cout << fourth << " fourrath" << endl;
					temp = "";
					continue;
				}
				else if (a == '*')
				{
					boolMsg = true;
					temp = "";
					continue;
				}

				temp += a;
			}
			objects[first] = new game_object(fourth, first, second);
			if (boolHealth)
			{
				health* tempHealth = new health();
				tempHealth->sethealth(stoi(third));
				objects[first]->add_component("health", tempHealth);
			}
			else if (boolAttack)
			{
				damage* tempDmg = new damage();
				tempDmg->setdamage(stoi(third));
				objects[first]->add_component("attack", tempDmg);
			}
			else if (boolChild)
			{
				child_entity* tempChild = new child_entity();
				tempChild->add_childentity(third, objects[third]);
				objects[first]->add_component("children", tempChild);
			}
			
			if (boolMsg)
			{
				Message* tempMsg = new Message(*objects[first]);
				objects[first]->add_component("attack", tempMsg);
			}
		}
		locate.close();
	}
}


