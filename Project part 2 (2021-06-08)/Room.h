/****************************************************************************************************************************************************************************************
Description:		Header file of Room class
File:				Room.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#pragma once
#include<iostream>
#include <string>
#include <span>
#include <vector>
#include <memory>

#include "Item.h"

using namespace std;

int const CARDINAL = 4;
int const WEST = 0, NORTH = 1, EAST = 2, SOUTH = 3;
int const DIRECTIONOPPOSE[] = { 2, 3, 0, 1 };
vector<string> const DIRECTIONWORD = { "west","north","east","south" };
vector<char> const DIRECTIONCHAR = { 'W','N','E','S' };

class Room
{
public:
	Room() = default;

	Room(string nom, string description, bool isLocked);

	string getName();

	virtual string getDescription();

	Room* getNeighbour(int index);

	bool getIsLocked();

	vector<Item*> getItem();

	void setName(string name);

	void setDescription(string description);

	void addNeighbour(Room* voisin, int index);

	void resetNeighbour(int index);

	void setIsLocked(bool isLocked);

	void addItem(unique_ptr<Item> item);

	void useItem(int index);

protected:
	string name_;
	string description_;
	Room* neighbours_[CARDINAL] = {};
	bool isLocked_;
	vector<unique_ptr<Item>> items_;
};

