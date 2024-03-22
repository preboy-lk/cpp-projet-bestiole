#include "Nageoire.h"

std::string Nageoire::getNom() const {
    return "Nageoire";
}

void Nageoire::draw(int x,int y,double size, double orientation,UImg & support, T* couleur) const{
    double xq = x - cos( orientation )*size;
    double yq = y + sin( orientation )*size;
    double angle = (30/180.0)*M_PI;
    double xb = xq - size * cos(-orientation + angle);
    double yb = yq - size * sin(-orientation + angle);
    double xc = xq - size * cos(-orientation - angle);
    double yc = yq - size * sin(-orientation - angle);
    support.draw_triangle( xq, yq, xb, yb, xc, yc, couleur );
    std::cout<< "Drawed Nageoire" <<std::endl;
}

void Nageoire::info() {
    std::cout <<" a une Nageoire" << endl;
}

double Nageoire::getProtectionCapacite()
    {return 0.f;}
double Nageoire::getCamouflageCapacite()
    {return 0.f;}