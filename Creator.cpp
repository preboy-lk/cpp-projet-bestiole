#include "Creator.h"

Bestiole* Creator::createBestiole(){
		int behavior = rand() % 4 + 1; //Create a bestiole with behavior random
		//int beahvior = 3;
		int age = rand() % 1001 + 300;

		//Builder pour fixer des accessoires et des capteurs a la bestiole
		std::vector<Accessoires*> accessoires;
    	std::vector<Capteurs*> capteurs;
		std::unique_ptr<BestioleBuilder> builder(new BestioleBuilder);
		accessoires = builder->construireAccessoires();
		capteurs = builder->construireCapteurs();
		return new Bestiole(behavior, age, std::move(accessoires), std::move(capteurs));
	}
