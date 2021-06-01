#include "bibliotheque_cours/bibliotheque_cours.hpp"
#include "bibliotheque_cours/debogage_memoire.hpp"
#include "bibliotheque_cours/verification_allocation.hpp"
#include "Liste.hpp"
#include "Jeu.hpp"
#include "fonctions.hpp"
#include <iostream>
//TODO: Vos surcharges d'opérateur <<


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
	static const std::string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";
	//std::cout << ligneSeparation << lj;
	//TODO: Recherche d'un concepteur de votre choix avec la méthode à faire en passant un lambda pour le critère
	shared_ptr<Concepteur> concepteurTemp;
	for (int i = 0; i < lj.getNbElem(); i++) {
		concepteurTemp = lj[i]->trouverConcepteurLambda([](shared_ptr<Concepteur>& c) {return c->getName() == "Sara"; });
	}
	return 0;
}