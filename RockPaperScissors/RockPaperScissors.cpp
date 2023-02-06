// 
// RockPaperScissors is a simple program that implements the popular Rock, Paper, Scissors hand game.
// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Utility.h"

#include <iostream>
#include <algorithm>
#include <string>

#define RAND_MAX 3

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
	int random;
	int userScore = 0;
	int userWins = 0;
	int userLosses = 0;
	int userTies = 0;
	string dummyInsert = "[]";
	string userName = "";
	string userInput = "";
	string userContinue = "";
	string heroes[3] = { "ROCK", "PAPER", "SCISSORS" };


	//Log(to_string(RAND_MAX));// check

	// begin program
	cout << "Welcome to Rock, Paper, Scissors, the utlimate clash. Type 'x' to quit or enter your Username below. It's ok if you're a new player, just enter your username when prompted but remember, your username should be 8 characters long or more." << endl;

	while (userNotDefined)
	{	
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
			// do something
			break;
		}
	}
	clrscr();

	while (on)
	{
		// computer choice
		random = std::rand();
		Log("random: " + to_string(random));// check

		cout << "Hi " + userName + ", welcome to Rock, Paper, Scissors, the utlimate clash. Type 'x' to quit or 'rank' for leaderboard." << endl;
		cout << "Your score is " + dummyInsert + ". You have " + dummyInsert + " wins, " + dummyInsert + " losses, and " + dummyInsert + " ties." << endl;
		cout << "Please choose your hero (Rock, Paper, or Scissors) : ";
		cin >> userInput;
		transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);// see above

		if (userInput == "X")
		{
			break;
		}
		else if (userInput == "ROCK" || userInput == "PAPER" || userInput == "SCISSORS")
		{
			//Log(userInput);// check
			cout << endl << userInput << endl << endl;

			while (inputNotDefined)
			{
				cout << "Would you like to continue playing [y/n]?" << endl;
				cin >> userContinue;
				transform(userContinue.begin(), userContinue.end(), userContinue.begin(), ::toupper);// see above
				
				if (userContinue == "N" || userContinue == "X")
				{
					on = false;
					break;
				}
				else if (userContinue != "Y")
				{
					clrscr();
					cout << "Please enter a valid response." << endl;
				}
				else
				{
					break;
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
