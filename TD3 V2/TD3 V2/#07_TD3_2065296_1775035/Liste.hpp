/*****************************************************************************************************
Description:		Fichier contenant l'interface et méthodes de la classe Liste
Fichier:			Jeux.hpp
Auteur(s):			Guillaume Renaud, Maya Kurdi-Teylouni ET Sara Beddouch
Date de creation:	26 mai 2021
Date de remise:		01 juin 2021
******************************************************************************************************/

#pragma once
#include <iostream>
#include <memory>
#include "cppitertools/range.hpp"

using namespace std;

template<typename T>
class Liste
{
	public:
		// Constructeur par défaut
		Liste();
		// Constructeur paramétré 
		Liste(unsigned int capacite);
		// Constructeur de copie
		Liste(const Liste<T>& other);

		Liste<T>& operator=(const Liste<T>& other);

		shared_ptr<T>& operator[](int indexe) const;

		// Méthode pour ajouter un élément à la liste
		void ajouterElement(shared_ptr<T> pointeur);

		// Méthode pour doubler la taille de la liste
		void doublerTaille();

		void setNbElems(unsigned int); // Donné
		unsigned int getNbElem(void); // Donné
		unsigned int getCapacite(void); // Donné

private:
	unique_ptr<shared_ptr<T>[]> listeElements_;
	unsigned int nElements_; // Donné
	unsigned int capacite_; // Donné
};

template<typename T>
Liste<T>::Liste() {
	nElements_ = 0;
	capacite_ = 1;
	listeElements_ = make_unique<shared_ptr<T>[]>(capacite_);
}

template<typename T>
Liste<T>::Liste(unsigned int capacite) {
	nElements_ = 0;
	capacite_ = capacite;
	listeElements_ = make_unique<shared_ptr<T>[]>(capacite);
}

template<typename T>
Liste<T>::Liste(const Liste<T>& other) {
	capacite_ = other.capacite_;
	nElements_ = other.nElements_;
	listeElements_ = make_unique<shared_ptr<T>[]>(nElements_);
	for (unsigned int i = 0; i < other.nElements_; i++) {
		listeElements_[i] = move(other.listeElements_[i]);
	}
}

template<typename T>
Liste<T>& Liste<T>::operator=(const Liste<T>& other) {
	if (&other != this) {
		capacite_ = other.capacite_;
		nElements_ = other.nElements_;
		for (unsigned int i = 0; i < other.nElements_; i++) {
			listeElements_[i] = move(other.listeElements_[i]);
		}
	}
	return *this;
}

template<typename T>
shared_ptr<T>& Liste<T>::operator[](int indexe) const {
	return listeElements_[indexe];
}

template<typename T>
void Liste<T>::ajouterElement(shared_ptr<T> pointeur) {
	if (pointeur == nullptr) {
		cout << "pointeur est null" << "\n";
	}
	if (nElements_ >= capacite_) {
		doublerTaille();
	}
	listeElements_[nElements_++] = move(pointeur);
}

template<typename T>
void Liste<T>::doublerTaille() {
	unsigned int nouvelleTaille = 2 * capacite_;
	auto newListe = make_unique<shared_ptr<T>[]>(nouvelleTaille);
	for (unsigned int i = 0; i < nElements_; i++) {
		newListe[i] = listeElements_[i];
	}
	listeElements_ = move(newListe);
	capacite_ = nouvelleTaille;
}

template<typename T>
void Liste<T>::setNbElems(unsigned int n)
{
	nElements_ = n;
}
template<typename T>
unsigned int Liste<T>::getNbElem(void)
{
	return nElements_;
}
template<typename T>
unsigned int Liste<T>::getCapacite(void)
{
	return capacite_;
}
