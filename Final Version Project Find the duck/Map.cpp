/****************************************************************************************************************************************************************************************
Description:		implementation of class Map.h
File:				Map.cpp
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#include <string>
#include <fstream>

using namespace std;

#include "Map.h"

Map::Map(string file) {
	createMap(file);
}

vector<Room*> Map::getMap() {
	vector<Room*> mapCopy;
	for (int i = 0; i < map_.size(); i++) {
		mapCopy.push_back(map_[i].get());
	}
	return mapCopy;
}

/*
 * Function that search for a specific room in map with the name giving in parameter
 * \param	(string)				name of the room we're searching for 
 * \return	(shared_ptr<Room>)		The room's pointer or a nullptr
 **/
Room* Map::searchRoom(string name) {
	for (int i = 0; i < map_.size(); i++) {
		if (map_[i]->getName() == name) {
			return map_[i].get();
		}
	}
	return nullptr;
}

int Map::searchIndexRoom(string name) {
	for (int i = 0; i < map_.size(); i++) {
		if (map_[i]->getName() == name) {
			return i;
		}
	}
}

/*
 * Function that read a stream and creates a room if not found in the map
 * \param	(ifstream&)				refference to stream
 * \return	(shared_ptr<Room>)		The room's pointer
 **/
void Map::createRoom(ifstream& f) {
	string name;
	string description;
	string b;
	bool isLocked;

	getline(f, name, '\t');
	getline(f, description,'\t');
	getline(f, b);
	isLocked = stoi(b);

	map_.push_back(make_unique<Room>(name, description, isLocked));
}

RoomWithLight* Map::createRoomWithLight(ifstream& f) {
	string name;
	string description;
	string b;
	bool isLocked;

	getline(f, name, '\t');
	getline(f, description, '\t');
	getline(f, b);
	isLocked = stoi(b);

	unique_ptr<RoomWithLight> roomTemp = make_unique<RoomWithLight>(name, description, isLocked);
	RoomWithLight* roomptr = roomTemp.get();
	map_.push_back(move(roomTemp));

	return roomptr;
}

void Map::createLightSwitch(ifstream& f) {
	string roomName;
	string name;
	string description;
	string usage;

	getline(f, roomName, '\t');
	getline(f, name, '\t');
	getline(f, description, '\t');
	getline(f, usage);

	searchRoom(roomName)->addItem(make_unique<ItemLightSwitch>(name, description, usage, createRoomWithLight(f)));
}

/*
 * Function that read a stream and creates a room's neighbour
 * \param	(ifstream&)				refference to stream
 *			(shared_ptr<Room>)		The room's pointer
 * \return	void
 **/
void Map::createRoomNeighbours(ifstream& f) {
	string roomName;
	string neighbourName;

	getline(f, roomName, '\t');

	for (int i = 0; i < CARDINAL; i++) {
		if (i == CARDINAL - 1) {
			getline(f, neighbourName);
		}
		else {
			getline(f, neighbourName, '\t');
		}
		if (neighbourName != "x") {
			map_[searchIndexRoom(roomName)]->addNeighbour(searchRoom(neighbourName), i);
		}
		else {
			map_[searchIndexRoom(roomName)]->addNeighbour(nullptr, i);
		}
	}
}

void Map::createBasicItem(ifstream& f) {
	string roomName;
	string name;
	string description;
	string usage;

	getline(f, roomName, '\t');
	getline(f, name, '\t');
	getline(f, description, '\t');
	getline(f, usage);

	searchRoom(roomName)->addItem(make_unique<BasicItem>(name, description, usage));
}

void Map::createKey(ifstream& f) {
	string roomName;
	string name;
	string description;
	string usage;
	string dynamicRoomName;
	
	vector<Room*> map = getMap();

	getline(f, roomName, '\t');
	getline(f, name, '\t');
	getline(f, description, '\t');
	getline(f, usage, '\t');
	getline(f, dynamicRoomName);

	searchRoom(roomName)->addItem(make_unique<ItemKey>(name, description, usage, dynamicRoomName, map));
}

void Map::createMap(string file) {
	ifstream roomFile(file);
	string type;
	while (!roomFile.eof()) {
		getline(roomFile, type, '\t');
		switch (stoi(type)) {
		case ROOM:
			createRoom(roomFile);
			break;
		case SWITCH:
			createLightSwitch(roomFile);
			break;
		case NEIGHBOUR:
			createRoomNeighbours(roomFile);
			break;
		case ITEM:
			createBasicItem(roomFile);
			break;
		case KEY:
			createKey(roomFile);
			break;
		}
	}
}