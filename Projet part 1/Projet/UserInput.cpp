#include "UserInput.h"

int UserInput::getIndex() {
	return index_;
}

string UserInput::getInput() {
	toLower();
	return input_;
}

void UserInput::setInput(string input) {
	input_ = input;
}

void UserInput::toLower() {
	input_ = to_lower_copy(input_);
}

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

bool UserInput::isIndexValid() {
	if (charToIndex() || stringToIndex()) {
		return true;
	}
	return false;
}
