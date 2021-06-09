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

/*
 * Map constructor
 * \param	(string)	the file name containing the Room's name, description and neighbours
 * \return	void
 **/
Map::Map(string fileRoom, string fileRoomWithLight, string fileNeighbour, string fileItem, string fileLightSwitch, string fileKey) {
	createMap(fileRoom, fileRoomWithLight, fileNeighbour, fileItem, fileLightSwitch, fileKey);
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

void Map::createRoomWithLight(ifstream& f) {
	string name;
	string description;
	string b;
	bool isLocked;

	getline(f, name, '\t');
	getline(f, description, '\t');
	getline(f, b);
	isLocked = stoi(b);

	map_.push_back(make_unique<RoomWithLight>(name, description, isLocked));
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

void Map::createLightSwitch(ifstream& f) {
	string roomName;
	string name;
	string description;
	string usage;
	string dynamicRoomName;
	Room* dynamicRoom;

	getline(f, roomName, '\t');
	getline(f, name, '\t');
	getline(f, description, '\t');
	getline(f, usage, '\t');
	getline(f, dynamicRoomName);
	dynamicRoom = searchRoom(dynamicRoomName);

	searchRoom(roomName)->addItem(make_unique<ItemLightSwitch>(name, description, usage, dynamicRoom));
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

/*
* Function that creates a map based on a file
* \param	(string)	the file name containing the Room's name, description and neighbours
* \return	void
**/
void Map::createMap(string fileRoom, string fileRoomWithLight, string fileNeighbour, string fileItem, string fileLightSwitch, string fileKey) {
	ifstream roomFile(fileRoom);
	while (!roomFile.eof()) {
		createRoom(roomFile);
	}
	ifstream roomWithLightFile(fileRoomWithLight);
	while (!roomWithLightFile.eof()) {
		createRoomWithLight(roomWithLightFile);
	}
	ifstream neighbourFile(fileNeighbour);
	while (!neighbourFile.eof()) {
		createRoomNeighbours(neighbourFile);
	}
	ifstream itemFile(fileItem);
	while (!itemFile.eof()) {
		createBasicItem(itemFile);
	}
	ifstream lightSwitchFile(fileLightSwitch);
	while (!lightSwitchFile.eof()) {
		createLightSwitch(lightSwitchFile);
	}
	ifstream keyFile(fileKey);
	while (!keyFile.eof()) {
		createKey(keyFile);
	}
}