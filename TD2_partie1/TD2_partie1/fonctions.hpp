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
Designer* rechercherDesignerNom(const ListeJeux& lj, string nom) {
	for (Jeu* j : spanListeJeux(lj)) {
		for (Designer* d : spanListeDesigners(j->designers)) {
			if (d->nom == nom) {
				return d;
			}
		}
	}
	cout << "Le designer recherche n'existe pas." << "\n";
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
	Designer* designerLu = new Designer;
	designerLu = rechercherDesignerNom(lj, d.nom);

	if (designerLu == nullptr) {
		*designerLu = d;
	}

	return designerLu;
}

//TODO: Fonction qui double le tableau de jeux de ListeJeux
// Cette fonction doit recevoir en param�tre la nouvelle capacit� du nouveau
// tableau. Il faut allouer un nouveau tableau plus grand, copier ce qu'il y
// avait dans l'ancien, et �liminer l'ancien trop petit. N'oubliez pas, on copie
// des pointeurs de jeux. Il n'y a donc aucune nouvelle allocation ici !
void doublerTaille(unsigned int nouvelleTaille, ListeJeux& lj) {

	Jeu** TableauJeux = new Jeu * [nouvelleTaille];
	int index = 0;
	for (Jeu* j : spanListeJeux(lj)) {
		if (j != nullptr) {
			TableauJeux[index] = j;
			index++;
		}
	}
	delete[] lj.elements;
	lj.capacite = nouvelleTaille;
	lj.elements = TableauJeux;
	return;                                            // Est-ce que l'on retourne quelque chose?
}


//TODO: Fonction pour ajouter un Jeu � ListeJeux
// Le jeu existant d�j� en m�moire, on veut uniquement ajouter le pointeur vers
// le jeu existant. De plus, en cas de saturation du tableau elements, cette
// fonction doit doubler la taille du tableau elements de ListeJeux et d�truire
// l'ancien. Utilisez la fonction de doublement �crite plus haut.
Jeu* ajouterJeu(Jeu jeu, ListeJeux& lj) {
	
	if (lj.capacite == 0) {
		// TODO warning pour la capacite = 0
		cout << "capacite est de 0, mais elle doit etre d'au moins 1" << "\n";
		return nullptr;
	}
	if (lj.nElements == lj.capacite) {
		doublerTaille(lj.capacite * 2, lj);
	}
	lj.nElements += 1;
	*(lj.elements[lj.nElements]) = jeu;
	return lj.elements[lj.nElements];
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
	Jeu* jeuLu = new Jeu;
	jeuLu = ajouterJeu(j, lj);
	
	// Ici on consid�re comme taille la capacit� du tableau de designers � la position 0 de lj.elements, donc le premier jeu sauvegarder dans la listeJeu
	Designer** tableauDesigners = new Designer*[j.designers.nElements];
	
	ListeJeux listeJeuxParticipes = {};
	listeJeuxParticipes.capacite = 1;
	listeJeuxParticipes.nElements = 0;

	for (int n : iter::range(j.designers.nElements))
	{
		lj.nElements = n;
		//TODO: Ajouter un jeu � ListeJeux
		tableauDesigners[n] = lireDesigner(f, lj);																					// On fait quoi avec la capacite?
		tableauDesigners[n]->listeJeuxParticipes.elements[listeJeuxParticipes.nElements] = ajouterJeu(j, listeJeuxParticipes);
		listeJeuxParticipes.nElements++;
		cout << "Allocation en memoire du designer " << tableauDesigners[n]->nom << " est reussie" << "\n";
	}

	// Ici on affecte a Jeu* jeuLu le tableau de designer
	jeuLu->designers.elements = tableauDesigners;
	cout << "Allocation en memoire du jeu " << jeuLu->titre << " est reussie" << "\n";
	return jeuLu;
}

ListeJeux creerListeJeux(const std::string nomFichier)
{
	std::ifstream f(nomFichier, std::ios::binary);
	f.exceptions(std::ios::failbit);
	int nElements = lireUint16(f);
	ListeJeux lj = {};
	lj.capacite = nElements;
	for(int n : iter::range(nElements))
	{
		lj.nElements = n;
		//TODO: Ajouter un jeu � ListeJeux
		lj.elements[n] = lireJeu(f, lj);																								// On fait quoi avec la capacite?
	}
	lj.nElements = nElements;
	//TODO: Renvoyez la ListeJeux
	return lj;
}

//TODO: Fonction qui d�termine si un designer participe encore � un jeu
bool designerParticipe(const ListeJeux& lj, string nomDesigner) {
	Designer* designer = new Designer;
	designer = rechercherDesignerNom(lj, nomDesigner);
	return designer->listeJeuxParticipes.nElements > 0;
}

void swap(int*& a, int*& b)
{
	int* c = a;
	a = b;
	b = c;
}

//TODO: Fonction pour d�truire un designer (lib�ration de m�moire allou�e)
// Lorsqu'on d�truit un designer, on affiche son nom pour fins de d�bogage

