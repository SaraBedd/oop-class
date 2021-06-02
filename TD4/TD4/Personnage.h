/*****************************************************************************************************
Description:		Fichier contenant l'interface et méthodes de la classe Personnage
Fichier:			Personnage.hpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	02 juin 2021
Date de remise:		08 juin 2021
******************************************************************************************************/
#pragma once
#include <string>
#include "Affichable.h"

using namespace std;

class Personnage : public Affichable
{
public:
	// Constructeur par default et parametres
	Personnage() = default;
	Personnage(string nom, string titre) {
		nom_ = nom;
		titre_ = titre;
	}

	// Redefinition de la methode afficher
	void afficher(ostream& stream) override {
		stream 
			<< "Nom: " << nom_
			<< "\nParution: " << titre_ << "\n";
	}

	// Redefinition de la methode afficherAvecCouleur
	void afficherAvecCouleur(ostream& stream, int ansiCodeNumber) override {
		string ansiCode = "\033[" + to_string(ansiCodeNumber) + "m";
		stream << ansiCode;
		afficher(stream);
		stream << "\033[0m";
	}

	// getters et setters
	string getNom() { return nom_; }
	string getTitre() { return titre_; }
	void setNom(string nom) { nom_ = nom; }
	void setTitre(string titre) { titre_ = titre; }

private:
	string nom_;
	string titre_;
};

