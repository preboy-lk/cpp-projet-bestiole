#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "Accessoires.h"

class Nageoire : public Accessoires {
private:
    double facteur = 1 + static_cast<double>(rand()) / RAND_MAX * (Aquarium::ACCELERATION_COEFF - 1);

public:
    void info() ;
    Nageoire(void) {};
    std::string getNom() const override;
    void draw(int x,int y,double size,double orientation,UImg & support, T* couleur) const override;
    double getCamouflageCapacite() override;
    double getProtectionCapacite() override;
    double getFacteur() {return facteur;}
};

#endif // NAGEOIRE_H
