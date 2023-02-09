// help with fstream from CodeBeauty - https://youtu.be/EaHFhms_Shw

#include "GameData.h"


GameData::GameData()
{
	m_user = nullptr;
}

GameData::GameData(Player* _user)
{
	m_user = _user;
	getScoreFromFile();
}

void GameData::setScoreToFile()
{
	// add Player* to array
	scoreArr[0] = to_string(m_user->getPoints());
	scoreArr[1] = to_string(m_user->getWins());
	scoreArr[2] = to_string(m_user->getLosses());
	scoreArr[3] = to_string(m_user->getTies());

	m_filer.open("./data/" + m_user->getUserName() + ".txt", ios::out);
	if (m_filer.is_open())// fill file with array
	{
		for (int i = 0; i < size(scoreArr); i++)
		{
			m_filer << scoreArr[i] + "\n";		}
	}
	m_filer.close();
}

void GameData::getScoreFromFile()
{
	m_filer.open("./data/" + m_user->getUserName() + ".txt", ios::in);
	if (m_filer.is_open())// file fills array
	{
		int incr = 0;
		string line;
		while (getline(m_filer, line))
		{
			if (incr < size(scoreArr))
			{
				scoreArr[incr] = line;
				incr++;
			}
		}

		for (int i = 0; i < size(scoreArr); i++)
		{
			if (scoreArr[i] == "")
			{
				scoreArr[i] = to_string(0);
			}
		}
		// add array to Player*
		m_user->addPoints(stoi(scoreArr[0]));
		m_user->addWins(stoi(scoreArr[1]));
		m_user->addLosses(stoi(scoreArr[2]));
		m_user->addTies(stoi(scoreArr[3]));

		// points validity check
		if (m_user->getPoints() != ((m_user->getWins() * 3) + (m_user->getTies())))
		{
			m_user->addPoints( (0 - m_user->getPoints()) + (m_user->getPoints() != ((m_user->getWins() * 3) + (m_user->getTies()))) );
		}
	}
	m_filer.close();
}

void GameData::cleanGameData()
{
	m_user = nullptr;
}
