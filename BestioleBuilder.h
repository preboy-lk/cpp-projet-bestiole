#ifndef BESTIOLE_BUILDER_H
#define BESTIOLE_BUILDER_H

#include <random>
#include <memory>
#include "accessoires/Accessoires.h"
#include "accessoires/Camouflage.h"
#include "accessoires/Carapace.h"
#include "accessoires/Nageoire.h"

#include "capteurs/Capteurs.h"
#include "capteurs/Oreilles.h"
#include "capteurs/Yeux.h"

using AccessoiresPtr = std::shared_ptr<Accessoires>;
using CapteursPtr = std::shared_ptr<Capteurs>;

class BestioleBuilder {
public:
    std::vector<AccessoiresPtr> construireAccessoires();
    std::vector<CapteursPtr> construireCapteurs();

private:
    std::vector<AccessoiresPtr> accessoires;
    std::vector<CapteursPtr> capteurs;
};

#endif // BESTIOLE_BUILDER_H