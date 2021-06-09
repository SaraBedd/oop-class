#include "RoomWithLight.h"

string RoomWithLight::getDescription() {
	if (isSwitchOn_ == true) {
		return Room::getDescription();
	}
	else { return "No light!"; }
}

void RoomWithLight::setSwitch(bool isSwitchOn)  {
	isSwitchOn_ = isSwitchOn;
}

bool RoomWithLight::getSwitch() {
	return isSwitchOn_;
}