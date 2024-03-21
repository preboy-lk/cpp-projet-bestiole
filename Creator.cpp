#include "Creator.h"

Bestiole* Creator::createBestiole(){
		int beahvior = rand() % 4 + 1; //Create a bestiole with behavior random
		//initialisation de la graine pour les nombres aleatoires
		//std::srand(static_cast<unsigned int>(std::time(nullptr)));
		int age = rand() % 1001 + 300;
		return new Bestiole(beahvior, age);
	}
