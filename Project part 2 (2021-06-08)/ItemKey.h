#pragma once
#include "Item.h"
#include "Map.h"
#include "Room.h"

class ItemKey : public Item
{
public:
	using Item::Item;

	ItemKey(string name, string description, string usage, string room, vector<Room*> map) : Item(name, description, usage) {
		lockedRoom_ = room;
		myMap_ = map;
	}

	void use() override {
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
	Room* searchLockedRoom(string name) {
		for (int i = 0; i < myMap_.size(); i++) {
			if (myMap_[i]->getName() == name) {
				return myMap_[i];
			}
		}
		return nullptr;
	}

	void lock(string lockedRoom) {
		for (int i = 0; i < myMap_.size(); i++) {
			for (int j = 0; j < CARDINAL; j++) {
				if (myMap_[i]->getNeighbour(j) != nullptr && myMap_[i]->getNeighbour(j)->getName() == lockedRoom) {
					myMap_[i]->resetNeighbour(j);
				}
			}
		}
	}

	void unlock(string unlockedRoom) {
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

private:
	string lockedRoom_;
	vector<Room*> myMap_;
};

