#include "pch.h"
#include "Message.h"

Message* Message::Instance()
{
	if (_instance == NULL) {
		_instance = new Message;
	}

	return _instance;
}

Message* Message::_instance;

void Message::update()
{
}

Message::Message(game_object obj)
{
	board->Register(obj);
}

Message::Message()
{
}

void Message::Send(game_object* obj, string msg)
{
	board->Post(obj,msg);
}
