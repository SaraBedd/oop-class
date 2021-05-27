#pragma once
#include<iostream>
#include<memory>
#include <vector>
#include<iterator>

#include "Case.h"

using namespace std;

class Carte
{
public:
	Carte() = default;

	Carte(string fichier);

	shared_ptr<Case> rechercherCase(string nom);

	void creerCarte(string fichier);

	vector<shared_ptr<Case>> getCarte() const;

	vector<shared_ptr<Case>> getCarte();

private:
	vector<shared_ptr<Case>> carte_;
};

