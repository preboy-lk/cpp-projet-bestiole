#ifndef CAPTEURS_H
#define CAPTEURS_H

#include <string>
#include <iostream>
#include "cfg/Configurations.h"
#include "UImg.h"

using namespace Configurations;

class Capteurs {
public:
    virtual std::string getNom() const = 0;
    virtual void draw(int x,int y, double size,double orientation,UImg & support, T* couleur) const = 0;
    virtual double getAudibleDistance() = 0;
    virtual double getOreillesDetectionCapacite() = 0;
    virtual double getVisionAngle() = 0 ;   
    virtual double getVisionDistance() = 0 ;
    virtual double getYeuxDetectionCapacite() = 0;
};

#endif // CAPTEURS_H
