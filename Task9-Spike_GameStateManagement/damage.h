#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "component.h"

using namespace std;

class damage : public component
{
public:
	int _damage;
	virtual void update();
	void setdamage(int h) { _damage = h; };
	int getdamage() { return _damage; };
};