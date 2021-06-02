/****************************************************************************************************************************************************************************************
Description:		Fichier contenant les methodes de la partie 1 du TD2
Fichier:			fonctions.hpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	26 mai 2021
Date de remise:		01 juin 2021
****************************************************************************************************************************************************************************************/

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

/*
 * Fonction qui cherche un concepteur par son nom dans une ListeJeux
 * \param	(ListeJeux&)				réfférence vers une structure ListeJeux lj
 *			(string)					nom du concepteur
 * \return	(shared_ptr<Concepteur>)	pointeur vers le concepteur si elle le trouve,
 *							sinon on renvoie un pointeur nul
 **/
std::shared_ptr<Concepteur> chercherConcepteur(Liste<Jeu>& lj, std::string nom)
{
	for (unsigned int i = 0; i < lj.getNbElem(); i++) {
		for (unsigned int j = 0; j < lj[i]->concepteurs_.getNbElem(); j++) {
			if (lj[i]->concepteurs_[j]->getName() == nom) {
				return lj[i]->concepteurs_[j];
			}
		}
	}
	return nullptr;
}

/*
 * Fonction qui lit un concepteur du fichier passé en paramètre et l'ajoute en mémoire
 * s'il n'existe pas déjà.
 * On retourne le pointeur vers ce designer
 * \param	(istream&)					réfférence vers le fichier à lire
 *			(ListeJeux&)				réfférence vers une structure ListeJeux lj
 * \return	(shared_ptr<Concepteur>)	pointeur vers le concepteur 
 **/
std::shared_ptr<Concepteur> lireConcepteur(Liste<Jeu>& lj, std::istream& f)
{
	Concepteur c;
	c.setName(lireString(f));
	c.setAnneeNaissance(lireUint16(f));
	c.setPays(lireString(f));
	
	shared_ptr<Concepteur> concepteurExistant = chercherConcepteur(lj, c.getName());
	if (concepteurExistant != nullptr) {
		return concepteurExistant;
	}
	else {
		cout << "Allocation en memoire du designer " 
			 << "\033[1;92m" << c.getName()
			 << "\033[0m" << " est reussie" << "\n";

		return make_shared<Concepteur>(c.getName(), c.getAnneeNaissance(), c.getPays());
	}
}

/*
 * Fonction qui lit un jeu du fichier passé en paramètre et l'ajoute en mémoire
 * s'il n'existe pas déjà. On retourne le pointeur vers ce jeu
 * \param	(istream&)			réfférence vers le fichier à lire
 *			(ListeJeux&)		réfférence vers une structure ListeJeux lj
 * \return	(shared_ptr<Jeu>)	pointeur vers le jeu
 **/
std::shared_ptr<Jeu> lireJeu(std::istream& f, Liste<Jeu>& lj)
{
	Jeu j;
	j.setTitre(lireString(f));
	j.setAnneeSortie(lireUint16(f));
	j.setDeveloppeur(lireString(f));
	j.concepteurs_.setNbElems(lireUint8(f));
	
	shared_ptr<Jeu> jeu = make_shared<Jeu>(j.getTitre(), j.getAnneeSortie(), j.getDeveloppeur(), j.concepteurs_.getNbElem());
	cout << "\n\033[1;95mAllocation en memoire du jeu " 
		 << j.getTitre() << " est reussie\033[0m\n";

	for (unsigned int i = 0; i < j.concepteurs_.getNbElem(); i++) {
		jeu->concepteurs_.ajouterElement(lireConcepteur(lj, f));
	}
	return jeu;
}

/*
 * Fonction qui cree une struct ListeJeux a partir d'un fichier
 * \param	(string)		nom du fichier
 * \return	(ListeJeux)		structure ListeJeux cree
 **/
Liste<Jeu> creerListeJeux(const std::string nomFichier)
{
	std::ifstream f(nomFichier, std::ios::binary);
	f.exceptions(std::ios::failbit);
	int nElements = lireUint16(f);
	Liste<Jeu> lj(nElements);
	for(unsigned int n : iter::range(nElements))
	{
		lj.setNbElems(n);
		lj.ajouterElement(lireJeu(f, lj));
	}

	lj.setNbElems(nElements);
	return lj;
}