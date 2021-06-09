#pragma once
#include "Room.h"

class RoomLocked : public Room 
{
	void setLock(bool islocked) {
		isLocked_ = islocked;
	}

private:
	bool isLocked_ = true;
};

