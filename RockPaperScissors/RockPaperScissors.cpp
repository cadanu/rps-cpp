// 
// RockPaperScissors is a simple program that implements the popular Rock, Paper, Scissors hand game.
// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Utility.h"
#include "GamePlay.h"
#include "Player.h"

#include <iostream>
//#include <algorithm>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

int main()
{
	// declarations
	bool userNotDefined = true;
	bool inputNotDefined = true;
	bool on = true;
	string userName = "";
	string userInput = "";
	string userContinue = "";
	// pointers
	GamePlay* gamePlay = new GamePlay();
	Player* computerPlayer = new Player("COMPUTER");
	Player* userPlayer = new Player();// user

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
			break;
		}
	}
	clrscr();

	// set player - user, and data
	userPlayer->setUserName(userName);
	// end set player
	
	while (on)// play game
	{
		// set player - computer		
		computerPlayer->randomHero();
		// end set player

		cout << "Welcome to Rock, Paper, Scissors, the ULTIMATE CLASH." << endl;
		cout << "Type 'x' to quit or 'rank' for leaderboard." << endl;
		cout << userName + ", your score is " + to_string(userPlayer->getPoints()) + ". You have " + to_string(userPlayer->getWins()) + " win(s), " + to_string(userPlayer->getLosses()) + " loss(es), and " + to_string(userPlayer->getTies()) + " tie(s)." << endl;
		cout << "Choose your HERO [Rock, Paper, or Scissors]: ";
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);// see above

		if (userInput == "X")
		{
			break;
		}
		else if (userInput == "ROCK" || userInput == "PAPER" || userInput == "SCISSORS")
		{
			// set player - user
			userPlayer->setHeroChoice(userInput);
			// end set player

			cout << endl << " (   (  ( ( ! ! ! CLASH ! ! ! ) )  )   )" << endl << endl;
			gamePlay->evaluateClash(userPlayer, computerPlayer);// user always in first pos

			// housekeeping
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
	}

	clrscr();
	cout << "Thankyou for Playing Rock, Paper, Scissors!" << endl;

	delete gamePlay;
	delete userPlayer;
	delete computerPlayer;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
