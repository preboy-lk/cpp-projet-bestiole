#ifndef BESTIOLE_BUILDER_H
#define BESTIOLE_BUILDER_H

#include <random>
#include "accessoires/Accessoires.h"
#include "accessoires/Camouflage.h"
#include "accessoires/Carapace.h"
#include "accessoires/Nageoire.h"

#include "capteurs/Capteurs.h"
#include "capteurs/Oreilles.h"
#include "capteurs/Yeux.h"

class BestioleBuilder {
public:
    std::vector<Accessoires*> construireAccessoires();
    std::vector<Capteurs*> construireCapteurs();

private:
    std::vector<Accessoires*> accessoires;
    std::vector<Capteurs*> capteurs;
};

#endif // BESTIOLE_BUILDER_H