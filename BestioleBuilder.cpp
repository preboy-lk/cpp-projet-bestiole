#include "BestioleBuilder.h"

std::vector<Accessoires*> BestioleBuilder::construireAccessoires() {
    if (static_cast<double>( rand() )/RAND_MAX  < NAGEOIRE_PROBABILITE) {
        accessoires.push_back(new Nageoire());
    }
    if (static_cast<double>( rand() )/RAND_MAX < CARAPACE_PROBABILITE ) {
        accessoires.push_back(new Carapace());
    }
    if (static_cast<double>( rand() )/RAND_MAX < CAMOUFLAGE_PROBABILITE ) {
        accessoires.push_back(new Camouflage());
    }
    return accessoires;
}

std::vector<Capteurs*> BestioleBuilder::construireCapteurs() {
    if (static_cast<double>( rand() )/RAND_MAX < YEUX_PROBABILITE ) {
        capteurs.push_back(new Yeux());
    }
    if (static_cast<double>( rand() )/RAND_MAX < OREILLES_PROBABILITE ) {
        capteurs.push_back(new Oreilles());
    }
    return capteurs;
}
