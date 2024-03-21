#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "Accessoires.h"

class Nageoire : public Accessoires {
public:
    std::string getNom() const override;
};

#endif // NAGEOIRE_H
