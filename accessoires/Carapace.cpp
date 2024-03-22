#include "Carapace.h"

void Carapace::info() {
    std::cout <<" a une Carapace" << endl;
}

std::string Carapace::getNom() const {
    return "Carapace";
}

void Carapace::draw(int x,int y,double size,UImg & support, T* couleur) const {
    //int couleur = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
    support.draw_circle( x, y,size/2, couleur );
    //support.draw_circle( xt, yt, AFF_SIZE/2., couleur );
    std::cout << "Drawed Carapace" << std::endl;
}

double Carapace::getProtectionCapacite()
    {return protectionCapacite;}
double Carapace::getCamouflageCapacite()
    {return 0.f;}