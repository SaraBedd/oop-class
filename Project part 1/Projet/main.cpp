///
/// Fonction principale du projet
///

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

using namespace std;
using namespace std::literals;

int main() {

	/*Constructs a map (or house) based on the txt file describing
	each room available, its description and neighbours.*/
	Map theMap("Rooms.txt");
	/*Constructs a game state.*/
	GameState myRoom(theMap);
	/*Constructs of a game.*/
	Game theGame(myRoom);
	/*Runs the game.*/
	theGame.runGame();

	return 0;
}
