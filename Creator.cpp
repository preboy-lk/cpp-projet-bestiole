#include "Creator.h"

Bestiole* Creator::createBestiole()
{
	// Les 2 lignes de code ci-dessous garantissent que 
	// les comportements sont correctement divisés selon
	// le ratio de configuration spécifié
	std::unique_ptr<Bestiole> bestiole;
	int behavior = bestiole->selectionComportement();

	int age = rand() % 1001 + 300;

	//Builder pour fixer des accessoires et des capteurs a la bestiole
	std::vector<Accessoires*> accessoires;
	std::vector<Capteurs*> capteurs;
	std::unique_ptr<BestioleBuilder> builder(new BestioleBuilder);
	accessoires = builder->construireAccessoires();
	capteurs = builder->construireCapteurs();
	return new Bestiole(behavior, age, std::move(accessoires), std::move(capteurs));
}
