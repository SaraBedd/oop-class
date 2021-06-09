/****************************************************************************************************************************************************************************************
Description:		implementation of class Room.h
File:				Room.cpp
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#include "Room.h"

/*
 * Parameterized constructor of Room class
 * \param	(string)	room name
 *			(string)	room description
 *			(bool)		isLocked
 * \return
 **/
Room::Room(string nom, string description, bool isLocked) :name_(nom), description_(description), isLocked_(isLocked) {};

/*
 * Returns value of name_ attribute (the name of the room)
 * \param	void
 * \return	(string)	room name
 **/
string Room::getName() { return name_; }

/*
 * Returns value of description_attribute, which describes each room
 * \param	void
 * \return	(string)	room description
 **/
string Room::getDescription() { return description_; }

/*
 * Returns the neighbour (of the room in question) at index position
 * given in argument
 * \param	(int)				neighbour's index
 * \return	(shared_ptr<Room>)	neighbour pointer
 **/
Room* Room::getNeighbour(int index) {
	return neighbours_[index];
}

vector<Item*> Room::getItem() {
	vector<Item*> itemCopy;
	for (int i = 0; i < items_.size(); i++) {
		itemCopy.push_back(items_[i].get());
	}
	return itemCopy;
}

bool Room::getIsLocked() {
	return isLocked_;
}

/*
 * Sets the value of name_ attribute to name value given in argument
 * \param	(string)	room name
 * \return	void
 **/
void Room::setName(string name) {
	name_ = name;
}

/*
 * Sets the value of description_ attribute to description value given
 * in argument
 * \param	(string)	room description
 * \return	void
 **/
void Room::setDescription(string description) {
	description_ = description;
}

/*
 * adds a neighbour to the list of shared_ptr neighbours_ attribute 
 * given the index passed in argument
 * \param	(shared_ptr<room>)	neighbour room pointer
 *			(int)				index
 * \return	void
 **/
void Room::addNeighbour(Room* neighbour, int index) {
	neighbours_[index] = neighbour;
}

/*
 * reset the neighbour at specified index in Room* neighbours_
 * given the index passed in argument
 * \param	(int)				index
 * \return	void
 **/
void Room::resetNeighbour(int index) {
	neighbours_[index] = nullptr;
}

void Room::setIsLocked(bool isLocked) {
	isLocked_ = isLocked;
}

void Room::addItem(unique_ptr<Item> item) {
	items_.push_back(move(item));
}

void Room::useItem(int index) {
	items_[index]->use();
}