#pragma once

#include "stdio.h"
#include "dirent.h"
#include "Utility.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using std::fstream;
using std::string;
using std::to_string;
using std::cout;
using std::endl;
using std::getline;
using std::ios;
using std::stoi;
using std::size;
using std::list;

//using namespace std;

class FileSystem
{
//private:
	list<string> dirList;
	int dirArr[4] = { 0,0,0,0 };
	fstream m_filer;

public:
	FileSystem();
	int listdir(const char*);
	static void callDir(int, char**, const char*);
};
