#ifndef CAPTEURS_H
#define CAPTEURS_H

#include <string>
#include "Aquarium.h"

class Capteurs {
public:
    virtual std::string getNom() const = 0;
    virtual void draw() const = 0;
    virtual double getAudibleDistance() = 0;
    virtual double getOreillesDetectionCapacite() = 0;
    virtual double getVisionAngle() = 0 ;   
    virtual double getVisionDistance() = 0 ;
    virtual double getYeuxDetectionCapacite() = 0;
};

#endif // CAPTEURS_H