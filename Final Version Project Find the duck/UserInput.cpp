/****************************************************************************************************************************************************************************************
Description:		implementation of class UserInput.h
File:				UserInput.cpp
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#include "UserInput.h"

/*
 * Return index_ attribute
 * \param	void
 * \return	(int)	index_ attribute
 **/
int UserInput::getRoomIndex() {
	return RoomIndex_;
}

/*
 * Return index_ attribute
 * \param	void
 * \return	(int)	index_ attribute
 **/
int UserInput::getItemIndex() {
	return itemIndex_;
}

/*
 * Return input_ attribute in lowercase
 * \param	void
 * \return	(string)	input_ attribute
 **/
string UserInput::getCommand() {
	return command_;
}

/*
 * sets a value (taken in argument) to the input_ attribute
 * \param	(string)	User's input
 * \return	void
 **/
void UserInput::setCommand(string command) {
	command_ = command;
}

/*
 * Return input_ attribute in lowercase
 * \param	void
 * \return	(string)	input_ attribute
 **/
string UserInput::getInput() {
	return input_;
}

/*
 * sets a value (taken in argument) to the input_ attribute
 * \param	(string)	User's input
 * \return	void
 **/
void UserInput::setInput(string input) {
	input_ = input;
}

/*
 * Return input_ attribute in lowercase
 * \param	void
 * \return	(string)	input_ attribute
 **/
string UserInput::getItem() {
	return item_;
}

/*
 * sets a value (taken in argument) to the input_ attribute
 * \param	(string)	User's input
 * \return	void
 **/
void UserInput::setItem(string item) {
	item_ = item;
}


/*
 * Puts the input in lowercase
 * \param	void
 * \return	void
 **/
void UserInput::toLower() {
	input_ = to_lower_copy(input_);
}

/*
 * Takes the first element of input, puts it in uppercase, 
 * finds a match between that element and a char element of vector
 * DIRECTIONCHAR. If a match is found, assigns the position of 
 * DIRECTIONCHAR element to index_attribute.
 * Returns true if match is found, false if not.
 * \param	void
 * \return	bool	true if match is found, false if not
 **/
bool UserInput::charToIndex() {
	char input = toupper(input_[0]);
	for (int i = 0; i < DIRECTIONCHAR.size(); i++) {
		if (input == DIRECTIONCHAR[i]) {
			RoomIndex_ = i;
			return true;
		}
	}
	return false;
}

/*
 * Takes the first occurence of each string 
 * element of vector DIRECTIONWORD and puts it in iterator r.
 * If string r not empty, assign the position of element in 
 * DIRECTIONWORD to index_ attribute. Returns true if match
 * is found, false if not
 * \param	void
 * \return	bool	true if match is found, false if not
 **/
bool UserInput::stringToIndex() {
	toLower();
	for (int i = 0; i < DIRECTIONWORD.size(); i++) {
		iterator_range<string::iterator> r = find_first(input_, DIRECTIONWORD[i]);
		if (!r.empty()) {
			RoomIndex_ = i;
			return true;
		}
	}
	return false;
}

/*
 * Takes the first occurence of each string
 * element of vector DIRECTIONWORD and puts it in iterator r.
 * If string r not empty, assign the position of element in
 * DIRECTIONWORD to index_ attribute. Returns true if match
 * is found, false if not
 * \param	void
 * \return	bool	true if match is found, false if not
 **/
bool UserInput::stringToItem(vector<Item*> items) {
	for (int i = 0; i < items.size(); i++) {
		string item = to_lower_copy(items[i]->getName());
		if (item.find(item_)!= string::npos) {
			itemIndex_ = i;
			return true;
		}
	}
	return false;
}

/*
 * Function that returns true if a substring in input_ matches 
 * one of the elements of DIRECTIONWORD, OR if first element 
 * of input_ matches one of the elements of DIRECTIONCHAR.
 * If neither condition is verified, returns false.
 * \param	void
 * \return	(bool)	true if condition is verified, false if not
 **/
bool UserInput::isIndexValid() {
	if (charToIndex() || stringToIndex()) {
		return true;
	}
	return false;
}
