#include "Carapace.h"

void Carapace::info() {
    std::cout <<" a une Carapace" << std::endl;
}

std::string Carapace::getNom() const {
    return "Carapace";
}

void Carapace::draw(int x,int y, double size,double orientation,UImg & support, T* couleur, float opacite ) const {
    support.draw_ellipse( x, y, size*2, size, -orientation/M_PI*180., couleur, 1.5f, ~0U);
    //std::cout << "Drawed Carapace" << std::endl;
}

double Carapace::getProtectionCapacite()
    {return protectionCapacite;}
double Carapace::getCamouflageCapacite()
    {return 0.f;}
double Carapace::getFacteur()
    {return facteur;}