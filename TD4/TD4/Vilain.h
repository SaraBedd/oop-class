/*****************************************************************************************************
Description:		Fichier contenant l'interface et méthodes de la classe Vilain
Fichier:			Vilain.hpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	02 juin 2021
Date de remise:		08 juin 2021
******************************************************************************************************/
#pragma once
#include "Personnage.h"

class Vilain : virtual public Personnage
{
public:
	// Constructeur par default et parametres
	using Personnage::Personnage;
	Vilain(string nom, string titre, string objectif) : Personnage(nom, titre) {
		objectif_ = objectif;
	}

	// Redefinition de la methode afficher
	void afficher(ostream& stream) override {
		Personnage::afficher(stream);
		stream
			<< "Objectif: " << objectif_ << "\n";
	}

	// getter et setter
	string getObjectif() { return objectif_; }
	void setObjectif(string objectif) { objectif_ = objectif; }

private:
	string objectif_;
};

