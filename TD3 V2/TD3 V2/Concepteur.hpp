/*****************************************************************************************************
Description:		Fichier contenant l'interface et méthodes de la classe Concepteur
Fichier:			Concepteur.hpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	26 mai 2021
Date de remise:		01 juin 2021
******************************************************************************************************/

#pragma once
#include <string>
#include "Liste.hpp"
#include <memory>

class Jeu; // Pour éviter un include circulaire
class Concepteur
{
	public:
		// Constructeur par défaut
		Concepteur();
		// Constructeur paramétré 
		Concepteur(std::string nom, unsigned int anneeNaissance, std::string pays);
		// Constructeur de copie
		Concepteur(const Concepteur& other);

		void setName(std::string); // Donné
		void setAnneeNaissance(unsigned int); // Donné
		void setPays(std::string); // Donné
		std::string getName(void); // Donné
		unsigned int getAnneeNaissance(void); // Donné
		std::string getPays(void); // Donné

	private:
		std::string nom_; // Donné
		unsigned int anneeNaissance_; // Donné
		std::string pays_; // Donné
};

Concepteur::Concepteur() {
	nom_ = "";
	anneeNaissance_ = 0;
	pays_ = "";
}

Concepteur::Concepteur(std::string nom, unsigned int anneeNaissance, std::string pays) {
	nom_ = nom;
	anneeNaissance_ = anneeNaissance;
	pays_ = pays;
}

Concepteur::Concepteur(const Concepteur& other) {
	nom_ = other.nom_;
	anneeNaissance_ = other.anneeNaissance_;
	pays_ = other.pays_;
}

void Concepteur::setName(std::string nom)
{
	nom_ = nom;
}

void Concepteur::setAnneeNaissance(unsigned int annee)
{
	anneeNaissance_ = annee;
}

void Concepteur::setPays(std::string pays)
{
	pays_ = pays;
}
std::string Concepteur::getName(void)
{
	return nom_;
}
unsigned int Concepteur::getAnneeNaissance(void)
{
	return anneeNaissance_;
}
std::string Concepteur::getPays(void)
{
	return pays_;
}