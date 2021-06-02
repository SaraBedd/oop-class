/*****************************************************************************************************
Description:		Fichier contenant l'interface et méthodes de la classe Jeu
Fichier:			Jeux.hpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	26 mai 2021
Date de remise:		01 juin 2021
******************************************************************************************************/

#pragma once
#include <string>
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <memory>
#include <functional>

class Jeu
{
	public:
		// Constructeur par défaut
		Jeu();
		// Constructeur paramétré 
		Jeu(std::string titre, unsigned int anneeSortie, std::string developpeur, unsigned int capacite);
		// Constructeur de copie
		Jeu(const Jeu& other);
		
		void setTitre(std::string); // Donné
		void setAnneeSortie(unsigned int); // Donné
		void setDeveloppeur(std::string); // Donné
		std::string getTitre(void); // Donné
		unsigned int getAnneeSortie(void); // Donné
		std::string getDeveloppeur(void); // Donné

		// Attribut publique de la liste des concepteurs du jeu
		Liste<Concepteur> concepteurs_;

		// Méthode pour trouver un concepteur selon un critère donné
		// par un lambda, voir ligne 26 du main.cpp
		shared_ptr<Concepteur> trouverConcepteurLambda(const function<bool(shared_ptr<Concepteur>&)> critere);

	private:
		std::string titre_; // Donné
		unsigned int anneeSortie_; // Donné
		std::string developpeur_; // Donné
};

Jeu::Jeu() {
	titre_ = "";
	anneeSortie_ = 0;
	developpeur_ = "";
	Liste<Concepteur> concepteurs_();
}

Jeu::Jeu(std::string titre, unsigned int anneeSortie, std::string developpeur, unsigned int capacite) {
	titre_ = titre;
	anneeSortie_ = anneeSortie;
	developpeur_ = developpeur;
	Liste<Concepteur> concepteurs_(capacite);
}

Jeu::Jeu(const Jeu& other) {
	titre_ = other.titre_;
	anneeSortie_ = other.anneeSortie_;
	developpeur_ = other.developpeur_;
	concepteurs_ = other.concepteurs_;
}

shared_ptr<Concepteur> Jeu::trouverConcepteurLambda(const function<bool(shared_ptr<Concepteur>&)> critere) {
	for (unsigned int i = 0; i < concepteurs_.getNbElem(); i++) {
		if (critere(concepteurs_[i])) {
			return concepteurs_[i];
		}
	}
	return nullptr;
}

void Jeu::setTitre(std::string titre)
{
	titre_ = titre;
}
void Jeu::setAnneeSortie(unsigned int annee)
{
	anneeSortie_ = annee;
}
void Jeu::setDeveloppeur(std::string developpeur)
{
	developpeur_ = developpeur;
}
std::string Jeu::getTitre(void)
{
	return titre_;
}
unsigned int Jeu::getAnneeSortie(void)
{
	return anneeSortie_;
}
std::string Jeu::getDeveloppeur(void)
{
	return developpeur_;
}