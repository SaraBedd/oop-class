#pragma once
#include <iostream>
#include <memory>
#include "cppitertools/range.hpp"

using namespace std;

template<typename T>
class Liste
{
	public:
		//TODO: Constructeurs et surcharges d'opérateurs
		Liste() {
			nElements_ = 0;
			capacite_ = 1;
			listeElements_ = make_unique<shared_ptr<T>[]>(capacite_);
		}

		Liste(unsigned int capacite) {
			nElements_ = 0;
			capacite_ = capacite;
			listeElements_ = make_unique<shared_ptr<T>[]>(capacite);
			std::cout << "Liste(capacite)" << "\n";
		}

		Liste(const Liste<T>& other){
			capacite_ = other.capacite_;
			nElements_ = other.nElements_;
			listeElements_ = make_unique<shared_ptr<T>[]>(nElements_);
			for (int i = 0; i < other.nElements_; i++) {
				listeElements_[i] = move(other.listeElements_[i]);
			}
		}

		Liste<T>& operator=(const Liste<T>& other) {
			if (&other != this) {
				capacite_ = other.capacite_;
				nElements_ = other.nElements_;
				for (int i = 0; i < other.nElements_; i++) {
					listeElements_[i] = move(other.listeElements_[i]);
				}
			}
			return *this;
		}

		shared_ptr<T>& operator[](int indexe) const{
			return listeElements_[indexe];
		}

		//TODO: Méthode pour ajouter un élément à la liste
		void ajouterElement(shared_ptr<T> pointeur) {
			if (pointeur == nullptr) {
				cout << "pointeur est null" << "\n";
			}
			if (nElements_ >= capacite_) {
				doublerTaille();
			}
			listeElements_[nElements_++] = move(pointeur);
		}

		//TODO: Méthode pour doubler la taille de la liste
		void doublerTaille() {
			unsigned int nouvelleTaille = 2 * capacite_;
			auto newListe = make_unique<shared_ptr<T>[]>(nouvelleTaille);
			for (int i = 0; i < nElements_; i++) {
				newListe[i] = listeElements_[i];
			}
			listeElements_ = move(newListe);
			capacite_ = nouvelleTaille;
		}

		void setNbElems(unsigned int); // Donné
		unsigned int getNbElem(void); // Donné
		unsigned int getCapacite(void); // Donné

private:
	//TODO: attribut contenant les éléments de la liste
	unique_ptr<shared_ptr<T>[]> listeElements_;
	unsigned int nElements_; // Donné
	unsigned int capacite_; // Donné
};

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
