#include "Oreilles.h"

std::string Oreilles::getNom() const {
    return "Oreilles";
}
void Oreilles::draw(int x,int y, double size,double orientation,UImg & support, T* couleur) const {
    //support.draw_circle( x, y, audibleDistance, couleur );
}

double Oreilles::getAudibleDistance()
{
    return audibleDistance;
}

double Oreilles::getOreillesDetectionCapacite()
{
    return oreillesDetectionCapacite;
}
double Oreilles::getVisionAngle()
{ return 0.f;}  
double Oreilles::getVisionDistance()
{ return 0.f;}
double Oreilles::getYeuxDetectionCapacite()
{ return 0.f;}
