#pragma once

#include <string>
#include <iostream>

using namespace std;

class state
{
public:
	virtual void handle() = 0;
	//virtual void show_state() = 0;

};

//virtual header file for state class
//use for function declaration that allow abstract class to inherit its function
