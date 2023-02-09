// 
// RockPaperScissors is a simple program that implements the popular Rock, Paper, Scissors hand game.
// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Utility.h"
#include "GamePlay.h"
#include "GameData.h"
#include "Player.h"
#include "FileSystem.h"

#include <iostream>
//#include <algorithm>
//#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

int main(int argc, char** argv)
{
	// testing
	//FileSystem::callDir(argc, argv, "./data/");
	
	// declarations
	bool userNotDefined = true;
	bool inputNotDefined = true;
	bool on = true;
	bool endGame = false;
	string userName = "";
	string userInput = "";
	string userContinue = "";
	// pointers
	GamePlay* gamePlay = new GamePlay();
	GameData* userData = nullptr;
	Player* computerPlayer = nullptr;
	Player* userPlayer = nullptr;// user

	// get username
	cout << "Welcome to Rock, Paper, Scissors, the ULTIMATE CLASH." << endl;
	cout << "Type 'x' to quit. New or returning players enter your Username below." << endl;
	while (userNotDefined)
	{	
		userName.erase();
		cout << "Username: ";
		cin >> userName;
		transform(userName.begin(), userName.end(), userName.begin(), ::toupper);// user input to uppercase https://stackoverflow.com/questions/23418390/how-to-convert-a-c-string-to-uppercase#23418474

		if (userName == "X")
		{
			on = false;
			break;
		}
		else if (userName.length() < 8)
		{
			clrscr();
			cout << "Username should be 8 characters or more in length, please try again or type 'x' to quit." << endl;
		}
		else
		{
			// set player - computer/ai
			computerPlayer = new Player("COMPUTER");

			// set player - user, and player data
			userPlayer = new Player(userName);

			// user file system/game data
			userData = new GameData(userPlayer);

			break;
		}
	}
	clrscr();
	
	while (on)// play game
	{
		// set player - computer		
		computerPlayer->randomHero();

		cout << "Welcome to Rock, Paper, Scissors, the ULTIMATE CLASH." << endl;
		cout << "Type 'x' to quit or 'rank' for leaderboard." << endl;
		cout << userPlayer->getUserName() + ", your score is " + to_string(userPlayer->getPoints()) + ". You have " + to_string(userPlayer->getWins()) + " win(s), " + to_string(userPlayer->getLosses()) + " loss(es), and " + to_string(userPlayer->getTies()) + " tie(s)." << endl;
		cout << "Choose your HERO [Rock, Paper, or Scissors]: ";
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);// see above

		if (userInput == "X")
		{
			endGame = true;
			on = false;
		}
		else if (userInput == "RANK")
		{
			clrscr();
			FileSystem::callDir(argc, argv, "./data/");
			clrscr();
		}
		else if (userInput == "ROCK" || userInput == "PAPER" || userInput == "SCISSORS")
		{
			// set player - user
			userPlayer->setHeroChoice(userInput);

			cout << endl << " (   (  ( ( ! ! ! CLASH ! ! ! ) )  )   )" << endl << endl;
			gamePlay->evaluateClash(userPlayer, computerPlayer);// user always in first pos

			// housekeeping - reset
			gamePlay->cleanWinner();
			computerPlayer->cleanPlayerHero();
			userPlayer->cleanPlayerHero();

			// continue playing?
			while (inputNotDefined)
			{
				cout << "Would you like to continue playing [y/n]? ";
				cin >> userContinue;
				transform(userContinue.begin(), userContinue.end(), userContinue.begin(), ::toupper);// see above
				
				if (userContinue == "N" || userContinue == "NO" || userContinue == "X")
				{
					on = false;
					endGame = true;
					break;
				}
				else if (userContinue == "Y" || userContinue == "YES")
				{
					clrscr();
					break;				
					//Log(userContinue);
				}
				else
				{
					clrscr();
					cout << "Please enter a valid response." << endl;
				}
			}
		}
		else
		{
			clrscr();
			cout << "Invalid entry, please try again." << endl;
		}
		// if user quits then finish up
		if (endGame)
		{
			userData->setScoreToFile();
			userData->cleanGameData();
			delete userData;
			delete computerPlayer;
			delete userPlayer;
		}
	}

	delete gamePlay;

	clrscr();
	cout << "Thankyou for Playing Rock, Paper, Scissors!" << endl;

	return 0;
}