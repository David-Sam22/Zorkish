#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "component.h"

using namespace std;

class health : public component
{
public:
	int _health;
	virtual void update();
	void reducedhealth(int dmgammount) { _health -= dmgammount; };
	void sethealth(int h) { _health = h; };
	int gethealth() { return _health; };
};