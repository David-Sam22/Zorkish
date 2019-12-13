#pragma once
#include <string>

using namespace std;
class Player
{
public:
	static Player* Instance();
	int getHP();
	void setHP(int hp);
	void setPrevLocation(string loc) { previous_location = loc; };
	string getPrevLocation() { return previous_location; };
	void setLocation(string loc);
	string getLocation();
private:
	string previous_location;
	string current_location;
	int hp;
	static Player* _instance;
};
