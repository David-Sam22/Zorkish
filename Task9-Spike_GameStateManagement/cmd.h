#pragma once

using namespace std;

class cmd
{
public:
	virtual void execute() = 0;
	virtual void load() = 0;
};