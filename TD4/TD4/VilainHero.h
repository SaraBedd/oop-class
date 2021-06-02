/*****************************************************************************************************
Description:		Fichier contenant l'interface et méthodes de la classe VilainHero
Fichier:			VilainHero.hpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	02 juin 2021
Date de remise:		08 juin 2021
******************************************************************************************************/
#pragma once
#include "Hero.h"
#include "Vilain.h"

class VilainHero : public Hero, public Vilain
{
public:
	// Constructeur par default et parametres
	VilainHero(Hero hero, Vilain vilain) {
		string nom = vilain.getNom() + "-" + hero.getNom();
		string titre = vilain.getTitre() + "-" + hero.getTitre();
		string objectif = vilain.getObjectif() + " dans le monde de " + hero.getTitre();
		vector<string> allies = hero.getAllies();
		
		setNom(nom);
		setTitre(titre);
		setObjectif(objectif);
		setAllies(allies);
	}

	// Redefinition de la methode afficher
	void afficher(ostream& stream) override {
		stream
			<< "Le nom de ce personnage est: " << this->getNom()
			<< "\nLe jeu de parution est: " << this->getTitre()
			<< "\nLa mission est: " << this->getObjectif() << "\n";
	}
};

