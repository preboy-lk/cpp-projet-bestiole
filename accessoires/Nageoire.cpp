#include "Nageoire.h"

std::string Nageoire::getNom() const {
    return "Nageoire";
}

void Nageoire::draw() const{
    std::cout<< "Drawed Nageoire" <<std::endl;
}

Nageoire::Nageoire(Bestiole* bestiole) {
    bestiole->augmenterVitesse(accelerate);
    std::cout << "const Bestiole (" << bestiole->getIdentite() << ") a une Nageoire" << endl;
}
