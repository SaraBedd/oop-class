#pragma once
#include <iostream>
using namespace std;
class Affichable
{
	public:
		virtual void afficher(ostream&) const abstract;
		virtual void changerCouleur(ostream&, int) abstract;
};