#include "Room.h"

/*Constructor of Room class*/
Room::Room(string nom) :name_(nom) {};

/*Parameterized constructor of Room class*/
Room::Room(string nom, string description) :name_(nom), description_(description) {};

/*Returns value of name_ attribute (the name of the room).*/
string Room::getName() { return name_; }

/*Returns value of description_attribute, which describes each room.*/
string Room::getDescription() { return description_; }

/*Returns the neighbour (of the room in question) at index position
given in argument.*/
shared_ptr<Room> Room::getNeighbour(int index) {
	return neighbours_[index];
}

/*Sets the value of name_ attribute to name value given in argument.*/
void Room::setName(string name) {
	name_ = name;
}

/*Sets the value of description_ attribute to description value given
in argument.*/
void Room::setDescription(string description) {
	description_ = description;
}

/*Adds a neighbour to the list of shared_ptr neighbours_ attribute. */
void Room::addNeighbour(shared_ptr<Room> neighbour, int index) {
	neighbours_[index] = neighbour;
}

/*Displays the name of the room, its description, and each of its 
neighbours.*/
void Room::displayRoom() {
	cout << "\n" << "\033[1;95m" << "= = =   " << name_ << "   = = =" << "\n" << "\033[0m";
	cout << description_ << "\n";
	for (int i = 0; i < CARDINAL; i++) {
		if (neighbours_[i] != nullptr) {
			displayNeighbour(i);
			cout << "\n";
		}
	}
	cout << "\033[1;92m" << " >> " << "\033[0m";
}

/*Displays the neighbour given at index position given in argument,
in vector DIRECTIONWORD.*/
void Room::displayNeighbour(int index) {
	cout << neighbours_[index]->getName();
	cout << " is " << DIRECTIONWORD[index] << "\033[1;95m" << " (" << DIRECTIONCHAR[index] << ")" << "\033[0m";
}

