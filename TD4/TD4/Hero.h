/*****************************************************************************************************
Description:		Fichier contenant l'interface et méthodes de la classe Hero
Fichier:			Hero.hpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	02 juin 2021
Date de remise:		08 juin 2021
******************************************************************************************************/
#pragma once
#include <vector>
#include "Personnage.h"

class Hero : virtual public Personnage
{
public:
	// Constructeur par default et parametres
	using Personnage::Personnage;
	Hero(string nom, string titre, string ennemi, vector<string> allies): Personnage(nom, titre) {
		ennemi_ = ennemi;
		allies_ = allies;
	}

	// Redefinition de la methode afficher
	void afficher(ostream& stream) override {
		Personnage::afficher(stream);
		stream
			<< "Ennemi: " << ennemi_
			<< "\nAllies: " << allies_[0] << "\n";
		for (int i = 1; i < allies_.size(); i++) {
			stream << "\t" << allies_[i] << "\n";
		}
	}

	// getters et setters
	string getEnnemi() { return ennemi_; }
	vector<string> getAllies() { return allies_; }
	void setEnnemi(string ennemi) { ennemi_ = ennemi; }
	void setAllies(vector<string> allies) { allies_ = allies; }

private:
	string ennemi_;
	vector<string> allies_;
};

