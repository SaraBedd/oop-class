#pragma once
#include "Liste.hpp"
#include "Jeu.hpp"
#include "Concepteur.hpp"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#pragma region "Fonctions de lecture"
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
#pragma endregion
//TODO
std::shared_ptr<Concepteur> chercherConcepteur(Liste<Jeu>& lj, std::string nom)
{
	// Servez-vous de fors traditionnels et non de spans. La surcharge [] vous
	// sera utile ici
	for (int i = 0; i < lj.getNbElem(); i++) {
		for (int j = 0; j < lj[i]->concepteurs_.getNbElem(); j++) {
			if ((lj[i]->concepteurs_[j]->getName().compare(nom)) == 0) {
				return lj[i]->concepteurs_[j];
			}
		}
	}
	return nullptr;
}

std::shared_ptr<Concepteur> lireConcepteur(Liste<Jeu>& lj, std::istream& f)
{
	Concepteur c;
	c.setName(lireString(f));
	c.setAnneeNaissance(lireUint16(f));
	c.setPays(lireString(f));
	//TODO
	shared_ptr<Concepteur> concepteurExistant = chercherConcepteur(lj, c.getName());
	if (concepteurExistant != nullptr) {
		return concepteurExistant;
	}
	else {
		std::cout << "\033[92m" << "Allocation en mémoire du designer " << c.getName()
				  << "\033[0m" << std::endl;
		return make_shared<Concepteur>(c);
	}
}

std::shared_ptr<Jeu> lireJeu(std::istream& f, Liste<Jeu>& lj)
{
	Jeu j;
	j.setTitre(lireString(f));
	j.setAnneeSortie(lireUint16(f));
	j.setDeveloppeur(lireString(f));
	j.concepteurs_.setNbElems(lireUint8(f));
	//TODO
	shared_ptr<Jeu> jeu = make_shared<Jeu>(j);
	std::cout << "\033[96m" << "Allocation en mémoire du jeu " << j.getTitre()
			  << "\033[0m" << std::endl;
	for (int i = 0; i < jeu->concepteurs_.getNbElem(); i++) {
		jeu->concepteurs_.ajouterElement(lireConcepteur(lj, f));
	}
	return jeu;
}

Liste<Jeu> creerListeJeux(const std::string nomFichier)
{
	std::ifstream f(nomFichier, std::ios::binary);
	f.exceptions(std::ios::failbit);
	int nElements = lireUint16(f);
	Liste<Jeu> lj(nElements);
	for(unsigned int n : iter::range(nElements))
	{
		//TODO
		lj.setNbElems(n);
		lj.ajouterElement(lireJeu(f, lj));
	}
	//TODO: Ajuster le nombre d'éléments présents dans la liste
	lj.setNbElems(nElements);
	//TODO: Votre retour
	return lj;
}