#pragma once

#include "Item.h"
#include "RoomWithLight.h"

class ItemLightSwitch : public Item
{
public:
	using Item::Item;

	ItemLightSwitch(string name, string description, string usage, Room* room) : Item(name, description, usage) {
		myRoom_ = dynamic_cast<RoomWithLight*>(room);		// A gerer at some point!
	}

	void use() override {
		myRoom_->setSwitch(!(myRoom_->getSwitch()));
		cout << myRoom_->getName() << " ";
		if (myRoom_->getSwitch()) { cout << "is now lit!"; }
		else { cout << "is now dark!"; }
	};

private:
	RoomWithLight* myRoom_;
};

