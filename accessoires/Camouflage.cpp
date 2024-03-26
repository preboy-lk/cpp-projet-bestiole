#include "Camouflage.h"

void Camouflage::info() {
    std::cout <<" a un Camouflage" << std::endl;
}

std::string Camouflage::getNom() const {
    return "Camouflage";
}
void Camouflage::draw(int x,int y, double size,double orientation,UImg & support, T* couleur, float opacite ) const {
    //std::cout << "Drawed Camouflage" << std::endl;
}

double Camouflage::getCamouflageCapacite()
    {return camouflageCapacite;}
double Camouflage::getProtectionCapacite()
    {return 1.f;}
double Camouflage::getFacteur() 
    {return 1.f;}