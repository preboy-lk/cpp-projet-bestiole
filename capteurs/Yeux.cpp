#include "Yeux.h"

std::string Yeux::getNom() const {
    return "Yeux";
}
void Yeux::draw(int x,int y, double size,double orientation,UImg & support, T* couleur) const {
    // double xq = x;
    // double yq = y;
    // double angle = visionAngle/2;
    // double xb = xq + visionDistance * cos(orientation - angle);
    // double yb = yq - visionDistance * sin(orientation - angle);
    // double xc = xq + visionDistance * cos(orientation + angle);
    // double yc = yq - visionDistance * sin(orientation + angle);
    // float opacite = 0.3;
    // support.draw_triangle( xq, yq, xb, yb, xc, yc, couleur );
}

double Yeux::getAudibleDistance()
{
    return 0.f;
}

double Yeux::getOreillesDetectionCapacite()
{
    return 0.f;
}
double Yeux::getVisionAngle()
{ return visionAngle;}  
double Yeux::getVisionDistance()
{ return visionDistance;}
double Yeux::getYeuxDetectionCapacite()
{ return yeuxDetectionCapacite;}