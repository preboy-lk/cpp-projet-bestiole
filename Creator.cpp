#include "Creator.h"

Bestiole* Creator::createBestiole(){
		int beahvior = rand() % 4 + 1; //Create a bestiole with behavior random
		//int beahvior = 3;
		int age = rand() % 1001 + 300;

		Nageoire* nageoire = new Nageoire();
		Carapace* carapace = new Carapace();
		Camouflage* camouflage = new Camouflage();


		std::vector<Accessoires*> accessoires;


		if (static_cast<double>( rand() )/RAND_MAX  < Aquarium::NAGEOIRE_PROBABILITE) {
        accessoires.push_back(nageoire);
	    }

	    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::CARAPACE_PROBABILITE ) {
	        accessoires.push_back(carapace);
	    }
	    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::CAMOUFLAGE_PROBABILITE ) {
	        accessoires.push_back(camouflage);
	    }

		return new Bestiole(beahvior, age, accessoires);
	}
