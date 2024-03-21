#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Accessoires.h"

class Camouflage : public Accessoires {
public:
    std::string getNom() const override;
};

#endif // CAMOUFLAGE_H
