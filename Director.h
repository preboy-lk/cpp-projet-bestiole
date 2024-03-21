#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"
#include "Bestiole.h"
#include "BestioleBuilder.h"

class Director {
public:
    void construireBestiole( Bestiole* bestiole, double proba) const;
};

#endif // DIRECTOR_H
