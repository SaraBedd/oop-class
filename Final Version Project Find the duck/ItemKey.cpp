/****************************************************************************************************************************************************************************************
Description:		implementation of class ItemKey.h
File:				ItemKey.cpp
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			June 08 2021
****************************************************************************************************************************************************************************************/
#include "ItemKey.h"

void ItemKey::use() {
	if (searchLockedRoom(lockedRoom_)->getIsLocked()) {
		unlock(lockedRoom_);
		searchLockedRoom(lockedRoom_)->setIsLocked(false);
		cout << searchLockedRoom(lockedRoom_)->Room::getName() << " is now unlocked. \n";
	}
	else if (!(searchLockedRoom(lockedRoom_)->getIsLocked())) {
		lock(lockedRoom_);
		searchLockedRoom(lockedRoom_)->setIsLocked(true);
		cout << searchLockedRoom(lockedRoom_)->Room::getName() << " is now locked. \n";
	}
};

/*
* Function that search for a specific room in map with the name giving in parameter
* \param	(string)				name of the room we're searching for
* \return	(shared_ptr<Room>)		The room's pointer or a nullptr
**/
Room* ItemKey::searchLockedRoom(string name) {
	for (int i = 0; i < myMap_.size(); i++) {
		if (myMap_[i]->getName() == name) {
			return myMap_[i];
		}
	}
	return nullptr;
}

void ItemKey::lock(string lockedRoom) {
	for (int i = 0; i < myMap_.size(); i++) {
		for (int j = 0; j < CARDINAL; j++) {
			if (myMap_[i]->getNeighbour(j) != nullptr && myMap_[i]->getNeighbour(j)->getName() == lockedRoom) {
				myMap_[i]->resetNeighbour(j);
			}
		}
	}
}

void ItemKey::unlock(string unlockedRoom) {
	for (int i = 0; i < myMap_.size(); i++) {
		if (myMap_[i]->getName() == unlockedRoom) {
			for (int j = 0; j < CARDINAL; j++) {
				if (myMap_[i]->getNeighbour(j) != nullptr) {
					myMap_[i]->getNeighbour(j)->addNeighbour(myMap_[i], DIRECTIONOPPOSE[j]);
				}
			}
		}
	}
}