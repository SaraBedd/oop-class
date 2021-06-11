/****************************************************************************************************************************************************************************************
Description:		Header file of ItemKey class
File:				ItemKey.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			June 08 2021
****************************************************************************************************************************************************************************************/
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

	void use() override;

	Room* searchLockedRoom(string name);

	void lock(string lockedRoom);

	void unlock(string unlockedRoom);

private:
	string lockedRoom_;
	vector<Room*> myMap_;
};

