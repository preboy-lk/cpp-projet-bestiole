#include "Camouflage.h"

void Camouflage::info() {
    std::cout <<" a un Camouflage" << endl;
}

std::string Camouflage::getNom() const {
    return "Camouflage";
}
void Camouflage::draw(int x,int y, double size,double orientation,UImg & support, T* couleur) const {
    std::cout << "Drawed Camouflage" << std::endl;
}

double Camouflage::getCamouflageCapacite()
    {return camouflageCapacite;}
double Camouflage::getProtectionCapacite()
    {return 0.f;}
double Camouflage::getFacteur() 
    {return 1.f;}