#include "Carapace.h"

void Carapace::info() {
    std::cout <<" a une Carapace" << std::endl;
}

std::string Carapace::getNom() const {
    return "Carapace";
}

void Carapace::draw(int x,int y, double size,double orientation,UImg & support, T* couleur) const {
    //support.draw_circle( x, y,size/2, couleur );
    //std::cout << "Drawed Carapace" << std::endl;
}

double Carapace::getProtectionCapacite()
    {return protectionCapacite;}
double Carapace::getCamouflageCapacite()
    {return 0.f;}
double Carapace::getFacteur()
    {return facteur;}