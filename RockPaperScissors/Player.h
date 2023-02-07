#pragma once

#include "Hero.h"

//#include <string>

using std::string;

class Player
{
// private:
	int m_points;
	int m_wins;
	int m_losses;
	int m_ties;
	string m_userName;
	Hero* m_heroObject;

public:
	Player();
	Player(string _userName);
	//Player(string _userName, string _heroChoice);

	void addPoints(int);
	int getPoints();
	void addWins(int);
	int getWins();
	void addLosses(int);
	int getLosses();
	void addTies(int);
	int getTies();
	void setUserName(string _userName);
	string getUserName();

	void setHeroChoice(string _herochoice);
	Hero* getHeroChoice();
	void cleanPlayerHero();
	void randomHero();
};

