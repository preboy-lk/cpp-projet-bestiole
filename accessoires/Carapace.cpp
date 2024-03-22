#include "Carapace.h"

Carapace::Carapace() {
    std::cout << "const Bestiole (" << "I will fix it" << ") a une Carapace" << endl;
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