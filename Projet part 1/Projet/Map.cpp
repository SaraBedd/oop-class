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
Map::Map(string file) {
	createMap(file);
}

/*
 * Map getter
 * \param	void
 * \return	(shared_ptr<Room>&)		refference to map[0]
 **/
shared_ptr<Room>& Map::getCarte(){
	return map_[0];
}

/*
 * Function that search for a specific room in map with the name giving in parameter
 * \param	(string)				name of the room we're searching for 
 * \return	(shared_ptr<Room>)		The room's pointer or a nullptr
 **/
shared_ptr<Room> Map::searchRoom(string name) {
	for (int i = 0; i < map_.size(); i++) {
		if (map_[i]->getName() == name) {
			return map_[i];
		}
	}
	return nullptr;
}

/*
 * Function that read a stream and creates a room if not found in the map
 * \param	(ifstream&)				refference to stream
 * \return	(shared_ptr<Room>)		The room's pointer
 **/
shared_ptr<Room> Map::createRoom(ifstream& f) {
	string nom;
	string description;
	getline(f, nom, '\t');
	getline(f, description, '\t');
	
	shared_ptr<Room> room;
	
	if (searchRoom(nom) == nullptr) {
		room = make_shared<Room>(nom, description);
		map_.push_back(room);
	}
	else {
		room = searchRoom(nom);
		if (room->getDescription().empty()) {
			room->setDescription(description);
		}
	}
	return room;
}

/*
 * Function that read a stream and creates a room's neighbour
 * \param	(ifstream&)				refference to stream
 *			(shared_ptr<Room>)		The room's pointer
 * \return	void
 **/
 void Map::createRoomNeighbours(shared_ptr<Room> room, ifstream& f) {
	 for (int i = 0; i < CARDINAL; i++) {
		 string neighbourName;
		 if (i == CARDINAL - 1) {
			 getline(f, neighbourName);
		 }
		 else {
			 getline(f, neighbourName, '\t');
		 }
		 if (neighbourName != "x") {
			 if (searchRoom(neighbourName) == nullptr) {
				 shared_ptr<Room> neighbour;
				 neighbour = make_shared<Room>(neighbourName);
				 map_.push_back(neighbour);
			 }
			 room->addNeighbour(searchRoom(neighbourName), i);
		 }
	 }
 }

 /*
 * Function that creates a map based on a file
 * \param	(string)	the file name containing the Room's name, description and neighbours
 * \return	void
 **/
void Map::createMap(string file) {
	ifstream roomFile(file);
	while (!roomFile.eof()) {
		shared_ptr<Room> room(createRoom(roomFile));
		createRoomNeighbours(room, roomFile);
	}
}

