#include "pch.h"
#include "cmd_manager.h"
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include "inventory.h"
#include "location.h"
#include "player.h"
#include <algorithm>
#include <map>
#include "child_entity.h"
#include "Message.h"

using namespace std;

cmd_manager::cmd_manager()
{
	loadFile();
}

multimap<string, string> cmd_manager::cmd_map;
string cmd_manager::userinput;
string cmd_manager::usercmd;

void cmd_manager::loadFile()
{
	fstream cmd_file("./worlds/command.txt", ios::binary | ios::in | ios::out);
	string line;
	string temp = "";
	string first;
	string second;

	if (cmd_file.is_open())
	{
		while (getline(cmd_file, line))
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
			cmd_map.insert(make_pair(first, second));
		}
		cmd_file.close();
	}
}

void cmd_manager::printDebug()
{
	location* loc = location::Instance();
	cout << "\nLocate Player:\n" << endl;
	loc->showPlayer();
	cout << "--------------------------------\n" << endl;
}

void cmd_manager::printHelp()
{
	cout << "\nHelp:\n" << endl;
	multimap<string, string>::iterator it;

	for (it = cmd_manager::cmd_map.begin(); it != cmd_manager::cmd_map.end(); ++it)
	{
		cout << "`" << it->first << "`" << " - " << it->second << endl;
	}
	cout << "--------------------------------\n" << endl;
}

void cmd_manager::printInventory()
{
	inventory* inv = inventory::Instance();
	inv->show_inventory();
}

void cmd_manager::printAlias()
{
	cout << "\nAlias:\n" << endl;
	multimap<string, string>::iterator it;
	multimap<string, string>::iterator temp;
	string second;
	string input;
	bool isMatch = false;

	for (it = cmd_manager::cmd_map.begin(); it != cmd_manager::cmd_map.end(); ++it)
	{
		cout << " - " << it->first << " :: " << it->second << endl;
	}

	cout << "please type in the exist command, you wish to map : " ;
	cin >> input;

	transform(input.begin(), input.end(), input.begin(), ::tolower);
	for (it = cmd_manager::cmd_map.begin(); it != cmd_manager::cmd_map.end(); ++it)
	{
		if (input == it->first)
		{
			temp = it;
			second = it->second;
			isMatch = true;
		}
	}
	if (isMatch)
	{
		cout << "new command: " ;
		cin >> input;
		cmd_manager::cmd_map.insert(make_pair(input, second));
		cmd_manager::cmd_map.erase(temp);
	}
	else
		cout << "Exist command not match.\n" << endl;
	cout << "--------------------------------\n" << endl;
}

void cmd_manager::printLook()
{
	location* loc = location::Instance();
	Player* pl = Player::Instance();
	cout << "\nYou see:\n" << endl;
	loc->printConnection(pl->getLocation());
	cout << "--------------------------------\n" << endl;
}

bool cmd_manager::checkList(string input)
{
	bool isFound = false;
	multimap<string, string>::iterator it;
	string my_str = input;
	location* loc = location::Instance();
	transform(my_str.begin(), my_str.end(), my_str.begin(), ::tolower);
	setInput(my_str);
	my_str += " ";
	string cmd = "";

	string first_block = "";
	string second_block = "";
	string third_block = "";
	string fourth_block = "";

	for (auto x : my_str)
	{
		if (x == ' ')
		{
			if (first_block == "")
			{
				if (cmd == "look" || cmd == "open" || cmd == "take" || cmd == "put" || cmd == "go" || cmd == "attack")
				{
					first_block = cmd + ' ';
				}
			}
			else if (second_block == "")
			{
				if (cmd == "at" || cmd == "in" || cmd == "the" || cmd == "back")
				{
					second_block = cmd + ' ';
				}
				else if (loc->checkConnection(cmd))
				{
					second_block += "* ";
				}
				else if (loc->checkObject(cmd))
				{
					second_block += "^ ";
				}
			}
			else if (third_block == "")
			{
				if (cmd == "from" || cmd == "in" || cmd == "the")
				{
					third_block = cmd + ' ';
				}
				else if (loc->checkConnection(cmd))
				{
					third_block += "* ";
				}
				else if (loc->checkObject(cmd))
				{
					third_block += "^ ";
				}
			}
			else if (fourth_block == "")
			{
				if (loc->checkObject(cmd))
				{
					fourth_block += "^ ";
				}
			}
			cmd = "";
		}
		else
		{
			cmd = cmd + x;
		}
	}
	string user = first_block + second_block + third_block + fourth_block;
	if (user == "")
	{
		user = getInput();
	}

	for (it = cmd_manager::cmd_map.begin(); it != cmd_manager::cmd_map.end(); ++it)
	{
		if (it->first == user)
		{
			setCommand(it->second);
			isFound = true;
		}
	}
//	cout << first_block << second_block << third_block << fourth_block << endl;
	
	return isFound;
}

