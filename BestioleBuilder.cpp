#include "BestioleBuilder.h"

std::vector<AccessoiresPtr> BestioleBuilder::construireAccessoires() {
    if (static_cast<double>( rand() )/RAND_MAX  < Configurations::NAGEOIRE_PROBABILITE) {
        accessoires.push_back(std::make_shared<Nageoire>());
    }
    if (static_cast<double>( rand() )/RAND_MAX < Configurations::CARAPACE_PROBABILITE ) {
        accessoires.push_back(std::make_shared<Carapace>());
    }
    if (static_cast<double>( rand() )/RAND_MAX < Configurations::CAMOUFLAGE_PROBABILITE ) {
        accessoires.push_back(std::make_shared<Camouflage>());
    }
    return accessoires;
}

std::vector<CapteursPtr> BestioleBuilder::construireCapteurs() {
    if (static_cast<double>( rand() )/RAND_MAX < Configurations::YEUX_PROBABILITE ) {
        capteurs.push_back(std::make_shared<Yeux>());
    }
    if (static_cast<double>( rand() )/RAND_MAX < Configurations::OREILLES_PROBABILITE ) {
        capteurs.push_back(std::make_shared<Oreilles>());
    }
    return capteurs;
}
