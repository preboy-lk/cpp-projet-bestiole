#include "Camouflage.h"

Camouflage::Camouflage(Bestiole* bestiole) {
    std::cout << "const Bestiole (" << bestiole->getIdentite() << ") a un Camouflage" << endl;
}

std::string Camouflage::getNom() const {
    return "Camouflage";
}
void Camouflage::draw() const {
    std::cout << 'Drawed Camouflage' << std::endl;
}

double Camouflage::getCamouflageCapacite()
    {return camouflageCapacite;}
double Camouflage::getProtectionCapacite()
    {return 0.f;}