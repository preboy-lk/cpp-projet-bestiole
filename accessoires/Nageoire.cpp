#include "Nageoire.h"

std::string Nageoire::getNom() const {
    return "Nageoire";
}

void Nageoire::draw() const{
    std::cout<< "Drawed Nageoire" <<std::endl;
}

Nageoire::Nageoire() {
    //bestiole->augmenterVitesse(accelerate);
    std::cout << "const Bestiole (" << "Ore wa kai zu ku" << ") a une Nageoire" << endl;
}
double Nageoire::getProtectionCapacite()
    {return 0.f;}
double Nageoire::getCamouflageCapacite()
    {return 0.f;}