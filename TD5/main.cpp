#pragma region "Les includes"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "bibliotheque_cours/bibliotheque_cours.hpp"
#include "bibliotheque_cours/debogage_memoire.hpp"
#include "bibliotheque_cours/verification_allocation.hpp"
#include "listeliee.hpp"
#include "Hero.hpp"
#include "Villain.hpp"
#include "VillainHero.hpp"
#pragma endregion

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

Iterateur<Hero> trouverHero(ListeLiee<Hero>& l, std::string nom)
{
	Iterateur<Hero> fin = l.end();
	for(Iterateur<Hero> pos = l.begin(); pos != fin; pos.avancer())
	{
		if((*pos).getNom().compare(nom) == 0)
			return pos;
	}
	return fin;
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
	
	vector<Hero> heros;
	ifstream fh("heros.bin", ios::binary);
	ifstream fv("villains.bin", ios::binary);

	fh.exceptions(ios::failbit);
	fv.exceptions(ios::failbit);

	int nbHeros = lireUint16(fh);
	int nbVillains = lireUint16(fv);

	for(int i = 0; i < nbHeros; i++)
	{
		heros.push_back(Hero(lireString(fh), lireString(fh), lireString(fh)));
		vector<string> allies;
		int nbAllies = lireUint8(fh);
		for(int j = 0; j < nbAllies; j++)
		{
			allies.push_back(lireString(fh));
		}
		heros[i].setAllies(allies);
	}
	//Pour itérer sur la liste avec une boucle sur itérateur, voir la fonction trouverHero()

	//TODO: Transférez les héros du vecteur heros dans la liste liée

	//TODO: Créez un itérateur sur la liste liée à la position du héro Alucard
	// Servez-vous de la fonction trouverHero définie plus haut

	//TODO: Servez-vous de l'itérateur créé précédemment pour trouver l'héroine
	// Aya Brea

	//TODO: Ajouter un hero bidon à la liste après Aya Brea en vous servant de
	// l'itérateur

	//TODO: Reculez votre itérateur jusqu'au héro Mario et effacez-le en utilisant
	// l'itérateur

	//TODO: Affichezvotre liste de héros en utilisant l'itérateur. La liste débute
	//avec le héro Crono. Servez-vous des methodes being et end de la Liste...
	
	//TODO: Utilisez un conteneur pour avoir les héros en ordre alphabétique. 
}