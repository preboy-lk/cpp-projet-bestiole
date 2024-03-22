#include "Camouflage.h"

Camouflage::Camouflage() {
    std::cout << "const Bestiole (" << "I will fix here"<< ") a un Camouflage" << endl;
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