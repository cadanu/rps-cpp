#include "Hero.h"


Hero::Hero()
{
	// random number generator - https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
	std::random_device randomDevice;
	std::mt19937 gen(randomDevice());
	std::uniform_int_distribution<> distr(0, 2);
	m_name = heroes[(distr(gen))];
	setAttributes(m_name);
}

Hero::Hero(string _choice)
{
	m_name = _choice;
	setAttributes(m_name);
}

void Hero::setAttributes(string _name)
{
	if (_name == "ROCK")
	{
		m_weakAgainst = "PAPER";
		m_winAction = " smashes ";
	}
	else if (_name == "PAPER")
	{
		m_weakAgainst = "SCISSORS";
		m_winAction = " smothers ";
	}
	else if (_name == "SCISSORS")
	{
		m_weakAgainst = "ROCK";
		m_winAction = " slices ";
	}
}

void Hero::setName(string _name)
{
	m_name = _name;
	setAttributes(m_name);
}

string Hero::getName()
{
	return m_name;
}

string Hero::getWeakness()
{
	return m_weakAgainst;
}

string Hero::getWinAction()
{
	return m_winAction;
}
