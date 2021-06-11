#pragma once
#include "Personnage.hpp"
#include <vector>
class Hero : public virtual Personnage
{
	public:
		Hero(void) = default;
		Hero(string, string, string);
		void afficher(ostream&) const override;
		void setEnnemi(string);
		void setAllies(const vector<string>&);
		string getEnnemi(void);
		vector<string> getAllies(void);
	private:
		string ennemi_;
		vector<string> allies_;
};
////////////////////////////////////////////////////////////////////////////////
Hero::Hero(string ennemi, string jeu, string nom): Personnage(nom, jeu)
{
	ennemi_ = ennemi;
}
void Hero::afficher(ostream& os) const
{
	Personnage::afficher(os);
	os << "Type : Héro\n";
	os << "Ennemi : " << ennemi_ << "\n";
	os << "Companions :\n";
	for(string str : allies_)
	{
		os << "\t" << str << "\n";
	}
}
void Hero::setEnnemi(string ennemi)
{
	ennemi_ = ennemi;
}
void Hero::setAllies(const vector<string>& companions)
{
	for(string str : companions)
	{
		allies_.push_back(str);
	}
}
string Hero::getEnnemi(void)
{
	return ennemi_;
}
vector<string> Hero::getAllies(void)
{
	return allies_;
}