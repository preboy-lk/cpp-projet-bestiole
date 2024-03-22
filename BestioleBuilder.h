#ifndef BESTIOLE_BUILDER_H
#define BESTIOLE_BUILDER_H

#include "Bestiole.h"
#include "Builder.h"
#include "Aquarium.h"
#include "accessoires/Accessoires.h"
#include "accessoires/Camouflage.h"
#include "accessoires/Carapace.h"
#include "accessoires/Nageoire.h"
#include "capteurs/Capteurs.h"
#include "capteurs/Oreilles.h"
#include "capteurs/Yeux.h"
#include <random>

class BestioleBuilder : public Builder {
public:
    void construireAccessoires(Bestiole* bestiole) const override;
    void construireCapteurs(Bestiole* bestiole) const override;

private:
    double probAccessoire;
    double probCapteur;
};

#endif // BESTIOLE_BUILDER_H