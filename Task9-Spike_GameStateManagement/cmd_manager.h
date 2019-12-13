#pragma once
#include <list>
#include <string>
#include <map>
using namespace std;

class cmd_manager
{
public:
	cmd_manager();
	void loadFile();
	void printDebug();
	void printHelp();
	void printInventory();
	void printAlias();
	void printLook();
	void setCommand(string input){ usercmd = input; };
	void setInput(string input) { userinput = input; };
	string getInput() { return userinput; };
	string getCmd() { return usercmd; };
	bool checkList(string input);
	void process_input();
	static multimap<string, string> cmd_map;
private:
	static string usercmd;
	static string userinput;
};