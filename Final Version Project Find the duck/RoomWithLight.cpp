#include "RoomWithLight.h"

string RoomWithLight::getDescription() {
	if (isSwitchOn_ == true) {
		return Room::getDescription();
	}
	else { return "No light!"; }
}

vector<Item*> RoomWithLight::getItem() {
	if (isSwitchOn_ == true) {
		return Room::getItem();
	}
	else { return vector<Item*>(); }
}

void RoomWithLight::setSwitch(bool isSwitchOn)  {
	isSwitchOn_ = isSwitchOn;
}

bool RoomWithLight::getSwitch() {
	return isSwitchOn_;
}