#include "FileSystem.h"


FileSystem::FileSystem()
{}

// https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/dirent.h
int FileSystem::listdir(const char* _path)
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
			dirList.push_back((string)m_ent->d_name);
			incr++;
		}
	}
	closedir(m_dir);

	// print header
	cout << "LEADERBOARD:\n" << endl;
	cout << "NAME\t\t\tPOINTS\t\tWINS\t\tLOSSES\t\tTIES" << endl;

	dirList.sort();// smallest biggest
	dirList.reverse();// biggest to smallest
	while(!dirList.empty())
	{
		// init vars
		incr = 0;
		string line;

		// open file
		m_filer.open(_path + dirList.front(), ios::in);
		if (m_filer.is_open())
		{
			while (getline(m_filer, line))
			{
				// set score values from file into array
				dirArr[incr] = stoi(line);
				incr++;
			}
		}
		// build string according to username with array values
		string scoreLine = dirList.front();
		for (int i = 0; i < size(dirArr); i++)
		{
			scoreLine += "\t\t" + to_string(dirArr[i]);
		}
		cout << scoreLine << endl;// print to console
		dirList.pop_front();
	}
	return 0;
}

void FileSystem::callDir(int argc, char** argv, const char* _path)
{
	FileSystem* fs = new FileSystem();

	if (argc == 1)// call function with specified path
		fs->listdir((_path));

	system("pause");
}
