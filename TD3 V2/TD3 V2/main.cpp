/*****************************************************************************************************
Description:		Fichier contenant la fonction principale du TD3
Fichier:			main.cpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	26 mai 2021
Date de remise:		01 juin 2021
******************************************************************************************************/

#include "bibliotheque_cours/bibliotheque_cours.hpp"
#include "bibliotheque_cours/debogage_memoire.hpp"
#include "bibliotheque_cours/verification_allocation.hpp"
#include "Liste.hpp"
#include "Jeu.hpp"
#include "fonctions.hpp"
#include <iostream>

ostream& operator<<(ostream& lhs, Concepteur& rhs){
	lhs << "\t" << rhs.getName() << ", " 
		<< rhs.getAnneeNaissance() << ", "
		<< rhs.getPays()
		<< std::endl;
	return lhs;
}

ostream& operator<<(ostream& lhs, Jeu& rhs) {
	lhs << "Titre: " << "\033[96m" << rhs.getTitre() << "\033[0m" << "\n"
		<< "Annee de sortie: " << rhs.getAnneeSortie() << "\n"
		<< "Developpe par: " << rhs.getDeveloppeur() << "\n"
		<< "Designers du jeu " << "\n";
	for (unsigned int i = 0; i < rhs.concepteurs_.getNbElem(); i++) {
		lhs << *rhs.concepteurs_[i];
	}
	return lhs;
}

ostream& operator<<(ostream& lhs, Liste<Jeu>& rhs) {
	for (unsigned int i = 0; i < rhs.getNbElem(); i++) {
		lhs << "\033[95m""-----------------------------------------------------""\033[0m" << "\n"
			<< *rhs[i]
			<< "\033[95m""-----------------------------------------------------""\033[0m" << "\n";
	}
	return lhs;
}

int main(int argc, char** args)
{
	#pragma region "Bibliothèque du cours"
	#ifdef VERIFICATION_ALLOCATION_INCLUS
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	#endif
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	Liste<Jeu> lj = creerListeJeux("jeux.bin");

	cout << "\033[95m\n==============================================================\n"
		<< "Affichage de liste de jeux\n"
		<< "==============================================================\033[0m\n"
		<< "\033[95mVoici la liste des jeux viédo de jeux.bin :\033[0m" << "\n"
		<< lj;

	// Recherche d'un concepteur de votre choix avec la méthode à faire en passant un lambda pour le critère
	shared_ptr<Concepteur> concepteurTrouve;
	for (unsigned int i = 0; i < lj.getNbElem(); i++) {
		concepteurTrouve = (lj[i]->trouverConcepteurLambda([](shared_ptr<Concepteur>& c) {return c->getName() == "Motoi Sakuraba"; }));
	}

	cout << "\033[95m==============================================================\n"
		<< "Affichage du concepteur recherche par la fonction lambda\n"
		<< "==============================================================\033[0m\n"
		<< "On recherche le concepteur du nom Motoi Sakuraba.\n"
		<< "\033[96m" << "La fonction nous retourne le pointeur du concepteur "
		<< concepteurTrouve->getName() << "\033[0m\n";

	return 0;
}