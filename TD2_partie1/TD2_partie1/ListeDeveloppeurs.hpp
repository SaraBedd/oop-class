#pragma once
#include "Developpeur.hpp"
#include "Jeu.hpp"

class ListeDeveloppeurs
{
	public:
		ListeDeveloppeurs(void);
		~ListeDeveloppeurs(void); // Désalloue la mémoire occupée par la liste
		void afficher(void); // Afficher le contenu de la ListeDeveloppeur
		void ajouterDeveloppeur(Developpeur*); // Développeur créé à l'extérieur
		void retirerDeveloppeur(const Developpeur*); // Ne désalloue pas la mémoire
	private:
		unsigned int nElements_;
		unsigned int capacite_;
		Developpeur** liste_;
		gsl::span<Developpeur*> spanListeDeveloppeurs(void); // Pour simplifier
		void doublerTaille(void); // Lorsque on ajoute mais liste pleine
};
