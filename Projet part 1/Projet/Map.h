#pragma once
#include<iostream>
#include<memory>
#include <vector>
#include<iterator>

#include "Room.h"

using namespace std;

class Map
{
public:
	Map() = default;

	Map(string fichier);

	shared_ptr<Room> searchRoom(string nom);

	shared_ptr<Room> createRoom(ifstream& f);

	void createRoomNeighbours(shared_ptr<Room> room, ifstream& f);

	void createMap(string fichier);

	shared_ptr<Room>& getCarte();

private:
	vector<shared_ptr<Room>> map_;
};

