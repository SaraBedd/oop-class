#include "GameState.h"

/*Returns the shared_ptr currentRoom_ attribute (the shared_ptr of
which room the user is currently in).*/
shared_ptr<Room> GameState::getCurrentRoom() {
	return currentRoom_;
}

/*Sets the value of currentRoom_ to the neighbor of currentRoom_
in neighbours attribute at the position given in argument.*/
void GameState::setCurrentRoom(int direction) {
	if (currentRoom_->getNeighbour(direction) != nullptr) {
		currentRoom_ = currentRoom_->getNeighbour(direction);
	}
}

/*Returns bool attribute isGameOver_. If isGameOver_ is true,
the game is over, if not, it continues.*/
bool GameState::getIsGameOver() {
	return isGameOver_;
}

/*Sets the value of isGameOver_ attribute to the value given
in argument.*/
void GameState::setIsGameOver(bool etatJeu) {
	isGameOver_ = etatJeu;
}

/*Displays the room the user in currently in.*/
void GameState::displayCurrrentRoom() {
	currentRoom_->displayRoom();
}