#pragma once
#include "noeud.hpp"
#include "gsl/gsl_assert"
template<typename T>
class Iterateur
{
	public:
		//TODO: Constructeur paramétré
		void avancer(void)
		{
			Expects(position_ != nullptr);
			//TODO: changez la position de l'itérateur pour le noeud suivant
		}
		void reculer(void)
		{
			Expects(position_ != nullptr);
			//TODO: Changez la position de l'itérateur pour le noeud précédent
		}
		T& operator*()
		{
			return position_->donnee_;
		}
		bool operator==(const Iterateur<T>& it) const = default; 
	private:
		Noeud<T>* position_;
		friend class ListeLiee<T>;
};