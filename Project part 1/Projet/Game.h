#pragma once
#include <string>
#include "GameState.h"
#include "UserInput.h"

using namespace std;

class Game
{
public:
	Game() = default;
	Game(GameState currentRoom) {
		myRoom_ = currentRoom;
	}

	void runGame();

private:
	UserInput userInput_;
	GameState myRoom_;
};

