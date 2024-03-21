#include "BestioleBuilder.h"

BestioleBuilder::BestioleBuilder(double probAccessoire, double probCapteur) : probAccessoire(probAccessoire), probCapteur(probCapteur) {}

void BestioleBuilder::construireAccessoires(Bestiole* bestiole) const {
    if (static_cast<double>( rand() )/RAND_MAX  < Aquarium::NAGEOIRE_PROBABILITE) {
        bestiole->ajouterAccessoires(new Nageoire(bestiole));
    }

    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::CARAPACE_PROBABILITE ) {
        bestiole->ajouterAccessoires(new Carapace(bestiole));
    }
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::CAMOUFLAGE_PROBABILITE ) {
        bestiole->ajouterAccessoires(new Camouflage(bestiole));
    }
}

void BestioleBuilder::construireCapteurs(Bestiole* bestiole) const {
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::YEUX_PROBABILITE ) {
        bestiole->ajouterCapteurs(new Yeux(bestiole));
    }
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::OREILLES_PROBABILITE ) {
        bestiole->ajouterCapteurs(new Oreilles(bestiole));
    }
}
