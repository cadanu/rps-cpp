#pragma once

#include "Utility.h"

#include <string>
#include <random>

using std::string;
//using std::to_string;

class Hero
{
// private:
	const string heroes[3] = {"ROCK","PAPER","SCISSORS"};
	string m_name;
	string m_weakAgainst;
	string m_winAction;

	void setAttributes(string);

public:
	Hero();
	Hero(string _choice);
	void setName(string);
	string getName();	
	string getWeakness();
	string getWinAction();
};
