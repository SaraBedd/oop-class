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

void Game::displayWelcome() {
cout << BLUE << string(SPACE_WELCOME, '\n');
printf(R"EOF(
                                                                    ___  _   _  _____  _   ___   _  ____  
                                                                   |_ _|| \ | ||  ___|/ | / _ \ / || ___| 
                                                                    | | |  \| || |_   | || | | || ||___ \ 
                                                                    | | | |\  ||  _|  | || |_| || | ___) |
                                                                   |___||_| \_||_|    |_| \___/ |_||____/ 
                    ____                                               _                          
                   |  _ \  ___    ___   _ __ ___     ___ __  __ _ __  | |  ___   _ __  ___  _ __ 
                   | |_) |/ _ \  / _ \ | '_ ` _ \   / _ \\ \/ /| '_ \ | | / _ \ | '__|/ _ \| '__|
                   |  _ <| (_) || (_) || | | | | | |  __/ >  < | |_) || || (_) || |  |  __/| |   
                   |_| \_\\___/  \___/ |_| |_| |_|  \___|/_/\_\| .__/ |_| \___/ |_|   \___||_|   
                                                               |_|                               
     ____                _                _  _  _    _               
    |  _ \  _   _   ___ | | __   ___   __| |(_)| |_ (_)  ___   _ __  
    | | | || | | | / __|| |/ /  / _ \ / _` || || __|| | / _ \ | '_ \ 
    | |_| || |_| || (__ |   <  |  __/| (_| || || |_ | || (_) || | | |
    |____/  \__,_| \___||_|\_\  \___| \__,_||_| \__||_| \___/ |_| |_|
                                                                      
)EOF");
cout << RED << string(SPACE_ENTER, '\n');
cout << "                                                 press Enter";
cout << COLOR_END;
}

void Game::displayHeader() {
	cout << YELLOW << " > > > > > > > > > > > > > > > >     INF1015 ROOM EXPLORER 2021     < < < < < < < < < < < < < < < < < " << "\n"
		<< " > > > - - - - - - - - - - - - - - - - - -  DUCK EDITION  - - - - - - - - - - - - - - - - - - - < < < " << YELLOW_END << "\n\n";
	cout << "A duck enterred the house, try to find it!" << "\n";
	cout << "You can explore the rooms by entering the direction you wish to go at." << "\n";
	cout << "Special command: " << RED << "x " << COLOR_END << "\t\t  -> To exit game" << "\n";
	cout << "\t\t" << RED << " look " << COLOR_END << "\t\t  -> To display current room" << "\n";
	cout << "\t\t" << RED << " look \"item name\"" << COLOR_END << " -> To display item description" << "\n";
	cout << "\t\t" << RED << " use \"item name\"" << COLOR_END << "  -> To use the item" << "\n\n";
}

/*
 * Displays the name of the room, its description, and each of its neighbours
 * \param	void
 * \return	void
 **/
void Game::displayRoom() {
	cout << "\n" << PURPLE << "= = =   " << myRoom_.getCurrentRoom()->getName() << "   = = =" << "\n" << COLOR_END;
	cout << myRoom_.getCurrentRoom()->getDescription() << "\n";
	if (myRoom_.getCurrentRoom()->getItem().size() != 0) {
		displayItems();
	}

	for (int i = 0; i < CARDINAL; i++) {
		if (myRoom_.getCurrentRoom()->getNeighbour(i) != nullptr) {
			displayNeighbour(i);
			cout << "\n";
		}
	}
	cout << BLUE << "\n >> " << COLOR_END;
}

/*
 * Displays the neighbour given at index position given in argument,
 * in vector DIRECTIONWORD
 * \param	(int)	index of neighbour to display
 * \return	void
 **/
void Game::displayNeighbour(int index) {
	cout << myRoom_.getCurrentRoom()->getNeighbour(index)->getName();
	cout << " is " << DIRECTIONWORD[index] << BLUE << " (" << DIRECTIONCHAR[index] << ")" << COLOR_END;
}

void Game::displayItems() {
	cout << "You notice:\n";
	for (int i = 0; i < myRoom_.getCurrentRoom()->getItem().size(); i++) {
		cout << "   " << myRoom_.getCurrentRoom()->getItem()[i]->getName() << "\n";
	}
}

void Game::displayItemDescription(int index) {
	cout << myRoom_.getCurrentRoom()->getItem()[index]->getDescription();
	cout << BLUE << "\n\n >> " << COLOR_END;
}

void Game::displayUsage(int index) {
	myRoom_.getCurrentRoom()->getItem()[index]->use();
	if (myRoom_.getCurrentRoom()->getItem()[index]->getName().compare("The duck") == 0) {
		myRoom_.setIsDuckCaught(true);
	}
	cout << BLUE << "\n\n >> " << COLOR_END;
}

void Game::displayQuitGame() {
	myRoom_.setIsGameOver(true);
	cout << RED << "\nYou quit, the game is over!" << COLOR_END << "\n";
}

void Game::displayValidInput() {
	if (myRoom_.getCurrentRoom()->getNeighbour(userInput_.getRoomIndex()) == nullptr) {
		cout << BLUE << "\nOups, you can't go there. Try again!" << COLOR_END << "\n";
		cout << BLUE << " >> " << COLOR_END;
	}
	else {
		myRoom_.setCurrentRoom(userInput_.getRoomIndex());
		displayRoom();
	}
}

void Game::displayInvalidInput() {
	cout << BLUE << "\nThe entry is invalid. Try Again!" << COLOR_END << "\n";
	cout << BLUE << " >> " << COLOR_END;
}

// This function was found online : https://mathbits.com/MathBits/CompSci/Screen/screen.h
// --------------------------------------------------------
// delay( ) -- Allow the screen to be "paused" for the
// number of seconds determined by the programmer.  Unlike 
// the system("PAUSE");, no message is displayed on the 
// screen.  (5000 = 5 seconds, approximately)
// --------------------------------------------------------
// Function for delay( )
void delay(long seconds)
{
	clock_t time1 = clock();  // use clock time
	clock_t time2 = time1 + seconds;
	while (time1 < time2)
		time1 = clock();
	return;
}

void displayDuckOne() {
	system("CLS");
	cout << YELLOW;
	cout << string(SPACE_DUCK, '\n');
	printf(R"EOF(
                                                               __
                                                              /` ,\__
            You Caught the Duck!                             |    ).-'    ~ Quack ~ Quack ~
                                                            / .--'
                                                           / /
                                             ,      _.==''`  \
                                           .'(  _.='         |
                                          {   ``  _.='       |
                                           {    \`     ;    /
                                            `.   `'=..'  .='
                                              `=._    .='
                                                '-`\\`__
                                                    `-._{
)EOF");
	cout << YELLOW_END;
}

void displayDuckTwo() {
	system("CLS");
	cout << YELLOW;
	cout << string(SPACE_DUCK, '\n');
	printf(R"EOF(


            You Caught the Duck!            _          _   
                                            \`.__..--'' `.
                                            ( _          ,\
                                           ( <_< < <   `','`.
                                            \ (_< < <    \   `.
                                             `. `----'   (  q _p
                                               `-._  _.-' `-(_''\
                                                (_'))--,      `._\     ~ Quack ~ Quack ~
                                                   `-._<
)EOF");
	cout << YELLOW_END;
}

