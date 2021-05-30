#include <iostream>
#include "cppitertools/range.hpp"
#include "ListeDeveloppeurs.hpp"

ListeDeveloppeurs::ListeDeveloppeurs(void)
{
	nElements_ = 0;
	capacite_ = 1;
	liste_ = new Developpeur*[1];
}

ListeDeveloppeurs::~ListeDeveloppeurs(void)
{
	delete[] liste_;
}

void ListeDeveloppeurs::afficher(void)
{
	for(Developpeur* const d : spanListeDeveloppeurs())
	{
		d->afficher();
	}
}

void ListeDeveloppeurs::ajouterDeveloppeur(Developpeur* d)
{
	if(nElements_ == capacite_)
		doublerTaille();
	liste_[nElements_++] = d;
}

void ListeDeveloppeurs::retirerDeveloppeur(const Developpeur* aRetirer)
{
	for(Developpeur*& d : spanListeDeveloppeurs())
	{
		if(d == aRetirer)
		{
			if(nElements_ > 1)
			{
				d = liste_[nElements_ - 1];
			}
			nElements_--;
		}
	}
}


gsl::span<Developpeur*> ListeDeveloppeurs::spanListeDeveloppeurs(void)
{
	return gsl::span(liste_, (int)nElements_);
}

void ListeDeveloppeurs::doublerTaille(void)
{
	Developpeur** nouvelleListe = new Developpeur*[capacite_ * 2];
	if(liste_ != nullptr)
	{
		for(int i : iter::range(nElements_))
		{
			nouvelleListe[i] = liste_[i];
		}
		delete[] liste_;
	}
	liste_ = nouvelleListe;
	capacite_ *= 2;
}