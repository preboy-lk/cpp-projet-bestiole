#include "Yeux.h"

std::string Yeux::getNom() const {
    return "Yeux";
}
void Yeux::draw() const {
    std::cout << "Drawed Yeux" << std::endl;
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