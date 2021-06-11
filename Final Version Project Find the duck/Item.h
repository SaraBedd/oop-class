/****************************************************************************************************************************************************************************************
Description:		Header file of Item class
File:				Item.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			June 08 2021
****************************************************************************************************************************************************************************************/
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item
{
public:
	Item() = default;
	Item(string name, string description, string usage) : itemName_(name), itemDescription_(description), usage_(usage) {};

	virtual ~Item() = default;

	void look();
	virtual void use() {};

	string getName();
	string getDescription();
	string getUsage();

	void setName(string name);
	void setDescription(string description);
	void setUsage(string usage);

private:
	string itemName_;
	string itemDescription_;
	string usage_;
};

