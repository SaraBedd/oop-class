#pragma once
#include "ListeJeux.hpp"
#include "bibliotheque_cours/gsl/span"
#include <string>
#include <utility>
class Developpeur
{
	public:
		Developpeur(std::string);
		~Developpeur(void); // D�salloue la m�moire occup�e par ListeJeux
		const std::string getName(void);
		void ajouterJeux(const ListeJeux&); // Les pointeurs jeux sont dans la Liste
		void afficher(void); // Affiche toute l'info concernant le d�veloppeur
	private:
		std::pair<std::string, ListeJeux> paireNomJeux_;
		gsl::span<Jeu*> spanListeJeux(const ListeJeux&); // Pour simplifier le span
		unsigned int compterJeux(const ListeJeux&); // Pour nb de jeux � ajouter
};
