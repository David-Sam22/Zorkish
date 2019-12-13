#pragma once
#include <List>
#include <string>
#include "game_object.h"
#include <map>

using namespace std;

class Blackboard
{
public:
	static Blackboard* Instance();
	static list<game_object> registered;
	static map<game_object*, string> MessageList;

	void Register(game_object obj);
	void Update();
	void Post(game_object* sendTo,string msg);
	void RemovePost();
	Blackboard();

private:
	static Blackboard* _instance;
};
