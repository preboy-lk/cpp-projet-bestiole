#include "Director.h"

Director::Director(double probAccessoire, double probCapteur)
    : probAccessoire(probAccessoire), probCapteur(probCapteur) {}

void Director::construireBestiole(Bestiole* bestiole) const {
    BestioleBuilder builder(probAccessoire, probCapteur);
    builder.construireAccessoires(bestiole);
    builder.construireCapteurs(bestiole);
    builder.ajusterVitesse(bestiole);
}
