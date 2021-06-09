/****************************************************************************************************************************************************************************************
Description:		Header file of Map class
File:				Map.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#pragma once
#include<iostream>
#include<memory>
#include <vector>
#include<iterator>

#include "Room.h"
#include "RoomWithLight.h"
#include "Item.h"
#include "BasicItem.h"
#include "ItemLightSwitch.h"
#include "ItemKey.h"

using namespace std;

class Map
{
public:
	Map() = default;

	Map(string fileRoom, string fileRoomWithLight, string fileNeighbour, string fileItem, string fileLightSwitch, string fileKey);

	vector<Room*> getMap();

	Room* searchRoom(string nom);

	int searchIndexRoom(string name);

	void createRoom(ifstream& f);

	void createRoomWithLight(ifstream& f);

	void createRoomNeighbours(ifstream& f);
	
	void createBasicItem(ifstream& f);

	void createLightSwitch(ifstream& f);

	void createKey(ifstream& f);

	void createMap(string fileRoom, string fileRoomWithLight, string fileNeighbour, string fileItem, string fileLightSwitch, string fileKey);

private:
	vector<unique_ptr<Room>> map_;
};

