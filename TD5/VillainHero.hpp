#pragma once
#include "Hero.hpp"
#include "Villain.hpp"
class VillainHero : public Villain, public Hero
{
	public:
		VillainHero(const Villain&, const Hero&);
		void afficher(ostream&) const override;
	private:
		string mission_;
};
////////////////////////////////////////////////////////////////////////////////
VillainHero::VillainHero(const Villain& v, const Hero& h)
{
	Personnage::setNom(v.getNom() + "-" + h.getNom());
	Personnage::setParutionJeu(v.getParutionJeu() + "-" + h.getParutionJeu());
	mission_ = v.getObjectif() + " dans le monde de " + h.getParutionJeu();
}
void VillainHero::afficher(ostream& os) const
{
	Personnage::afficher(os);
	os << "Et ma mission est de " << mission_ << endl;
}