#ifndef CARAPACE_H
#define CARAPACE_H

#include "Accessoires.h"
#include "Bestiole.h"

class Carapace : public Accessoires {
private:
    double protectionCapacite = Aquarium::MEURT_COLLISION_PROBABILITE / ( 1 + static_cast<double>(rand()) / RAND_MAX * (Aquarium::MEURT_REDUCTION_COEFF - 1));
    double decelerate = 1 + static_cast<double>(rand()) / RAND_MAX * (Aquarium::VITESSE_REDUCTION_COEFF - 1);
public:
    Carapace(Bestiole* bestiole);
    std::string getNom() const override;
    void draw() const override;
    double getCamouflageCapacite() override;
    double getProtectionCapacite() override;
};

#endif // CARAPACE_H
