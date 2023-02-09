#include "FileSystem.h"


FileSystem::FileSystem()
{}

// https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/dirent.h
int FileSystem::leaderBoard(const char* _path)
{
	// init vars
	struct dirent* m_ent;
	DIR* m_dir;

	// open directory
	m_dir = opendir(_path);
	if (m_dir == nullptr)
	{
		perror("opendir");
		return -1;
	}

	// while directory is open
	int incr = 0;
	while ((m_ent = readdir(m_dir)))
	{
		// ignore the 'pwd' and 'back' directory markers
		if (((string)m_ent->d_name != ".") && ((string)m_ent->d_name != ".."))
		{
			// push file name values to list
			dirList.push_back((string)m_ent->d_name);// list gives ability to sort
			incr++;
		}
	}
	closedir(m_dir);// close directory

	dirListTemp = dirList;
	int order = 0;
	while(!dirListTemp.empty())// perhaps change to iterator?
	{
		// init vars
		incr = 0;
		string line;

		// open file
		m_filer.open(_path + dirListTemp.front(), ios::in);
		if (m_filer.is_open())
		{
			while (getline(m_filer, line))
			{
				if (incr < dirArr.size() - 1)
				{
					// set score values from file into array
					dirArr[incr] = stoi(line);
					incr++;
				}
			}
		}
		m_filer.close();

		// for sort - order id
		incr++;
		order++;
		dirArr[4] = order;
		nameArr = { dirListTemp.front(), to_string(order) };

		// add arrays to list
		dirArrList.push_back(dirArr);
		nameArrList.push_back(nameArr);
		dirListTemp.pop_front();// pop
	}

	// sort score
	dirArrList.sort();
	dirArrList.reverse();

	cout << "LEADERBOARD:\n" << endl;
	cout << "NAME\t\t\tPOINTS\t\tWINS\t\tLOSSES\t\tTIES" << endl;
	// build string according to username with array values
	while (!dirArrList.empty())// dirArrList holds the score arrays
	{
		// init vars
		string scoreLine;

		// pass list to temp list
		nameArrListTemp = nameArrList;
		while (!nameArrListTemp.empty())
		{
			// match order id's
			if (stoi(nameArrListTemp.front()[1]) == dirArrList.front()[4])
			{
				// username is matched to score
				scoreLine = nameArrListTemp.front()[0];
				break;
			}
			else nameArrListTemp.pop_front();
		}
		nameArrListTemp.clear();
		scoreLine.erase(scoreLine.find(".txt"), scoreLine.length() - 1);

		for (int i = 0; i < (dirArrList.front().size())-1; i++)
		{
			scoreLine += "\t\t" + to_string(dirArrList.front()[i]);
		}
		cout << scoreLine << endl;// print to console

		dirArrList.pop_front();
	}
	
	printf ("\n");

	return 0;
}

void FileSystem::getLeaderBoard(int argc, char** argv, const char* _path)
{
	FileSystem* fs = new FileSystem();

	if (argc == 1)// call function with specified path
		fs->leaderBoard((_path));

	system("pause");
}
