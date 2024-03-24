#ifndef CARAPACE_H
#define CARAPACE_H

#include "Accessoires.h"

class Carapace : public Accessoires {
private:
    double protectionCapacite =  1 + static_cast<double>(rand()) / RAND_MAX * (MEURT_REDUCTION_COEFF - 1);
    double facteur = 1/(1 + static_cast<double>(rand()) / RAND_MAX * (VITESSE_REDUCTION_COEFF - 1));
public:
    void info() override;
    Carapace(void) {};
    std::string getNom() const override;
    void draw(int x,int y, double size,double orientation,UImg & support, T* couleur) const override;
    double getCamouflageCapacite() override;
    double getProtectionCapacite() override;
    double getFacteur() override;
};

#endif // CARAPACE_H
