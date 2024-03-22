#include "Nageoire.h"

std::string Nageoire::getNom() const {
    return "Nageoire";
}

void Nageoire::draw(int x,int y,double size,UImg & support, T* couleur) const{
    std::cout<< "Drawed Nageoire" <<std::endl;
}

void Nageoire::info() {
    std::cout <<" a une Nageoire" << endl;
}

double Nageoire::getProtectionCapacite()
    {return 0.f;}
double Nageoire::getCamouflageCapacite()
    {return 0.f;}