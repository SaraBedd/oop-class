#pragma once
#include"Room.h"
#include "Map.h"
#include <memory>

string const START = "Entrance";

class GameState {
public:

	GameState() = default;
	GameState(Map map, string startingPoint = START) {
		map_ = map;
		currentRoom_ = make_shared<Room>(*map.searchRoom(START).get());
	}

	shared_ptr<Room> getCurrentRoom();

	void setCurrentRoom(int direction);

	bool getIsGameOver();

	void setIsGameOver(bool etatJeu);

	void displayCurrrentRoom();

private:
	Map map_;
	shared_ptr<Room> currentRoom_;
	bool isGameOver_ = false;

};