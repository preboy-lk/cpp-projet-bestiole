#include "Carapace.h"

Carapace::Carapace(Bestiole* bestiole) {
    bestiole->augmenterVitesse(1/decelerate);
    std::cout << "const Bestiole (" << bestiole->getIdentite() << ") a une Carapace" << endl;
}

std::string Carapace::getNom() const {
    return "Carapace";
}

void Carapace::draw() const {
    std::cout << "Drawed Carapace" << std::endl;
}

double Carapace::getProtectionCapacite()
    {return protectionCapacite;}
double Carapace::getCamouflageCapacite()
    {return 0.f;}