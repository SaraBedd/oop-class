///
/// Fonction principale du projet
///

#include <cstddef>
#include <cstdint>

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

#include <tclap/CmdLine.h>

#include "Case.h"
#include "Carte.h"
#include "EtatJeu.h"
#include "Jeu.h"
#include "EntreeUtilisateur.h"

using namespace std;
using namespace std::literals;

int main() {

	Carte carteJeu("casesFile.txt");
	EtatJeu caseActuelle(carteJeu);
	Jeu jeu(caseActuelle);
	jeu.runJeu();
	
	return 0;
}
