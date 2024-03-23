#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Accessoires.h"

class Camouflage : public Accessoires {
private:
    double camouflageCapacite = Aquarium::CAMOUFLAGE_CAPACITE_MIN + static_cast<double>(rand()) / RAND_MAX * (Aquarium::CAMOUFLAGE_CAPACITE_MAX - Aquarium::CAMOUFLAGE_CAPACITE_MIN);;
public:
    void info() override;
    Camouflage(void){};
    std::string getNom() const override;
    void draw(int x,int y, double size,double orientation,UImg & support, T* couleur) const override;
    double getCamouflageCapacite() override;
    double getProtectionCapacite() override;
    double getFacteur() override;
};

#endif // CAMOUFLAGE_H
