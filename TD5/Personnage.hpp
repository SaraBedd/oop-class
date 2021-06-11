#pragma once
#include <string>
#include "Affichable.hpp"
using namespace std;
class Personnage : public Affichable
{
	public:
		Personnage(void) = default;
		Personnage(string, string);
		void afficher(ostream&) const override;
		void changerCouleur(ostream&, int);
		void setNom(string);
		void setParutionJeu(string);
		string getNom(void) const;
		string getParutionJeu(void) const;
	protected:
		string nom_;
		string parutionJeu_;
};
////////////////////////////////////////////////////////////////////////////////
Personnage::Personnage(string nom, string parutionJeu)
{
	nom_ =  nom;
	parutionJeu_ = parutionJeu;
}
void Personnage::afficher(ostream& os) const
{
	os << "Nom : " << nom_ << "\n";
	os << "Jeu de parution : " << parutionJeu_ << endl;
}
void Personnage::changerCouleur(ostream& os, int c)
{
	switch(c)
	{
		case 1: os << "\033[91m"; break;
		case 2: os << "\033[92m"; break;
		case 3: os << "\033[94m"; break;
		default: os << "\033[0m"; break;
	}
}
void Personnage::setNom(string nom)
{
	nom_ = nom;
}
void Personnage::setParutionJeu(string parutionJeu)
{
	parutionJeu_ = parutionJeu;
}
string Personnage::getNom(void) const
{
	return nom_;
}
string Personnage::getParutionJeu(void) const
{
	return parutionJeu_;
}