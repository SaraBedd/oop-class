#include "Case.h"

Case::Case(string nom) :name_(nom) {};

Case::Case(string nom, string description) :name_(nom), description_(description) {};

string Case::getName() { return name_; }

string Case::getDescription() { return description_; }

shared_ptr<Case> Case::getVoisins(int index) {
	return voisins_[index];
}

void Case::setName(string name) {
	name_ = name;
}

void Case::setDescription(string description) {
	description_ = description;
}

void Case::addVoisin(shared_ptr<Case> voisin, int cardinalite) {
	voisins_[cardinalite] = voisin;
}

void Case::afficherVoisin(int index) {
	cout << voisins_[index]->getName();
	switch (index) {
	case 0:
		cout << " est a l'Ouest (O)";
		break;
	case 1:
		cout << " est au Nord (N)";
		break;
	case 2:
		cout << " est a l'Est (E)";
		break;
	case 3:
		cout << " est au Sud (S)";
		break;
	}
}

