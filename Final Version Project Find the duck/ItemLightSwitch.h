/****************************************************************************************************************************************************************************************
Description:		Header file of ItemLightSwitch class
File:				ItemLightSwitch.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			June 08 2021
****************************************************************************************************************************************************************************************/
#pragma once

#include "Item.h"
#include "RoomWithLight.h"

class ItemLightSwitch : public Item
{
public:
	using Item::Item;

	ItemLightSwitch(string name, string description, string usage, RoomWithLight* room) : Item(name, description, usage) {
		myRoom_ = room;
	}

	void use() override;

private:
	RoomWithLight* myRoom_;
};

