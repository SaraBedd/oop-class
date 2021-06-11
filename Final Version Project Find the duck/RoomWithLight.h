/****************************************************************************************************************************************************************************************
Description:		Header file of RoomWithLight class
File:				RoomWithLight.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			June 08 2021
****************************************************************************************************************************************************************************************/
#pragma once
#include "Room.h"

class RoomWithLight : public Room
{
public:
	using Room::Room;

	string getDescription() override;

	vector<Item*> getItem() override;

	void setSwitch(bool isSwitchOn);

	bool getSwitch();

private:
	bool isSwitchOn_ = false;
};