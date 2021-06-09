/****************************************************************************************************************************************************************************************
Description:		implementation of class Game.h
File:				Game.cpp
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#include "Game.h"

/*
 * Game constructor
 * \param	(GameState)	current state of game
 * \return	void
 **/
Game::Game(GameState currentRoom) {
	myRoom_ = move(currentRoom);
}

/*
 * Displays the name of the room, its description, and each of its neighbours
 * \param	void
 * \return	void
 **/
void Game::displayRoom() {
	cout << "\n" << "\033[1;95m" << "= = =   " << myRoom_.getCurrentRoom()->getName() << "   = = =" << "\n" << "\033[0m";
	cout << myRoom_.getCurrentRoom()->getDescription() << "\n";
	cout << "You notice:\n";
	for (int i = 0; i < myRoom_.getCurrentRoom()->getItem().size(); i++) {
		cout << "   " << myRoom_.getCurrentRoom()->getItem()[i]->getName() << "\n";
	}
	for (int i = 0; i < CARDINAL; i++) {
		if (myRoom_.getCurrentRoom()->getNeighbour(i) != nullptr) {
			displayNeighbour(i);
			cout << "\n";
		}
	}
	cout << "\033[1;96m" << "\n >> " << "\033[0m";
}

/*
 * Displays the neighbour given at index position given in argument,
 * in vector DIRECTIONWORD
 * \param	(int)	index of neighbour to display
 * \return	void
 **/
void Game::displayNeighbour(int index) {
	cout << myRoom_.getCurrentRoom()->getNeighbour(index)->getName();
	cout << " is " << DIRECTIONWORD[index] << "\033[1;96m" << " (" << DIRECTIONCHAR[index] << ")" << "\033[0m";
}

void Game::displayItem(int index) {
	cout << myRoom_.getCurrentRoom()->getItem()[index]->getDescription();
}

void Game::displayUsage(int index) {
	cout << myRoom_.getCurrentRoom()->getItem()[index]->getUsage();
}

/*
 * Function that runs the following game:
 * A duck has entered the house. In order to find it, the user has to explore the rooms vy entering the direction where he wishes to go.
 * The game displays the first room the user is in.
 * The command x : exist the game
 * The command look: offer the user a display of the room he currently is in.
 * \param	void
 * \return	void
 **/
void Game::runJeu() {

	cout << "\u001b[33;1m" << " > > > > > > > > > > > > > > > >     INF1015 ROOM EXPLORER 2021     < < < < < < < < < < < < < < < < < " << "\n"
		 << " > > > - - - - - - - - - - - - - - - - - -  DUCK EDITION  - - - - - - - - - - - - - - - - - - - < < < " << "\u001b[0m" << "\n\n";
	cout << "A duck enterred the house, try to find it!" << "\n";
	cout << "You can explore the rooms by entering the direction you wish to go at." << "\n";
	cout << "Special command: " << "\033[1;91m" << "x " << "\033[0m" << "\t-> To exit game" << "\n";
	cout << "\t\t" << "\033[1;91m" << " look " << "\033[0m" << "\t-> To display current room" << "\n\n";

	displayRoom();
	
	string inputUser;

	while (!myRoom_.getIsGameOver()) {
		getline(cin, inputUser);
		userInput_.setInput(inputUser);
		// is the input an "x"
		if (inputUser == "x" || inputUser == "X") {
			myRoom_.setIsGameOver(true);
			cout << "\033[1;91m" << "\nYou quit, the game is over!" << "\033[0m" << "\n";
			break;
		}
		// is the input a "look"
		else if (userInput_.getInput().compare("look") == 0) {
			displayRoom();
		}
		// is the input a "use"
		else if (userInput_.getInput().compare("use") == 0) {
			myRoom_.getCurrentRoom()->useItem(0);
			cout << "\n";
			displayRoom();
		}
		// is the input a valid index
		else if (userInput_.isIndexValid()) {
			if (myRoom_.getCurrentRoom()->getNeighbour(userInput_.getIndex()) == nullptr) {
				cout << "\033[1;96m" << "\nOups, you can't go there. Try again!" << "\033[0m" << "\n";
				cout << "\033[1;96m" << " >> " << "\033[0m";
			}
			else {
				myRoom_.setCurrentRoom(userInput_.getIndex());
				displayRoom();
			}
		}else {
					cout << "\033[1;96m" << "\nThe entry is invalid. Try Again!" << "\033[0m" << "\n";
					cout << "\033[1;96m" << " >> " << "\033[0m";
				}
	}
}
