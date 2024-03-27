#ifndef ACCESSOIRES_H
#define ACCESSOIRES_H

#include <string>
#include "cfg/Configurations.h"
#include <iostream>
#include "UImg.h"

;

class Accessoires {
public:
    virtual std::string getNom() const = 0;
    virtual void draw(int x,int y, double size,double orientation,UImg & support, T* couleur, float opacite ) const = 0;
    virtual double getCamouflageCapacite() = 0;
    virtual double getProtectionCapacite() = 0;
    virtual void info() = 0;
    virtual double getFacteur() = 0 ;

};

#endif // ACCESSOIRE_H
