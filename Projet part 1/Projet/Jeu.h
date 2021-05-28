#pragma once
#include <string>
#include "EtatJeu.h"

using namespace std;

class Jeu
{
public:
	Jeu() = default;
	Jeu(EtatJeu caseActuelle) {
		caseAffichage_= caseActuelle;
	}

	void runJeu();

private:
	string entree_;
	EtatJeu caseAffichage_;
};

