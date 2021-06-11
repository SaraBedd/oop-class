#pragma once
#include "Personnage.hpp"
class Villain : public virtual Personnage
{
	public:
		Villain(void) = default;
		Villain(string, string, string);
		void afficher(ostream&) const override;
		void setObjectif(string);
		string getObjectif(void) const;
	private:
		std::string objectif_;
};
////////////////////////////////////////////////////////////////////////////////
Villain::Villain(string objectif, string jeu, string nom) : Personnage(nom, jeu)
{
	objectif_ = objectif;
}
void Villain::afficher(ostream& os) const
{
	Personnage::afficher(os);
	os << "Type : Villain\n";
	os << "Objectif : " << objectif_ << "\n";
}
void Villain::setObjectif(string objectif)
{
	objectif_ = objectif;
}
string Villain::getObjectif(void) const
{
	return objectif_;
}