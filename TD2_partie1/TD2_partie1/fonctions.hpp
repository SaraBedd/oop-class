#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma region "Les "includes" vont ici"
#include <iostream>
#include "cppitertools/range.hpp"
#include "Jeu.hpp"
#pragma endregion
#pragma region "Fonctions de base pour vous aider"
#include <fstream>
#include "gsl/span"
using namespace std;
typedef uint8_t UInt8;
typedef uint16_t UInt16;
UInt8 lireUint8(std::istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
UInt16 lireUint16(std::istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}
std::string lireString(std::istream& fichier)
{
	std::string texte;
	texte.resize(lireUint16(fichier));
	fichier.read((char*)&texte[0], std::streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
gsl::span<Jeu*> spanListeJeux(const ListeJeux& lj)
{
	return gsl::span(lj.elements, lj.nElements);
}
gsl::span<Designer*> spanListeDesigners(const ListeDesigners& ld)
{
	return gsl::span(ld.elements, ld.nElements);
}
#pragma endregion

//TODO: Fonction qui cherche un designer par son nom dans une ListeJeux
// Cette fonction renvoie le pointeur vers le designer si elle le trouve dans
// un des jeux de la ListeJeux. En cas contraire, elle renvoie un pointeur nul.
Designer* rechercherDesigner(const ListeJeux& lj, string nom) {
	for (Jeu* j : spanListeJeux(lj)) {
		for (Designer* d : spanListeDesigners(j->designers)) {
			if (d->nom.compare(nom) == 0) {
				return d;
			}
		}
	}
	return nullptr;
}

Designer* lireDesigner(std::istream& f, const ListeJeux& lj)
{
	Designer d = {}; // On initialise une structure vide de type Designer
	d.nom = lireString(f);
	d.anneeNaissance = lireUint16(f);
	d.pays = lireString(f);
	// Rendu ici, les champs pr�c�dents de la structure designer sont remplis
	// avec la bonne information

	//TODO: Ajouter en m�moire le designer lu. Il faut revoyer le pointeur cr��
	// Attention, valider si le designer existe d�j� avant de le cr�er, sinon
	// on va avoir des doublons car plusieurs jeux ont des designers en commun
	// dans le fichier binaire. Afficher un message lorsque l'allocation du
	// designer est r�ussie
	if (rechercherDesigner(lj, d.nom) == nullptr) {
		Designer* designerLu = new Designer(d);
		cout << "Allocation en memoire du designer " << "\033[1;32m" << designerLu->nom << "\033[0m" << " est reussie" << "\n";
		return designerLu;
	}
	else {
		return rechercherDesigner(lj, d.nom);

	}
}

//TODO: Fonction qui double le tableau de jeux de ListeJeux
// Cette fonction doit recevoir en param�tre la nouvelle capacit� du nouveau
// tableau. Il faut allouer un nouveau tableau plus grand, copier ce qu'il y
// avait dans l'ancien, et �liminer l'ancien trop petit. N'oubliez pas, on copie
// des pointeurs de jeux. Il n'y a donc aucune nouvelle allocation ici !
void doublerTaille(unsigned int nouvelleTaille, ListeJeux& lj) {
	Jeu** tableauDouble = new Jeu * [nouvelleTaille] {};
	for (int n : iter::range(lj.nElements)) {
		tableauDouble[n] = lj.elements[n];
	}
	delete[] lj.elements;
	lj.capacite = nouvelleTaille;
	lj.elements = tableauDouble;
}

//TODO: Fonction pour ajouter un Jeu � ListeJeux
// Le jeu existant d�j� en m�moire, on veut uniquement ajouter le pointeur vers
// le jeu existant. De plus, en cas de saturation du tableau elements, cette
// fonction doit doubler la taille du tableau elements de ListeJeux et d�truire
// l'ancien. Utilisez la fonction de doublement �crite plus haut.
void ajouterJeu(Jeu* j, ListeJeux& lj) {
	if (lj.nElements == lj.capacite) {
		doublerTaille(max((unsigned int)1, lj.capacite * 2), lj);
	}
	lj.elements[lj.nElements] = j;
	lj.nElements++;
}

Jeu* lireJeu(std::istream& f, ListeJeux& lj)
{
	Jeu j = {}; // On initialise une structure vide de type Jeu
	j.titre = lireString(f);
	j.anneeSortie = lireUint16(f);
	j.developpeur = lireString(f);
	j.designers.nElements = lireUint8(f);
	// Rendu ici, les champs pr�c�dents de la structure jeu sont remplis avec la
	// bonne information

	//TODO: Ajouter en m�moire le jeu lu. Il faut revoyer le pointeur cr��
	// Attention, il faut aussi cr�er un tableau dynamique pour les designers
	// que contient un jeu. Servez-vous de votre fonction d'ajout de jeu car la
	// liste de jeux particip� est une ListeJeu. Afficher un message lorsque
	// l'allocation du jeu est r�ussie
	Jeu* jeuLu = new Jeu(j);
	cout << "\n" << "\033[1;32mAllocation en memoire du jeu " << jeuLu->titre << " est reussie\033[0m\n";
	// cout << "Allocation en memoire du jeu " << jeuLu->titre << " est reussie" << "\n";
	jeuLu->designers.elements = new Designer * [j.designers.nElements]{};
	for (int n : iter::range(jeuLu->designers.nElements)) {
		jeuLu->designers.elements[n] = lireDesigner(f, lj);
		ajouterJeu(jeuLu, jeuLu->designers.elements[n]->listeJeuxParticipes);
	}
	return jeuLu;
}

ListeJeux creerListeJeux(const std::string nomFichier)
{
	std::ifstream f(nomFichier, std::ios::binary);
	f.exceptions(std::ios::failbit);
	int nElements = lireUint16(f);
	ListeJeux lj = {};

	for (int n : iter::range(nElements))
	{
		lj.nElements = n;
		//TODO: Ajouter un jeu � ListeJeux
		ajouterJeu(lireJeu(f, lj), lj);
	}
	lj.nElements = nElements;
	//TODO: Renvoyez la ListeJeux
	return lj;
}

//TODO: Fonction qui d�termine si un designer participe encore � un jeu OK
bool designerParticipe(Designer* designer) {
	return designer->listeJeuxParticipes.nElements > 0;
}

//TODO: Fonction pour d�truire un designer (lib�ration de m�moire allou�e)
// Lorsqu'on d�truit un designer, on affiche son nom pour fins de d�bogage
void detruireDesigner(Designer* designer) {
	cout << "Le designer  " << "\033[1;31m" << designer->nom << "\033[0m" << " est supprime avec succes" << "\n";
	delete[] designer->listeJeuxParticipes.elements;
	delete designer;
}

//TODO: Fonction qui enl�ve un jeu de ListeJeux
// Attention, ici il n'a pas de d�sallocation de m�moire. Elle enl�ve le
// pointeur de la ListeJeux, mais le jeu point� existe encore en m�moire.
// Puisque l'ordre de la ListeJeux n'a pas �tre conserv�, on peut remplacer le
// jeu � �tre retir� par celui pr�sent en fin de liste et d�cr�menter la taille
// de celle-ci 
void enleverJeu(ListeJeux& lj, Jeu* jeu) {
	for (Jeu*& j : spanListeJeux(lj)) {
		if (j == jeu) {
			if (lj.nElements > 1) {
				j = lj.elements[lj.nElements - 1];
			}
			lj.nElements--;
		}
	}
}

//TODO: Fonction pour d�truire un jeu (lib�ration de m�moire allou�e)
// Attention, ici il faut rel�cher toute les cases m�moires occup�es par un jeu.
// Par cons�quent, il va falloir g�rer le cas des designers (un jeu contenant
// une ListeDesigners). On doit commencer par enlever le jeu � d�truire des jeux
// qu'un designer a particip� (listeJeuxParticipes). Si le designer n'a plus de
// jeux pr�sents dans sa liste de jeux particip�s, il faut le supprimer.  Pour
// fins de d�bogage, affichez le nom du jeu lors de sa destruction. OK
void detruireJeu(ListeJeux& lj, Jeu* jeu) {
	for (Designer* d : spanListeDesigners(jeu->designers)) {
		enleverJeu(d->listeJeuxParticipes, jeu);
		if (!designerParticipe(d)) {
			detruireDesigner(d);
		}
	}
	cout << "\033[1;31mLe jeu " << jeu->titre << " est supprime avec succes\033[0m\n\n";
	// cout << "Le jeu " << jeu->titre << " est supprime avec succes" << "\n";
	delete[] jeu->designers.elements;
	delete jeu;
}

//TODO: Fonction pour d�truire une ListeJeux et tous ses jeux OK
void detruireListeJeu(ListeJeux& lj) {
	for (Jeu* j : spanListeJeux(lj)) {
		detruireJeu(lj, j);
	}
	delete[] lj.elements;
}

void afficherDesigner(const Designer& d)
{
	std::cout << "\t" << d.nom << ", " << d.anneeNaissance << ", " << d.pays
		<< std::endl;
}

//TODO: Fonction pour afficher les infos d'un jeu ainsi que ses designers
// Servez-vous de la fonction afficherDesigner ci-dessus
void afficherJeu(const Jeu& j) {
	cout << "Titre: " << j.titre << "\n";
	cout << "Annee de sortie: " << j.anneeSortie << "\n";
	cout << "Developpe par: " << j.developpeur << "\n";
	cout << "Designers du jeu " << "\n";
	for (int n : iter::range(j.designers.nElements)) {
		afficherDesigner(*(j.designers.elements[n]));
	}
}

//TODO: Fonction pour afficher tous les jeux de ListeJeux, s�par�s par un ligne
// Servez-vous de la fonction d'affichage d'un jeu cr�e ci-dessus. Votre ligne
// de s�paration doit �tre diff�rent de celle utilis�e dans le main
// /utf-8 
void afficherListeJeu(const ListeJeux& lj) {
	for (int n : iter::range(lj.nElements)) {
		cout << "-----------------------------------------------------" << "\n";
		afficherJeu(*(lj.elements[n]));
		cout << "-----------------------------------------------------" << "\n";
	}
}