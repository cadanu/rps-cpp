#pragma once

#include "stdio.h"
#include "dirent.h"
#include "Utility.h"

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <list>
#include <conio.h>

using std::fstream;
using std::string;
using std::to_string;
using std::cout;
using std::endl;
using std::getline;
using std::ios;
using std::stoi;
using std::size;
using std::array;
using std::list;


class FileSystem
{
//private:
	list<string> dirList;
	list<string> dirListTemp;
	array<string,2> nameArr = { "","" };
	array<int,5> dirArr = { 0,0,0,0,0 };
	list<array<int,5>> dirArrList;
	list<array<string,2>> nameArrList;
	list<array<string, 2>> nameArrListTemp;
	fstream m_filer;

public:
	FileSystem();
	int leaderBoard(const char*);
	static void getLeaderBoard(int, char**, const char*);
};
