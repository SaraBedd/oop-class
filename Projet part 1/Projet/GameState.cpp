#include "GameState.h"

shared_ptr<Room> GameState::getCurrentRoom() {
	return currentRoom_;
}

void GameState::setCurrentRoom(int direction) {
	if (currentRoom_->getNeighbour(direction) != nullptr) {
		currentRoom_ = currentRoom_->getNeighbour(direction);
	}
}

bool GameState::getIsGameOver() {
	return isGameOver_;
}

void GameState::setIsGameOver(bool etatJeu) {
	isGameOver_ = etatJeu;
}

void GameState::displayCurrrentRoom() {
	currentRoom_->displayRoom();
}