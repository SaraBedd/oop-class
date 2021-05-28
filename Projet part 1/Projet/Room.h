#pragma once
#include<iostream>
#include <string>
#include <span>
#include <vector>
#include <memory>
using namespace std;

int const CARDINAL = 4;
int const WEST = 0, NORTH = 1, EAST = 2, SOUTH = 3;
vector<string> const DIRECTIONWORD = { "west","north","east","south" };
vector<char> const DIRECTIONCHAR = { 'W','N','E','S' };

class Room
{
public:
	Room() = default;

	Room(string nom);

	Room(string nom, string description);

	string getName();

	string getDescription();

	shared_ptr<Room> getNeighbour(int index);

	void setName(string name);

	void setDescription(string description);

	void addNeighbour(shared_ptr<Room> voisin, int cardinalite);

	void displayRoom();

	void displayNeighbour(int index);

private:
	string name_;
	string description_;
	shared_ptr<Room> neighbours_[CARDINAL] = {};
};

