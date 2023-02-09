#pragma once

//#include "Utility.h"
#include "Player.h"
//#include "dirent.h"// check

#include <fstream>
#include <string>
//#include <filesystem>
//#include <array>

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
	//string m_userName;
	Player* m_user;
	string scoreArr[4] = { "0","0","0","0" };
	fstream m_filer;

public:
	GameData();
	GameData(Player*);
	void setScoreToFile();
	void getScoreFromFile();
	void displayScoresFromFiles(string);
	void cleanGameData();
	/*void setUser(Player*);
	Player* getUser();*/
}; 

