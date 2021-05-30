#include "Developpeur.hpp"
#include "Jeu.hpp"
#include "cppitertools/range.hpp"
#include <iostream>
// TODO
// implŽmenter les mŽthodes

Developpeur::Developpeur(std::string nom) {
	paireNomJeux_.first = nom;
	paireNomJeux_.second.elements = nullptr;
}

Developpeur::~Developpeur(void) {
	delete[] paireNomJeux_.second.elements;
}

const std::string Developpeur::getName(void) {
	return paireNomJeux_.first;
}

unsigned int Developpeur::compterJeux(const ListeJeux& lj1) {
	/*return paireNomJeux_.second.nElements;*/
	/*unsigned int n = 0;
	for (int i : iter::range(lj1.nElements)) {
		if ((lj1.elements[i]->developpeur.compare(paireNomJeux_.first)) == 0){
			n++;
		}
	}

	return n;*/

	
	unsigned int compteur = 0;
	for (Jeu* j : spanListeJeux(lj1)) {
		if (paireNomJeux_.first.compare(j->developpeur) == 0) {
			compteur++;
		}
	}
	return compteur;
	
}
void Developpeur::ajouterJeux(const ListeJeux& lj1) {
	paireNomJeux_.second.nElements = 0;
	paireNomJeux_.second.capacite = compterJeux(lj1);
	paireNomJeux_.second.elements = new Jeu * [compterJeux(lj1)];

	for (Jeu* j:spanListeJeux(lj1)) {
		if ((j->developpeur.compare(paireNomJeux_.first)) == 0) {
			
			paireNomJeux_.second.elements[paireNomJeux_.second.nElements] = j;
			paireNomJeux_.second.nElements++;
		}
	}
}

void Developpeur::afficher(void) {
	
	if (paireNomJeux_.second.capacite == 0) {
		std::cout << "Le développeur n'a pas développé de jeu";
	}

	else {
		std::cout << "Le développeur" << paireNomJeux_.first << "a développé les jeux suivants:" << std::endl;
		for (int i : iter::range(paireNomJeux_.second.capacite)) {
			std::cout << paireNomJeux_.second.elements[i]->titre << ", ";
		}
	}



}


// Param type ListeJeux car on s'en sert pour itérer sur une liste jeux externe
gsl::span<Jeu*> Developpeur::Developpeur::spanListeJeux(const ListeJeux& lj) 
{
	return gsl::span(lj.elements, lj.nElements);
}
