#pragma once
#include "Developpeur.hpp"
#include "Jeu.hpp"

class ListeDeveloppeurs
{
	public:
		ListeDeveloppeurs(void);
		~ListeDeveloppeurs(void); // D�salloue la m�moire occup�e par la liste
		void afficher(void); // Afficher le contenu de la ListeDeveloppeur
		void ajouterDeveloppeur(Developpeur*); // D�veloppeur cr�� � l'ext�rieur
		void retirerDeveloppeur(const Developpeur*); // Ne d�salloue pas la m�moire
	private:
		unsigned int nElements_;
		unsigned int capacite_;
		Developpeur** liste_;
		gsl::span<Developpeur*> spanListeDeveloppeurs(void); // Pour simplifier
		void doublerTaille(void); // Lorsque on ajoute mais liste pleine
};
