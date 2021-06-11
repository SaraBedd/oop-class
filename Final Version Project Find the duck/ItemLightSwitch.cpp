/****************************************************************************************************************************************************************************************
Description:		implementation of class ItemLightSwitch.h
File:				ItemLightSwitch.cpp
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			June 08 2021
****************************************************************************************************************************************************************************************/
#include "ItemLightSwitch.h"

void ItemLightSwitch::use() {
	myRoom_->setSwitch(!(myRoom_->getSwitch()));
	cout << myRoom_->getName() << " ";
	if (myRoom_->getSwitch()) { cout << "is now lit!"; }
	else { cout << "is now dark!"; }
};
