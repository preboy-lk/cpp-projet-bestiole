#include "Oreilles.h"

std::string Oreilles::getNom() const {
    return "Oreilles";
}
void Oreilles::draw(int x,int y, double size,double orientation,UImg & support, T* couleur) const {
    double xt = x + cos( orientation )*size/2.1;
    double yt = y - sin( orientation )*size/2.1;
    double angle = (45/180.0)*M_PI;
    double xb = xt - size * cos(-orientation + angle);
    double yb = yt - size * sin(-orientation + angle);
    double xc = xt - size * cos(-orientation - angle);
    double yc = yt - size * sin(-orientation - angle);
    //T earColor[] = {0, 0, 0};//couleur noire pour les oreilles
    support.draw_line(xb, yb, xc, yc, couleur, 2.0f);
    //std::cout << "Drawed Oreilles" << std::endl;
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
