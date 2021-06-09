/****************************************************************************************************************************************************************************************
Description:		Header file of GameState class
File:				GameState.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#pragma once
#include <memory>

#include "Map.h"
#include "RoomWithLight.h"

string const START = "Entrance";

class GameState {
public:
	GameState() = default;
	GameState(Map& map, string startingPoint = START) {
		currentRoom_ = map.searchRoom(START);
	}

	Room* getCurrentRoom();

	void setCurrentRoom(int direction);

	bool getIsGameOver();

	void setIsGameOver(bool etatJeu);

private:
	Room* currentRoom_;
	bool isGameOver_ = false;
};