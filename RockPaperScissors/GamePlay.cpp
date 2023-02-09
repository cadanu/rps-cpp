#include "GamePlay.h"


GamePlay::GamePlay()
{
	m_tie = false;
	m_winner = nullptr;
}

void GamePlay::setWinner(Player* _winner)
{
	m_winner = _winner;
}

Player* GamePlay::getWinner()
{
	return m_winner;
}

void GamePlay::cleanWinner()
{
	m_winner = nullptr;
}

void GamePlay::evaluateClash(Player* _player1, Player* _player2)
{
	Player* tempLoser = nullptr;

	string p1HeroName = _player1->getHeroChoice()->getName();
	string p2HeroName = _player2->getHeroChoice()->getName();
	string p1HeroWeakness = _player1->getHeroChoice()->getWeakness();
	string p2HeroWeakness = _player2->getHeroChoice()->getWeakness();

	if (p1HeroName == p2HeroName)
	{
		m_tie = true;
		calculateStats(_player1, "TIES");
		calculateStats(_player2, "TIES");

		cout << _player1->getHeroChoice()->getName() + " meets " + _player2->getHeroChoice()->getName() << endl;
		cout << _player1->getUserName() + " tied with " + _player2->getUserName() + "!" << endl;
	}
	else
	{
		if (p1HeroWeakness == p2HeroName)
		{
			setWinner(_player2);
			calculateStats(_player2, "WINS");
			calculateStats(_player1, "LOSSES");
			tempLoser = _player1;
		}
		else if (p2HeroWeakness == p1HeroName)
		{
			setWinner(_player1);
			calculateStats(_player1, "WINS");
			calculateStats(_player2, "LOSSES");
			tempLoser = _player2;
		}
		cout << m_winner->getHeroChoice()->getName() + m_winner->getHeroChoice()->getWinAction() + tempLoser->getHeroChoice()->getName() << endl;
		cout << m_winner->getUserName() + " wins!" << endl;

		tempLoser = nullptr;
	}
}

void GamePlay::calculateStats(Player* _player, string _type)
{
	if (_type == "WINS")
	{
		_player->addPoints(3);// a win awards 3 points
		_player->addWins(1);
	}
	if (_type == "LOSSES")
	{
		_player->addLosses(1);
	}
	if (_type == "TIES")
	{
		_player->addPoints(1);// a tie awards 1 point
		_player->addTies(1);
	}
}
