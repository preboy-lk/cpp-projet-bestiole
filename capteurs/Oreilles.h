#ifndef OREILLES_H
#define OREILLES_H

#include "Capteurs.h"

class Oreilles : public Capteurs {
public:
    std::string getNom() const override;
};

#endif // OREILLES_H
