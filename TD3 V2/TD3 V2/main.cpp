#include "bibliotheque_cours/bibliotheque_cours.hpp"
#include "bibliotheque_cours/debogage_memoire.hpp"
#include "bibliotheque_cours/verification_allocation.hpp"
#include "Liste.hpp"
#include "Jeu.hpp"
#include "fonctions.hpp"
#include <iostream>
//TODO: Vos surcharges d'opérateur <<
ostream& operator<<(ostream& lhs, Liste<Jeu> rhs) {
	for (unsigned int i = 0; i < rhs.getNbElem(); i++) {
		lhs << "Titre : " << "\033[94m" << rhs[i]->getTitre() << "\033[0m" << std::endl;
		lhs << "Parution : " << "\033[94m" << rhs[i]->getAnneeSortie() << "\033[0m"
			<< std::endl;
		lhs << "Développeur :  " << "\033[94m" << rhs[i]->getDeveloppeur() << "\033[0m"
			<< std::endl;
		for (unsigned int j = 0; j < rhs[i]->concepteurs_.getNbElem(); j++) {
			lhs << "\t" << rhs[i]->concepteurs_[j]->getName() << ", "
				<< rhs[i]->concepteurs_[j]->getAnneeNaissance() << ", "
				<< rhs[i]->concepteurs_[j]->getPays()
				<< std::endl;
		}
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
	static const std::string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	std::cout << ligneSeparation << lj;

	//TODO: Recherche d'un concepteur de votre choix avec la méthode à faire en passant un lambda pour le critère
	shared_ptr<Concepteur> concepteurTemp;
	for (int i = 0; i < lj.getNbElem(); i++) {
		concepteurTemp = (lj[i]->trouverConcepteurLambda(lj[i]->concepteurs_,[](shared_ptr<Concepteur>& c) {return c->getName() == "Motoi Sakuraba"; }));
	}
	return 0;
}