#pragma once
#include <string>
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <memory>
#include <functional>

#include "cppitertools/range.hpp"

using namespace std;

class Jeu
{
	public:
		//TODO: un constructeur par défaut, un constructeur paramétré et un
		// constructeur de copie
		Jeu() = default;
		Jeu(string titre, unsigned int anneeSortie, string developpeur, Liste<Concepteur> concepteurs) : titre_(titre),
			anneeSortie_(anneeSortie),
			developpeur_(developpeur),
			concepteurs_(concepteurs) {};

		Jeu(const Jeu& jeu) : titre_(jeu.titre_),
			anneeSortie_(jeu.anneeSortie_),
			developpeur_(jeu.developpeur_),
			concepteurs_(jeu.concepteurs_){};

		void setTitre(std::string); // Donné
		void setAnneeSortie(unsigned int); // Donné
		void setDeveloppeur(std::string); // Donné
		string getTitre(void); // Donné
		unsigned int getAnneeSortie(void); // Donné
		string getDeveloppeur(void); // Donné

		//TODO: Attribut publique de la liste des concepteurs du jeu
		Liste<Concepteur> concepteurs_;

		//TODO: Votre méthode pour trouver un concepteur selon un critère donné
		// par un lambda, voir ligne 26 du main.cpp
		shared_ptr<Concepteur> trouverConcepteur(const function<bool(shared_ptr<Concepteur>)>& critere) {
			for (unsigned int i = 0; i < concepteurs_.getNbElem(); i++) {
				if (critere(concepteurs_[i])) {
					return concepteurs_[i];
				}
			}
		}
		
	private:
		string titre_; // Donné
		unsigned int anneeSortie_; // Donné
		string developpeur_; // Donné
};

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