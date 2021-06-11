/****************************************************************************************************************************************************************************************
Description:		implementation of class GameState.h
File:				GameState.cpp
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#include "GameState.h"

/*
 * Returns the shared_ptr currentRoom_ attribute (the shared_ptr of
 * which room the user is currently in).
 * \param	void
 * \return	(shared_ptr<Room>&)	current room
 **/
Room* GameState::getCurrentRoom() {
	return currentRoom_;
}

/*
 * Sets the value of currentRoom_ to the neighbor of currentRoom_
 * in neighbours attribute at the position given in argument.
 * \param	(int)	index of neighbours' current room 
 * \return	void
 **/
void GameState::setCurrentRoom(int direction) {
	if (currentRoom_->getNeighbour(direction) != nullptr) {
		currentRoom_ = currentRoom_->getNeighbour(direction);
	}
}

/*
 * Returns bool attribute isGameOver_. 
 * If isGameOver_ is true, the game is over, if not, it continues.
 * \param	void
 * \return	bool	game state (is the game over or not)
 **/
bool GameState::getIsGameOver() {
	return isGameOver_;
}

/*
 * Sets the value of isGameOver_ attribute to the value given
 * in argument.
 * \param	bool	the new game state (is the game over or not)
 * \return	void
 **/
void GameState::setIsGameOver(bool gameState) {
	isGameOver_ = gameState;
}

bool GameState::getIsDuckCaught() {
	return isDuckCaught_;
}

void GameState::setIsDuckCaught(bool duckCaught) {
	isDuckCaught_ = duckCaught;
}