void cmd_manager::process_input()
{
	location* loc = location::Instance();
	Player* pl = Player::Instance();
	inventory* inv = inventory::Instance();
	map<string, game_object*>::iterator it;
	string my_str = getInput() + " ";
	string output = getCmd();
	string cmd = "";
	string inputCon = "";
	string inputItem1 = "";
	string inputItem2 = "";

	for (auto x : my_str)
	{
		if (x == ' ')
		{
			if (loc->checkConnection(cmd))
			{
				inputCon = cmd;
				break;
			}
			else if (loc->checkObject(cmd))
			{
				if (inputItem1 == "")
				{
					inputItem1 = cmd;
					if (output == "takeItem" || output == "lookItemAt" || output == "lookItemIn")
					{
						break;
					}
				}
				else if (inputItem2 == "")
				{
					inputItem2 = cmd;
				}
			}
			cmd = "";
		}
		else
		{
			cmd = cmd + x;
		}
	}
	if (output == "debug")
	{
		printDebug();
	}
	else if (output == "help")
	{
		printHelp();
	}
	else if (output == "look")
	{
		printLook();
	}
	else if (output == "inventory")
	{
		printInventory();
	}
	else if (output == "alias")
	{
		printAlias();
	}
	else if (output == "go")
	{
		if (loc->checkConnection(inputCon))
		{
			pl->setPrevLocation(pl->getLocation());
			pl->setLocation(loc->getDestination(inputCon, pl->getLocation()));
		}
	}
	else if (output == "back")
	{
		pl->setLocation(pl->getPrevLocation());
	}
	else if (output == "lookItemIn")
	{
		for (it = location::objects.begin(); it != location::objects.end(); ++it)
		{
			if (pl->getLocation() == it->second->_cloc || it->second->_cloc == "Player")
			{
				if (inputItem1 == it->second->_name)
				{
					if (it->second->has_component("children"))
					{
						component* tempComp = it->second->getcomponent("children");
						child_entity* tempChild = dynamic_cast<child_entity*>(tempComp);
						tempChild->show_child();
					}
				}
			}
		}
	}
	else if (output == "lookItemAt")
	{
		for (it = location::objects.begin(); it != location::objects.end(); ++it)
		{
			if (pl->getLocation() == it->second->_cloc || it->second->_cloc == "Player")
			{
				if (it->first == inputItem1)
				{
					cout << "\n" << it->second->_name << " :" << it->second->_desc << endl;
				}
			}
		}

		cout << "--------------------------------\n" << endl;
	}
	else if (output == "takeItem")
	{
		for (it = location::objects.begin(); it != location::objects.end(); ++it)
		{
			if (pl->getLocation() == it->second->_cloc)
			{
				if (!it->second->has_component("health"))
				{
					if (it->first == inputItem1)
					{
						inv->store_item(*it->second);
						it->second->_cloc = "Player";
					}
				}
			}
		}
	}
	else if (output == "takeItemFrom")
	{
		if (location::objects.find(inputItem2)->second->_cloc == "Player" || location::objects.find(inputItem2)->second->_cloc == pl->getLocation())
		{
			if (!location::objects.find(inputItem2)->second->has_component("childen"))
			{
				if (location::objects.find(inputItem1)->second->_cloc == "child")
				{
					if (inputItem1 != inputItem2)
					{
						component* tempComponent = location::objects.find(inputItem2)->second->getcomponent("children");
						child_entity* pDerived = dynamic_cast<child_entity*>(tempComponent);
						if (location::objects.find(inputItem2)->second->_cloc == "Player")
						{
							inv->store_item(*location::objects.find(inputItem1)->second);
						}
						else if (location::objects.find(inputItem2)->second->_cloc == pl->getLocation())
						{
							location::objects.find(inputItem1)->second->_cloc = "Player";
							inv->store_item(*location::objects.find(inputItem1)->second);
						}
						pDerived->childentity.erase(inputItem1);
						pDerived->show_child();
					}
				}
			}
		}
	}
	else if (output == "putItem")
	{
		for (it = location::objects.begin(); it != location::objects.end(); ++it)
		{
			if (it->second->_name == inputItem2)
			{
				if (pl->getLocation() == it->second->_cloc || it->second->_cloc == "Player")
				{
					if (it->second->has_component("children"))
					{
						if (inputItem1 != inputItem2)
						{
							component* tempComponent = it->second->getcomponent("children");
							child_entity* pDerived = dynamic_cast<child_entity*>(tempComponent);
							if (location::objects.find(inputItem1)->second->_cloc == "Player")
							{
								inv->takeOut_item(*location::objects.find(inputItem1)->second);
								location::objects.find(inputItem1)->second->_cloc = "child";
							}
							else if (location::objects.find(inputItem1)->second->_cloc == pl->getLocation())
							{
								location::objects.find(inputItem1)->second->_cloc = "child";
							}
							else if (location::objects.find(inputItem1)->second->_cloc == "child")
							{
								inv->takeOut_item(*location::objects.find(inputItem1)->second);
							}
							pDerived->add_childentity(inputItem1, location::objects.find(inputItem1)->second);
							pDerived->show_child();
						}
					}
				}
			}
		}
	}
	else if (output == "attack")
	{
		Message* msg = Message::Instance();
		for (it = location::objects.begin(); it != location::objects.end(); ++it)
		{
			if (it->first == "monster")
			{
				if (it->second->_cloc == pl->getLocation())
				{
					msg->Send(location::objects.find(it->first)->second, "5"); // 5 is damage sent to objs
				}
			}
		}
		//	msg->Send();
		//	msg_attack* tempMessage = new msg_attack(loc->objects.find("sword")->second, loc->objects.find("monster")->second);
		//	tempMessage->update();
	}
	else
	{
		cout << "\n\n----- You need a weapon to attack.\n" << endl;
	}
}

