#include "Yeux.h"

std::string Yeux::getNom() const {
    return "Yeux";
}
void Yeux::draw(int x,int y, double size,double orientation,UImg & support, T* couleur, float opacite ) const {
    double angle = (20/180.0)*M_PI;
    double xb = x + size * cos(-orientation + angle)/2.5;
    double yb = y + size * sin(-orientation + angle)/2.5;
    double xc = x + size * cos(-orientation - angle)/2.5;
    double yc = y + size * sin(-orientation - angle)/2.5;
    T eyeColor[] = {0, 0, 0};//couleur noire pour les yeux
    support.draw_circle(xb, yb,size/6, eyeColor);
    support.draw_circle(xc, yc,size/6, eyeColor);
    //std::cout << "Drawed Yeux" << std::endl;
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