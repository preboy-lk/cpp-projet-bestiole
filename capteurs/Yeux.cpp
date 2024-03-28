#include "Yeux.h"

std::string Yeux::getNom() const {
    return "Yeux";
}
void Yeux::draw(int x,int y, double size,double orientation,UImg & support, T* couleur, float opacite ) const {
    /*double angle = (20/180.0)*M_PI;
    double xb = x + size * cos(-orientation + angle)/2.5;
    double yb = y + size * sin(-orientation + angle)/2.5;
    double xc = x + size * cos(-orientation - angle)/2.5;
    double yc = y + size * sin(-orientation - angle)/2.5;
    T eyeColor[] = {0, 0, 0};//couleur noire pour les yeux
    support.draw_circle(xb, yb,size/6, eyeColor);
    support.draw_circle(xc, yc,size/6, eyeColor);*/
    //std::cout << "Drawed Yeux" << std::endl;
    double angle = visionAngle/2;
    double xb = x + visionDistance * cos(orientation - angle);
    double yb = y - visionDistance * sin(orientation - angle);
    double xc = x + visionDistance * cos(orientation + angle);
    double yc = y - visionDistance * sin(orientation + angle);
    float opacity = 0.3f;
    support.draw_triangle( x, y, xb, yb, xc, yc, couleur, opacity );
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