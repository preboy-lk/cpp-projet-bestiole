#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Accessoires.h"

class Camouflage : public Accessoires {
private:
    double camouflageCapacite = Aquarium::CAMOUFLAGE_CAPACITE_MIN + static_cast<double>(rand()) / RAND_MAX * (Aquarium::CAMOUFLAGE_CAPACITE_MAX - Aquarium::CAMOUFLAGE_CAPACITE_MIN);;
public:
    void info() ;
    Camouflage(void){};
    std::string getNom() const override;
    void draw() const override;
    double getCamouflageCapacite() override;
    double getProtectionCapacite() override;
};

#endif // CAMOUFLAGE_H
