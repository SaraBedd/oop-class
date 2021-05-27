#pragma once
#include"Case.h"
#include "Carte.h"

string const CASEDEPART = "Hall d'entree";

class EtatJeu {
public:

	EtatJeu() = default;
	EtatJeu(Carte carte, string caseDepart = CASEDEPART) {
		carte_ = carte;
		caseActuelle_ = make_shared<Case>(*carte.rechercherCase(CASEDEPART).get());
	}

	shared_ptr<Case> getCaseActuelle();

	void setCaseActuelle(shared_ptr<Case> caseActuelle);

	bool setCaseActuelle(int direction);

	bool getEtatJeu();

	void setEtatJeu(bool etatJeu);

	void afficherEtat();

private:
	Carte carte_;
	shared_ptr<Case> caseActuelle_;
	bool gameOver_ = false;

};