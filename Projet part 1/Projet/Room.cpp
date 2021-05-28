#include "Room.h"

Room::Room(string nom) :name_(nom) {};

Room::Room(string nom, string description) :name_(nom), description_(description) {};

string Room::getName() { return name_; }

string Room::getDescription() { return description_; }

shared_ptr<Room> Room::getNeighbour(int index) {
	return neighbours_[index];
}

void Room::setName(string name) {
	name_ = name;
}

void Room::setDescription(string description) {
	description_ = description;
}

void Room::addNeighbour(shared_ptr<Room> neighbour, int index) {
	neighbours_[index] = neighbour;
}

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

void Room::displayNeighbour(int index) {
	cout << neighbours_[index]->getName();
	cout << " is " << DIRECTIONWORD[index] << "\033[1;95m" << " (" << DIRECTIONCHAR[index] << ")" << "\033[0m";
}

