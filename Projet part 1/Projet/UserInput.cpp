#include "UserInput.h"

/*finds and returns the index indicating which element of the 
vector DIRECTIONCHAR or DIRECTIONWORD is concerned 
(in other words, the index indicates which of the four directions
the user wants to take)*/
int UserInput::getIndex() {
	return index_;
}

/*finds and returns the input given by the user*/
string UserInput::getInput() {
	toLower();
	return input_;
}

/*sets a value (taken in argument) to the input_ attribute*/
void UserInput::setInput(string input) {
	input_ = input;
}

/*puts the input in lowercase*/
void UserInput::toLower() {
	input_ = to_lower_copy(input_);
}

/*takes the first element of input, puts it in uppercase, 
finds a match between that element and a char element of vector
DIRECTIONCHAR. If a match is found, assigns the position of 
DIRECTIONCHAR element to index_attribute.
Returns true if match is found, false if not.*/
bool UserInput::charToIndex() {
	char input = toupper(input_[0]);
	for (int i = 0; i < DIRECTIONCHAR.size(); i++) {
		if (input == DIRECTIONCHAR[i]) {
			index_ = i;
			return true;
		}
	}
	return false;
}


/*takes the first occurence of each string 
element of vector DIRECTIONWORD and puts it in iterator r.
If string r not empty, assign the position of element in 
DIRECTIONWORD to index_ attribute. Returns true if match
is found, false if not.*/
bool UserInput::stringToIndex() {
	toLower();
	for (int i = 0; i < DIRECTIONWORD.size(); i++) {
		iterator_range<string::iterator> r = find_first(input_, DIRECTIONWORD[i]);
		if (!r.empty()) {
			index_ = i;
			return true;
		}
	}
	return false;
}

/*If a substring in input_ matches one of the elements 
of DIRECTIONWORD, OR if first element of input_ matches 
one of the elements of DIRECTIONCHAR, returns true.
If neither condition is verified, returns false.*/
bool UserInput::isIndexValid() {
	if (charToIndex() || stringToIndex()) {
		return true;
	}
	return false;
}
