#include "BestioleBuilder.h"

std::vector<Accessoires*> BestioleBuilder::construireAccessoires() {
    if (static_cast<double>( rand() )/RAND_MAX  < Aquarium::NAGEOIRE_PROBABILITE) {
        accessoires.push_back(new Nageoire());
    }
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::CARAPACE_PROBABILITE ) {
        accessoires.push_back(new Carapace());
    }
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::CAMOUFLAGE_PROBABILITE ) {
        accessoires.push_back(new Camouflage());
    }
    return accessoires;
}

std::vector<Capteurs*> BestioleBuilder::construireCapteurs() {
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::YEUX_PROBABILITE ) {
        capteurs.push_back(new Yeux());
    }
    if (static_cast<double>( rand() )/RAND_MAX < Aquarium::OREILLES_PROBABILITE ) {
        capteurs.push_back(new Oreilles());
    }
    return capteurs;
}
