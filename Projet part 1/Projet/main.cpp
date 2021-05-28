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

	Map theMap("Rooms.txt");
	GameState myRoom(theMap);
	Game theGame(myRoom);
	theGame.runJeu();

	return 0;
}
