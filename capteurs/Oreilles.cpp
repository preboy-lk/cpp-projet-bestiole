#include "Oreilles.h"

Oreilles::Oreilles() {
    std::cout << "const Bestiole (" << "xyz" << ") a des Oreilles" << std::endl;
}
std::string Oreilles::getNom() const {
    return "Oreilles";
}
void Oreilles::draw() const {
    std::cout << "Drawed Oreilles" << std::endl;
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