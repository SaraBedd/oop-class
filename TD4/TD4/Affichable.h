/*****************************************************************************************************
Description:		Fichier contenant l'interface Affichage
Fichier:			Affichable.hpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	02 juin 2021
Date de remise:		08 juin 2021
******************************************************************************************************/
#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Affichable
{
public:
	virtual void afficher(ostream& stream) {};
	virtual void afficherAvecCouleur(ostream& stream, int ansiCodeNumber) {};
};

