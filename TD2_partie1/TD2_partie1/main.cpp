#pragma region "Les includes"
#include "bibliotheque_cours/bibliotheque_cours.hpp"
#include "bibliotheque_cours/debogage_memoire.hpp"
#include "bibliotheque_cours/verification_allocation.hpp"
#include "fonctions.hpp"
#include "ListeDeveloppeurs.hpp"
#pragma endregion
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

	//PARTIE 1
	ListeJeux lj = creerListeJeux("jeux.bin");
	static const std::string ligneSeparation = "\n\033[92m"
	"-----------------------------------------------"
	"\033[0m\n";
	std::cout << ligneSeparation << std::endl;
	std::cout << "Voici la liste des jeux viédo de jeux.bin :" << std::endl;
	afficherListeJeux(lj);

	// PARTIE 2
	ListeDeveloppeurs ld;
	// Création des développeurs externes à la liste des développeur
	Developpeur* nintendo = new Developpeur("Nintendo");
	Developpeur* square = new Developpeur("Square");
	Developpeur* konami = new Developpeur("Konami");
	// On ajoute les jeux respectifs de ListeJeux développé par le développeur
	nintendo->ajouterJeux(lj);
	square->ajouterJeux(lj);
	konami->ajouterJeux(lj);
	// On ajoute les développeurs à la ListeDeveloppeur car ils sont externes
	ld.ajouterDeveloppeur(nintendo);
	ld.ajouterDeveloppeur(square);
	ld.ajouterDeveloppeur(konami);
	// On affiche la liste des développeurs, leurs jeux sont aussi affichés
	ld.afficher();
	// Test avec un développeur bidon
	std::cout << "\n\033[92m"
	"--------------------------Test avec bidon-------------------------"
	"\n\033[0m" << std::endl;
	Developpeur* bidon = new Developpeur("Bidon");
	ld.ajouterDeveloppeur(bidon);
	ld.afficher(); // Cela devrait indiquer que Bidon n'a développé aucun jeu
	std::cout << "\nRetrait de Bidon\n" << std::endl;
	ld.retirerDeveloppeur(bidon); // Bidon est retiré mais non détruit
	ld.afficher(); // Bidon ne devrait pas s'afficher
	std::cout << "\n\033[92m"
	"----------------------Fin test avec bidon--------------------------"
	"\n\033[0m" << std::endl;
	// main() a créé les développeurs, il doit donc les libérer...
	delete nintendo;
	delete square;
	delete konami;
	delete bidon;
	// Cette fonction se charge de détruire les pointeurs sur jeux et designers
	detruireListeJeux(lj);
	// Aucune fuite de mémoire, l'allocation dynamique s'est bien déroulée !
	return 0;
}