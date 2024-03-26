#include "Peureuse.h"

const int Peureuse::FUIR_PENDANT = 60;
const double Peureuse::MULTIPLICATEUR_VITESSE = 1.5;

void Peureuse::info()
{
	cout << " Peureuse" << endl;
}
Peureuse::Peureuse() {
	stepsRestants = 0;
}

// void Peureuse::action(Milieu & m, Bestiole & b)
// {
// 	// Si la bestiole est entrain de fuir :
//     if (stepsRestants > 0) {
//         if (stepsRestants == 1)
//             b.setVitesse(vitesseOriginale);
//         stepsRestants--;
//         return;
//     }
//     // Sinon, vérifions si la bestiole doit fuir
//     vitesseOriginale = b.getVitesse();
//     int nbVoisins = m.nbVoisins(b);

//     // Calcul de l'orientation nécéssaire pour fuir
//     double nouvelleOrientation = b.getOrientation();
//     nouvelleOrientation += M_PI; // On part dans la direction opposée à celle actuelle
//     nouvelleOrientation = fmod(nouvelleOrientation, 2*M_PI);
//     b.setOrientation(nouvelleOrientation);
//     double nouvelleVitesse = vitesseOriginale * MULTIPLICATEUR_VITESSE; // La fuite accélère la vitesse
//     b.setVitesse(nouvelleVitesse);
//     stepsRestants = FUIR_PENDANT; // On fuit pendant FUIR_PENDANT frames
// }

Peureuse::~Peureuse(void) {
	//cout << "Destruct Peureuse" << endl;
}
Peureuse::Peureuse( const Peureuse & b ) {
	setMultiple(this->getMultiple());
}