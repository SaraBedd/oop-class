/*****************************************************************************************************
Description:		Fichier contenant la fonction principale du TD4
Fichier:			main.cpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	02 juin 2021
Date de remise:		08 juin 2021
******************************************************************************************************/
#include <fstream>
#include <vector>
#include "bibliotheque_cours/bibliotheque_cours.hpp"

#include "Affichable.h"
#include "Personnage.h"
#include "Hero.h"
#include "Vilain.h"
#include "VilainHero.h"

using namespace std;

typedef uint8_t UInt8;
typedef uint16_t UInt16;
UInt8 lireUint8(std::istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
UInt16 lireUint16(std::istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
std::string lireString(std::istream& fichier)
{
	std::string texte;
	texte.resize(lireUint16(fichier));
	fichier.read((char*)&texte[0], std::streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}

int main(void)
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

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fh("heros.bin", ios::binary);
	ifstream fv("vilains.bin", ios::binary);
	fh.exceptions(ios::failbit);
	fv.exceptions(ios::failbit);

	vector<Hero> heros;
	vector<Vilain> vilains;
	vector<Personnage> personnages;

	// Lecture et ajout des heros dans le vecteur "heros"
	int nHeros = lireUint16(fh);
	for (int i = 0; i < nHeros; i++) {
		string nom = lireString(fh);
		string titre = lireString(fh);
		string ennemi = lireString(fh);
		int nAllie = lireUint8(fh);
		vector<string> allies;
		for (int j = 0; j < nAllie; j++) {
			allies.push_back(lireString(fh));
		}
		Hero heroLu(nom, titre, ennemi, allies);
		heros.push_back(heroLu);
	}

	// Lecture et ajout des vilains dans le vecteur "vilains"
	int nVillain = lireUint16(fv);
	for (int i = 0; i < nVillain; i++) {
		string nom = lireString(fv);
		string titre = lireString(fv);
		string objectif = lireString(fv);
		Vilain vilainLu(nom, titre, objectif);
		vilains.push_back(vilainLu);
	}

	// Affichage des heros
	cout << "\033[95m===================================================================================================\n"
		 << "Affichage des heros\n"
		 << "===================================================================================================\033[0m\n\n";
	for (int i = 0; i < heros.size(); i++) {
		heros[i].afficherAvecCouleur(cout, 96);
		cout << "\n\033[95m- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\033[0m" << "\n\n";
	}


	// Affichage des vilains
	cout << "\033[95m\n===================================================================================================\n"
		 << "Affichage des vilains\n"
		 << "===================================================================================================\033[0m\n\n";
	for (int i = 0; i < vilains.size(); i++) {
		vilains[i].afficherAvecCouleur(cout, 93);
		cout << "\n\033[95m- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\033[0m" << "\n\n";
	}

	// Ajout des heros, puis des vilains dans le vecteur "personnage"
	for (int i = 0; i < heros.size(); i++) {
		personnages.push_back(heros[i]);
	}
	for (int i = 0; i < vilains.size(); i++) {
		personnages.push_back(vilains[i]);
	}

	// Affichage des personnages
	cout << "\033[95m\n===================================================================================================\n"
		 << "Affichage des personnages\n"
		 << "===================================================================================================\033[0m\n\n";
	for (int i = 0; i < personnages.size(); i++) {
		personnages[i].afficher(cout);
		cout << "\n\033[95m- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\033[0m" << "\n\n";
	}
	
	// Affichage du vilain-hero (vilain => King Koopa/Bowser & hero => Link)
	cout << "\033[95m\n===================================================================================================\n"
		<< "Affichage du Vilain-Hero\n"
		<< "===================================================================================================\033[0m\n\n";
	VilainHero vilainHero(heros[3], vilains[4]);
	vilainHero.afficherAvecCouleur(cout, 94);

	// Ajout du vilain-hero dans le vecteur "personnage"
	personnages.push_back(vilainHero);

	return 0;
}
