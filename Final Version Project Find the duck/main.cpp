/****************************************************************************************************************************************************************************************
Description:		main function of INF1015 ROOM EXPLORER 2021 Game prototype 
File:				main.cpp
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#include <cstddef>
#include <cstdint>

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

#include <tclap/CmdLine.h>

#include "Room.h"
#include "Map.h"
#include "GameState.h"
#include "Game.h"
#include "UserInput.h"

#include "Item.h"

using namespace std;
using namespace std::literals;

int main() {
	// creating the map
	Map theMap("RoomsAndItems.txt");
	// creating the starting room
	GameState startingRoom(theMap);
	// creating the game
	Game theGame(startingRoom);
	// running the game
	theGame.runGame();

	return 0;
}
