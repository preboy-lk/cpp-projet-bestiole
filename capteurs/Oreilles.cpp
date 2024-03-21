#include "Oreilles.h"

Oreilles::Oreilles(Bestiole* bestiole) {
    std::cout << "const Bestiole (" << bestiole->getIdentite() << ") a des Oreilles" << std::endl;
}
std::string Oreilles::getNom() const {
    return "Oreilles";
}
void Oreilles::draw() const {
    std::cout << "Drawed Oreilles" << std::endl;
}

double Oreilles::getDetectionCapacite()
    {return oreillesDetectionCapacite;}