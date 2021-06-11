/****************************************************************************************************************************************************************************************
Description:		implementation of class Item.h
File:				Item.cpp
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			June 08 2021
****************************************************************************************************************************************************************************************/
#include "Item.h"

void Item::look() {
	cout << itemDescription_;
}

string Item::getName() {return itemName_;}
string Item::getDescription() { return itemDescription_; }
string Item::getUsage() { return usage_; }

void Item::setName(string name) { itemName_ = name; }
void Item::setDescription(string description) { itemDescription_ = description; }
void Item::setUsage(string usage) { usage_ = usage; }