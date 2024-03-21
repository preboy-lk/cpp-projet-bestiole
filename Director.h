#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"
#include "Bestiole.h"
#include "BestioleBuilder.h"

class Director {
public:
    Director(double probAccessoire, double probCapteur);
    void construireBestiole(Bestiole* bestiole) const;

private:
    double probAccessoire;
    double probCapteur;
};

#endif // DIRECTOR_H
