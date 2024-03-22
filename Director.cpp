#include "Director.h"

void Director::construireBestiole(Bestiole* bestiole) const {
    BestioleBuilder builder;
    builder.construireAccessoires(bestiole);
    builder.construireCapteurs(bestiole);
}
