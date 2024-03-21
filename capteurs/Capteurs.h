#ifndef CAPTEURS_H
#define CAPTEURS_H

#include <string>
#include "Aquarium.h"

class Capteurs {
public:
    virtual std::string getNom() const = 0;
    virtual void draw() const = 0;
    virtual double getDetectionCapacite() = 0;
};

#endif // CAPTEURS_H
