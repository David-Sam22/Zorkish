#pragma once

#include <string>
#include "component.h"
#include "game_object.h"
#include "Blackboard.h"

using namespace std;

class Message : public component
{
public:
	static Message* Instance();
	Blackboard* board = Blackboard::Instance();
	virtual void update();
	Message(game_object obj);
	Message();
	void Send(game_object* obj,string msg);
private:
	static Message* _instance;
};
