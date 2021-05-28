#pragma once
#include <string>
#include "Liste.hpp"
#include <memory>
class Jeu; // Pour éviter un include circulaire
class Concepteur
{
	public:
		//TODO: un constructeur par défaut, un constructeur paramétré et un
		// constructeur de copie
		Concepteur() = default;
		Concepteur(string nom, unsigned int anneeNaissance, string pays) : nom_(nom),
			anneeNaissance_(anneeNaissance),
			pays_(pays) {};
		Concepteur(const Concepteur& concepteur) : nom_(concepteur.nom_),
			anneeNaissance_(concepteur.anneeNaissance_),
			pays_(concepteur.pays_) {};


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