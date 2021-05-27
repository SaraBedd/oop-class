#include "EtatJeu.h"

shared_ptr<Case> EtatJeu::getCaseActuelle() {
	return caseActuelle_;
}

void EtatJeu::setCaseActuelle(shared_ptr<Case> caseActuelle) {
	caseActuelle_ = caseActuelle;
}

bool EtatJeu::setCaseActuelle(int direction) {
	if (caseActuelle_->getVoisins(direction) != nullptr) {
		caseActuelle_ = carte_.rechercherCase(caseActuelle_->getVoisins(direction)->getName());
		return true;
	}
	return false;
}

bool EtatJeu::getEtatJeu() {
	return gameOver_;
}

void EtatJeu::setEtatJeu(bool etatJeu) {
	gameOver_ = etatJeu;
}

void EtatJeu::afficherEtat() {
	cout << "---" << caseActuelle_->getName() << "---" << "\n";
	cout << caseActuelle_->getDescription() << "\n";
	for (int i = 0; i < CARDINAL; i++) {
		if (caseActuelle_->getVoisins(i) != nullptr) {
			caseActuelle_->afficherVoisin(i);
			cout << "\n";
		}
	}
	cout << "> ";
}