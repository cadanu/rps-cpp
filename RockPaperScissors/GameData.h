#pragma once

#include "Player.h"

#include <fstream>
#include <string>

using std::fstream;
using std::ios;
using std::string;
using std::array;
using std::getline;
using std::to_string;
using std::stoi;
using std::size;


class GameData
{
//private:
	Player* m_user;
	string scoreArr[4] = { "0","0","0","0" };
	fstream m_filer;

public:
	GameData();
	GameData(Player*);
	void setScoreToFile();
	void getScoreFromFile();
	void cleanGameData();
}; 

