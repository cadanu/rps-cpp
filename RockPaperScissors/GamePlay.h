#pragma once

#include "Player.h"

#include <iostream>
//#include <string>

using std::string;
using std::cout;
using std::endl;

class GamePlay
{
private:
	bool m_tie;
	Player* m_winner;

	void setWinner(Player*);

public:
	GamePlay();
	Player* getWinner();
	void cleanWinner();
	void evaluateClash(Player*, Player *);
	void calculateStats(Player*, string);
};

