#include "Jeu.h"

void Jeu::runJeu() {

	cout << ">>>> INF1015 ROOM EXPLORER 2021 <<<<" << "\n"
		<< ">- - - - - - GOTY EDITION - - - - - -<" << "\n";

	caseAffichage_.afficherEtat();

	while (!caseAffichage_.getEtatJeu()) {
		cin >> entree_;

		if (entree_.compare("look") == 0) {
			caseAffichage_.afficherEtat();
		}
		else {
			switch (entree_[0]) {
			case('O'):
				if (caseAffichage_.getCaseActuelle()->getVoisins(0) == nullptr) {
					cout << "On ne peut pas aller la!" << "\n";
					cout <<"> "<< "\n";
				}
				else { 
					caseAffichage_.setCaseActuelle(0);
					caseAffichage_.afficherEtat();
				}
				break;
			case('N'):
				if (caseAffichage_.getCaseActuelle()->getVoisins(1) == nullptr) {
					cout << "On ne peut pas aller la!" << "\n";
					cout << "> " << "\n";
				}
				else { 
					caseAffichage_.setCaseActuelle(1); 
					caseAffichage_.afficherEtat();
				}
				break;
			case('E'):
				if (caseAffichage_.getCaseActuelle()->getVoisins(2) == nullptr) {
					cout << "On ne peut pas aller la!" << "\n";
					cout << "> " << "\n";
				}
				else { 
					caseAffichage_.setCaseActuelle(2); 
					caseAffichage_.afficherEtat();
				}
				break;
			case('S'):
				if (caseAffichage_.getCaseActuelle()->getVoisins(3) == nullptr) {
					cout << "On ne peut pas aller la!" << "\n";
					cout << "> " << "\n";
				}
				else { 
					caseAffichage_.setCaseActuelle(3); 
					caseAffichage_.afficherEtat();
				}
				break;;
			case('X'):
				caseAffichage_.setEtatJeu(true);
				break;
			default:
				cout << "L'entree est invalide. Veuillez reesseyer." << "\n";
				cout << "> " << "\n";
			}
		}
	}
}
