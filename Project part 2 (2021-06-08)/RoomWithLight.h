#pragma once
#include "Room.h"

class RoomWithLight : public Room
{
public:
	using Room::Room;

	string getDescription() override {
		if (isSwitchOn_ == true) {
			return Room::getDescription();
		}
		else { return "No light!"; }
	}

	void setSwitch(bool isSwitchOn) {
		isSwitchOn_ = isSwitchOn;
	}

	bool getSwitch() {
		return isSwitchOn_;
	}

private:
	bool isSwitchOn_ = false;
};