/*void detruireDesigner(ListeJeux& lj, string nomDesigner) {
	Designer* designer = new Designer;
	Designer* designerTemp = new Designer;
	for (Jeu* j : spanListeJeux(lj)) {
		designer = rechercherDesignerNom(lj, nomDesigner);
		if (designer != nullptr) {
			delete[] designer->listeJeuxParticipes.elements;			// Est-ce que delete designer deleterait listeJeuxPartivipe?
			delete designer;											
				cout << "Destruction du designer " << nomDesigner << " est reussie pour le jeu " << j->titre << "\n";
		}
		else {
			cout << "Designer " << nomDesigner << " n'existe pas pour le jeu " << j->titre << "\n";
		}
	}
}*/

void detruireDesigner(ListeJeux& lj, string nomDesigner) {
	Designer* designer = new Designer;
	Designer* designerTemp = new Designer;
	for (Jeu* j : spanListeJeux(lj)) {
		designer = rechercherDesignerNom(lj, nomDesigner);
		if (designer != nullptr) {
			designerTemp = j->designers.elements[j->designers.nElements];
			swap(designer, designerTemp);
			delete[] designer->listeJeuxParticipes.elements;			// Est-ce que delete designer deleterait listeJeuxPartivipe?
			delete designer;
			j->designers.nElements--;
			cout << "Destruction du designer " << nomDesigner << " est reussie pour le jeu " << j->titre << "\n";
		}
		else {
			cout << "Designer " << nomDesigner << " n'existe pas pour le jeu " << j->titre << "\n";
		}
	}
}

//TODO: Fonction qui enl�ve un jeu de ListeJeux
// Attention, ici il n'a pas de d�sallocation de m�moire. Elle enl�ve le
// pointeur de la ListeJeux, mais le jeu point� existe encore en m�moire.
// Puisque l'ordre de la ListeJeux n'a pas �tre conserv�, on peut remplacer le
// jeu � �tre retir� par celui pr�sent en fin de liste et d�cr�menter la taille
// de celle-ci
Jeu* enleverJeu(ListeJeux& lj, string titre) {
	Jeu* jeuTemp = new Jeu;
	jeuTemp = lj.elements[lj.nElements];
	for (Jeu* j : spanListeJeux(lj)) {
		if (j->titre == titre) {
			swap(j, jeuTemp);
			lj.nElements--;
			return j;
		}
	}
	return nullptr;
}

//TODO: Fonction pour d�truire un jeu (lib�ration de m�moire allou�e)
// Attention, ici il faut rel�cher toute les cases m�moires occup�es par un jeu.
// Par cons�quent, il va falloir g�rer le cas des designers (un jeu contenant
// une ListeDesigners). On doit commencer par enlever le jeu � d�truire des jeux
// qu'un designer a particip� (listeJeuxParticipes). Si le designer n'a plus de
// jeux pr�sents dans sa liste de jeux particip�s, il faut le supprimer.  Pour
// fins de d�bogage, affichez le nom du jeu lors de sa destruction.
void detruireJeu(ListeJeux& lj, string titre) {
	Jeu* jeuDetruit = new Jeu;
	Designer* designerTemp = new Designer;

	for (Jeu* j : spanListeJeux(lj)) {
		for (Designer* d : spanListeDesigners(j->designers)) {
			jeuDetruit = enleverJeu(d->listeJeuxParticipes, titre);
			if (jeuDetruit != nullptr) {
				delete jeuDetruit;
				cout << "le jeu " << titre << " est detruit de la liste jeux participe de " << d->nom << "\n";
			}
			if (d->listeJeuxParticipes.nElements == 0) {
				designerTemp = j->designers.elements[j->designers.nElements];
				swap(d, designerTemp);
				string nomDesigner = d->nom;
				delete[] d->listeJeuxParticipes.elements;			// Est-ce que delete designer deleterait listeJeuxPartivipe?
				delete d;
				j->designers.nElements--;
				cout << "Destruction du designer " << nomDesigner << " est reussie pour le jeu " << j->titre << "\n";
			}
		}
		jeuDetruit = enleverJeu(lj, titre);
		delete[] jeuDetruit->designers.elements;
		delete jeuDetruit;
		cout << "le jeu " << titre << " est detruit." << "\n";
	}
}


//TODO: Fonction pour d�truire une ListeJeux et tous ses jeux
void detruireListeJeu(ListeJeux& lj) {
	for (Jeu* j : spanListeJeux(lj)) {
		detruireJeu(lj, j->titre);
	}
	lj.capacite = 0;
	lj.nElements = 0;
	delete &lj;
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
	cout << "Les jeux de la liste sont: " << "\n";
	for (int n : iter::range(lj.nElements)) {
		cout << "*********************************" << "\n";
		afficherJeu(*(lj.elements[n]));
		cout << "*********************************" << "\n";
	}
}