#include <string>
#include <fstream>

using namespace std;

#include "Carte.h"

Carte::Carte(string fichier) {
	creerCarte(fichier);
}

shared_ptr<Case> Carte::rechercherCase(string nom) {
	for (int i = 0; i < carte_.size(); i++) {
		if (carte_[i]->getName() == nom) {
			return carte_[i];
		}
	}
	/*for (auto&& c : carte_) {
		if (c->getName() == nom) {
			return c;
		}
	}*/
	return nullptr;
}


void Carte::creerCarte(string fichier) {
	ifstream roomFile(fichier);
	while (!roomFile.eof()) {

		string nom;
		string description;
		getline(roomFile, nom, '\t');
		getline(roomFile, description, '\t');

		shared_ptr<Case> caseCourante;

		if (rechercherCase(nom) == nullptr) {
			caseCourante = make_shared<Case>(nom, description);
			carte_.push_back(caseCourante);
		}
		else {
			caseCourante = rechercherCase(nom);
			if (caseCourante->getDescription().empty()) {
				caseCourante->setDescription(description);
			}
		}

		for (int i = 0; i < CARDINAL; i++) {
			string nomVoisin;
			if (i == CARDINAL - 1) {
				getline(roomFile, nomVoisin);
			}
			else {
				getline(roomFile, nomVoisin, '\t');
			}
			if (nomVoisin != "x") {
				shared_ptr<Case> voisin;
				voisin = make_shared<Case>(nomVoisin);
				caseCourante->addVoisin(voisin, i);
			}
		}
	}
}

vector<shared_ptr<Case>> Carte::getCarte() const {
	return carte_;
}

vector<shared_ptr<Case>> Carte::getCarte() {
	return carte_;
}
