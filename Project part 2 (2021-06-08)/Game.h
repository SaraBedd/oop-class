/****************************************************************************************************************************************************************************************
Description:		Header file of Game class
File:				Game.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#pragma once
#include <string>

#include "GameState.h"
#include "UserInput.h"

using namespace std;

class Game
{
public:
	Game() = default;
	Game(GameState currentRoom);

	void displayRoom();

	void displayNeighbour(int index);

	void displayItem(int index);

	void displayUsage(int index);
	 
	void runJeu();

private:
	UserInput userInput_;
	GameState myRoom_;
};

