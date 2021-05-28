#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "cppitertools/range.hpp"

using namespace std;

template<typename T>
class Liste
{
	public:
		//TODO: Constructeurs et surcharges d'opérateurs
		Liste() = default;
		Liste(const Liste& other);	// Constructeur
		Liste(unsigned int size) {
			nElements_ = size;
			capacite_ = size;
		};
		shared_ptr<T>& operator[](int index);
		const shared_ptr<T>& operator[](int index) const;
		Liste& operator=(const Liste& other);

		//TODO: Méthode pour ajouter un élément à la liste
		void ajouterElement(shared_ptr<T> element);

		void setNbElems(unsigned int);	// Donné
		unsigned int getNbElem(void);	// Donné
		unsigned int getCapacite(void); // Donné

		//TODO: Méthode pour doubler la taille de la liste
		void doublerTaille(unsigned int nouvelleTaille);

	private:
		unique_ptr<shared_ptr<T>[]> listeElements_;	//TODO: attribut contenant les éléments de la liste
		unsigned int nElements_;		// Donné
		unsigned int capacite_;			// Donné

};
template<typename T>
Liste<T>::Liste(const Liste<T>& other) {
	*this = other;
}

template<typename T>
shared_ptr<T>& Liste<T>::operator[](int index) {
	return listeElements_[index];
}

template<typename T>
const shared_ptr<T>& Liste<T>::operator[](int index) const {
	return listeElements_[index];
}

template<typename T>
Liste<T>& Liste<T>::operator=(const Liste<T>& other) {
	if (&other == this) {
		return *this;
	}
	capacite_ = other.capacite_;
	nElements_ = other.nElements_;
	for (int i = 0; i < other.nElements_; i++) {
		listeElements_[i] = other.listeElements_[i];
	}
	return *this;
}

template<typename T>
void Liste<T>::ajouterElement(shared_ptr<T> element) {
	if (nElements_ == capacite_) {
		doublerTaille(capacite_ * 2);
	}
	nElements_++;
	listeElements_[nElements_];
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

template<typename T>
void Liste<T>::doublerTaille(unsigned int nouvelleTaille) {
	auto&& old = move(listeElements_);
	listeElements_.reset();
	listeElements_ = make_unique<shared_ptr<T>[]>(nouvelleTaille);
	listeElements_ = move(old);
	capacite_ = nouvelleTaille;
}
