#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class component
{
public:
	component();

	virtual void update() = 0;
};


