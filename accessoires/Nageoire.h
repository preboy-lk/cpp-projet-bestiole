#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "Accessoires.h"

class Nageoire : public Accessoires {
private:
    double accelerate = 1 + static_cast<double>(rand()) / RAND_MAX * (Aquarium::ACCELERATION_COEFF - 1);

public:
    Nageoire();
    std::string getNom() const override;
    void draw() const override;
    double getCamouflageCapacite() override;
    double getProtectionCapacite() override;
};

#endif // NAGEOIRE_H
