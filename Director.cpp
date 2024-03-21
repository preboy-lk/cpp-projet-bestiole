#include "Director.h"

void Director::construireBestiole(Bestiole* bestiole, double proba) const {
    BestioleBuilder builder(proba, proba);
    builder.construireAccessoires(bestiole);
    builder.construireCapteurs(bestiole);
    builder.ajusterVitesse(bestiole);
}
