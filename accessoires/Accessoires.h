#ifndef ACCESSOIRES_H
#define ACCESSOIRES_H

#include <string>
#include "Aquarium.h"

class Accessoires {
public:
    virtual std::string getNom() const = 0;
    virtual void draw() const = 0;
    virtual double getCamouflageCapacite() = 0;
    virtual double getProtectionCapacite() = 0;

};

#endif // ACCESSOIRE_H
