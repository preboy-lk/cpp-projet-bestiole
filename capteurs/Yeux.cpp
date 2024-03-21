#include "Yeux.h"

Yeux::Yeux(Bestiole* bestiole) {
    std::cout << "const Bestiole (" << bestiole->getIdentite() << ") a des Yeux" << endl;
}

std::string Yeux::getNom() const {
    return "Yeux";
}
void Yeux::draw() const {
    std::cout << "Drawed Yeux" << std::endl;
}

double Yeux::getDetectionCapacite()
    {return yeuxDetectionCapacite;}