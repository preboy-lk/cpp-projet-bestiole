#include "BestioleBuilder.h"

void BestioleBuilder::construireAccessoires(Bestiole* bestiole) const {
    if (static_cast<double>( rand() )/RAND_MAX  < Aquarium::NAGEOIRE_PROBABILITE) {
        bestiole->ajouterAccessoires(new Nageoire());
    }

    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::CARAPACE_PROBABILITE ) {
        bestiole->ajouterAccessoires(new Carapace());
    }
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::CAMOUFLAGE_PROBABILITE ) {
        bestiole->ajouterAccessoires(new Camouflage());
    }
}

void BestioleBuilder::construireCapteurs(Bestiole* bestiole) const {
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::YEUX_PROBABILITE ) {
        bestiole->ajouterCapteurs(new Yeux());
    }
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::OREILLES_PROBABILITE ) {
        bestiole->ajouterCapteurs(new Oreilles());
    }
}
