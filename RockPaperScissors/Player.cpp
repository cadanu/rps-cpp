#include "Player.h"


Player::Player()
{
	m_userName = "";
	m_points = 0;
	m_wins = 0;
	m_losses = 0;
	m_ties = 0;
	m_heroObject = nullptr;
}

Player::Player(string _userName)
{
	m_userName = _userName;
	m_points = 0;
	m_wins = 0;
	m_losses = 0;
	m_ties = 0;
	m_heroObject = nullptr;	
}

//Player::Player(string _userName, string _heroChoice)
//{
//	m_userName = _userName;
//	m_points = 0;
//	m_heroObject = new Hero(_heroChoice);
//}

void Player::addPoints(int _points)
{
	m_points += _points;
}

int Player::getPoints()
{
	return m_points;
}

void Player::addWins(int _wins)
{
	m_wins += _wins;
}

int Player::getWins()
{
	return m_wins;
}

void Player::addLosses(int _losses)
{
	m_losses += _losses;
}

int Player::getLosses()
{
	return m_losses;
}

void Player::addTies(int _ties)
{
	m_ties += _ties;
}

int Player::getTies()
{
	return m_ties;
}

void Player::setUserName(string _userName)
{
	m_userName = _userName;
}

string Player::getUserName()
{
	return m_userName;
}

void Player::setHeroChoice(string _heroChoice)
{
	m_heroObject = new Hero(_heroChoice);
}

Hero* Player::getHeroChoice()
{
	return m_heroObject;
}

void Player::cleanPlayerHero()
{
	delete m_heroObject;
}

void Player::randomHero()
{
	m_heroObject = new Hero();
}