void Game::displayDuck() {
	for (int i = 0; i < DUCK_FRAMES; i++) {
		displayDuckOne();
		delay(TIME_DELAY);
		displayDuckTwo();
		delay(TIME_DELAY);
	}
}

void Game::lookItem() {
	if (userInput_.stringToItem(myRoom_.getCurrentRoom()->getItem())) {
		displayItemDescription(userInput_.getItemIndex());
	}else { displayInvalidInput(); }
}

void Game::useItem() {
	if (userInput_.stringToItem(myRoom_.getCurrentRoom()->getItem())) {
		
		displayUsage(userInput_.getItemIndex());
	}else { displayInvalidInput(); }
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
void Game::runGame() {
	do {
		displayWelcome();
	} while (cin.get() != '\n');

	system("CLS");
	
	displayHeader();

	displayRoom();

	string inputUser;
	
	while (!myRoom_.getIsGameOver() && !myRoom_.getIsDuckCaught()) {
		
		getline(cin, inputUser);
		
		userInput_.setInput(inputUser);

		userInput_.toLower();

		if (inputUser.find(' ')!= string::npos) {
			userInput_.setCommand(inputUser.substr(0, inputUser.find(' ')));
			userInput_.setItem(inputUser.substr(inputUser.find(' ') + 1, inputUser.size()));
		}
		// is the input an "x"
		if (userInput_.getInput() == "x") {
			displayQuitGame();
			break;
		}
		// is the input a "look"
		else if (userInput_.getInput().compare("look") == 0) {
			displayRoom();
		}
		// is the input a valid index
		else if (userInput_.isIndexValid()) {
			displayValidInput();
		}
		// is the input a "look"
		else if (userInput_.getCommand().compare("look") == 0) {
			lookItem();
		}
		// is the input a "use" item
		else if (userInput_.getCommand().compare("use") == 0){
			useItem();
		}
		// entry is invalid
		else {displayInvalidInput();}
	}
	if (myRoom_.getIsDuckCaught()) {
		displayDuck();
	}
}