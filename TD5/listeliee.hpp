#pragma once
#include "iterateur.hpp"
template<typename T> class Iterateur;
template<typename T>
class ListeLiee
{
	public:
	//TODO: Constructeur sans paramètre
	~ListeLiee(void)
	{
		//TODO: Vous devez vérifier si la liste est vide pour commencer
		//TODO: Une fois la vérification faite, vous devez commencer au début
		// de la liste et parcourir chaque noeud successivement.
		// 1. mémoriser le noeud suivant la tête de la liste
		// 2. deletez la tête
		// 3. réassignez le noeud suivant mémorisé en 1. à la tête
		// 4. décrémentez la taille de la liste
		// 5. recommencez tant que la liste n'est pas vide
	}
	void push_front(const T& item)
	{
		//TODO: Vous devez créer un nouveau noeud en mémoire avec un new 
		//TODO: Ensuite vérifiez si la liste est vide
		// Dans le cas d'une liste vide, la tête et la queue de la liste
		// pointent tous les deux sur ce nouveau noeud créé
		// Autrement, ajustez la tête de la liste en conséquence
	void push_back(const T& item)
	{
		//TODO: Vous devez créer un nouveau noeud en mémoire avec un new 
		//TODO: Ensuite vérifiez si la liste est vide
		// Dans le cas d'une liste vide, la tête et la queue de la liste
		// pointent tous les deux sur ce nouveau noeud créé
		// Autrement, ajustez la queue de la liste en conséquence
	}
	bool estVide(void)
	{
		return taille_ == 0;
	}
	Iterateur<T> begin(void)
	{
		return Iterateur<T>(tete_);
	}
	Iterateur<T> end(void)
	{
		return Iterateur<T>(queue_->suivant_);
	}
	Iterateur<T> insert_after(Iterateur<T> it, const T& item)
	{
		//TODO: Pour commencer, vérifiez si l'itérateur est déjà à la queue
		// Si c'est le cas, faites simplement appel à push_back en lui donnant
		// l'item comme paramètre et retournez un nouvel itérateur initialisé
		// à la queue de la liste
		// Autrement, procédez comme suit
		// 1. Créez un nouveau noeud initialisé avec item
		// 2. Modifiez les attributs suivant_ et precedent_ du nouveau noeud
		//    afin que le nouveau noeud soit lié au noeud précédent et suivant
		//    à l'endroit où il est insérer selon notre itérateur
		// 3. Modifiez l'attribut precedent_ du noeud suivant_ de la position
		//    de l'itérateur afin qu'il pointe vers le noeud créé
		// 4. Modifiez l'attribut suivant_ de la position de l'itérateur afin
		//    qu'il point vers le noeud créé
		// 5. Incrémentez la taille de la liste
		// 6. Retournez un nouvel itérateur initialisé au nouveau noeud
	}
	Iterateur<T> erase_after(Iterateur<T> it)
	{
		//TODO: Vous devez vérifier si la liste est vide pour commencer
		//TODO: Ensuite, vérifiez si l'itérateur est placé à la queue de la liste
		// Si placé à la queue de la liste:
		//  1. Initialisez une variable de type pointeur de Noeud à la position
		//     de l'itérateur. Attention, il n'y a pas création de pointeur ici!
		//  2. Reculez votre itérateur
		//  3. Modifiez l'attibut suivant_ du noeud sur lequel se trouve l'itérateur
		//     afin que cela pointe vers le néant (nullptr)
		//  4. Modifiez la queue de la liste afin qu'elle pointe à la position
		//     actuelle de votre itérateur
		//  5. Deletez la variable de type pointeur en 1.
		//  6. Décrémentez la taille de la liste
		//  7. Retournez un nouvel itérateur à la position actuel de l'itérateur en cours
		// Autrement:
		//  1. Avancez votre itérateur (il va pointer sur le noeud à effacer)
		//  2. Initialisez une variable de type pointeur de Noeud à la position
		//     de l'itérateur. Attention, il n'y a pas création de pointeur ici!
		//  3. Modifiez l'attribut suivant_ du noeud précédent pour que celui-ci
		//     pointe vers le noeud suivant la position de l'itérateur (voir 1.)
		//  4. Modifiez l'attribut precedent_ du noeud suivant la position de
		//     l'itérateur pour que celui-ci pointe vers le noeud précédent
		//     de la position de l'itérateur (voir 1.)
		//  5. Reculez votre itérateur
		//  6. Deletez la variable de type pointeur en 2.
		//  7. Décrémentez la taille de la liste
		//  8. Retournez un nouvel itérateur à la position actuel de l'itérateur en cours
		// Si la taille de la liste est déjà de zéro, lancez une std::exception
	}
	private:
		Noeud<T>* tete_;
		Noeud<T>* queue_;
		unsigned int taille_;
		friend class Iterateur<T>;	
};
