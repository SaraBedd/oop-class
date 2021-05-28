#include "Game.h"


void Game::runJeu() {

	cout << "\u001b[33;1m" << " > > > > > > > > > > > > > > > >     INF1015 ROOM EXPLORER 2021     < < < < < < < < < < < < < < < < < " << "\n"
		<< " > > > - - - - - - - - - - - - - - - - - -  GOTY EDITION  - - - - - - - - - - - - - - - - - - - < < < " << "\u001b[0m" << "\n\n";
	cout << "A duck enterred the house, try to find it!" << "\n";
	cout << "You can explore the rooms by entering the direction you wish to go at." << "\n";
	cout << "Special command: " << "\033[1;91m" << "x " << "\033[0m" << "\t-> To exit game" << "\n";
	cout << "\t\t" << "\033[1;91m" << " look " << "\033[0m" << "\t-> To display current room" << "\n\n";

	myRoom_.displayCurrrentRoom();
	
	string inputUser;

	while (!myRoom_.getIsGameOver()) {
		getline(cin, inputUser);

		if (inputUser == "x" || inputUser == "X") {
			myRoom_.setIsGameOver(true);
			cout << "\033[1;91m" << "You quit, the game is over!" << "\033[0m" << "\n";
			break;
		}else {
			userInput_.setInput(inputUser);
			if (userInput_.getInput().compare("look") == 0) {
				myRoom_.displayCurrrentRoom();
			}
			else {
				if (userInput_.isIndexValid()) {
					if (myRoom_.getCurrentRoom()->getNeighbour(userInput_.getIndex()) == nullptr) {
						cout << "\nOups, you can't go there. Try again!" << "\n";
						cout << "\033[1;92m" << " >> " << "\033[0m";
					}
					else {
						myRoom_.setCurrentRoom(userInput_.getIndex());
						myRoom_.displayCurrrentRoom();
					}
				}
				else {
					cout << "\nThe entry is invalid. Try Again!" << "\n";
					cout << "\033[1;92m" << " >> " << "\033[0m";
				}
			}
		}

		
	}
}
