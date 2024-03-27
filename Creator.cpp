#include "Creator.h"

BestiolePtr Creator::createBestiole()
{
	// Les 2 lignes de code ci-dessous garantissent que 
	// les comportements sont correctement divisés selon
	// le ratio de configuration spécifié
	std::unique_ptr<Bestiole> bestiole;
	int behavior = bestiole->selectionComportement();

	int age = rand() % 1001 + 300;

	//Builder pour fixer des accessoires et des capteurs a la bestiole
	std::vector<std::shared_ptr<Accessoires>> accessoires;
	std::vector<std::shared_ptr<Capteurs>> capteurs;
	std::unique_ptr<BestioleBuilder> builder(new BestioleBuilder);
	accessoires = builder->construireAccessoires();
	capteurs = builder->construireCapteurs();

	float opacite = 1.f;
	for (const auto& accessoire : accessoires) {//check if has camouflage
		if (accessoire->getNom() == "Camouflage"){
			opacite = 0.3;
	    }
   	}

	return std::make_shared<Bestiole>(behavior, age, opacite, accessoires, capteurs);
}
