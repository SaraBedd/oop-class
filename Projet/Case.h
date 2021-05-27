#pragma once
#include<iostream>
#include <string>
#include <span>
#include <memory>
using namespace std;

int const CARDINAL = 4;
int const OUEST = 0, NORTH = 1, EAST = 2, SOUTH = 3;

class Case
{
public:
	Case() = default;

	Case(string nom);

	Case(string nom, string description);

	string getName();

	string getDescription();

	shared_ptr<Case> getVoisins(int index);

	void setName(string name);

	void setDescription(string description);

	void addVoisin(shared_ptr<Case> voisin, int cardinalite);

	void afficherVoisin(int index);

private:
	string name_;
	string description_;
	shared_ptr<Case> voisins_[CARDINAL] = {};
};
