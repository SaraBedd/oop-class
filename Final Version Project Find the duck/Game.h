/****************************************************************************************************************************************************************************************
Description:		Header file of Game class
File:				Game.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#pragma once
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "GameState.h"
#include "UserInput.h"

using namespace std;

const string YELLOW = "\u001b[33m", RED = "\033[1;91m", PURPLE = "\033[1;95m", BLUE = "\033[1;96m", COLOR_END = "\033[0m", YELLOW_END = "\u001b[0m";
const int TIME_DELAY = 500, SPACE_WELCOME = 5, SPACE_ENTER = 10, SPACE_DUCK = 20, DUCK_FRAMES = 7;

class Game
{
public:
	Game() = default;
	Game(GameState currentRoom);

	void displayWelcome();

	void displayHeader();

	void displayRoom();

	void displayNeighbour(int index);

	void displayItems();

	void displayItemDescription(int index);

	void displayUsage(int index);

	void displayQuitGame();

	void displayValidInput();

	void displayInvalidInput();

	void displayDuck();

	void lookItem();

	void useItem();
	 
	void runGame();

private:
	UserInput userInput_;
	GameState myRoom_;
};

