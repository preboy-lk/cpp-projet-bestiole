#include "BestioleBuilder.h"

BestioleBuilder::BestioleBuilder(double probAccessoire, double probCapteur) : probAccessoire(probAccessoire), probCapteur(probCapteur) {}

void BestioleBuilder::construireAccessoires(Bestiole* bestiole) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    if (dis(gen) < probAccessoire) {
        bestiole->ajouterAccessoires(new Nageoire());
    }
    if (dis(gen) < probAccessoire) {
        bestiole->ajouterAccessoires(new Carapace());
    }
    if (dis(gen) < probAccessoire) {
        bestiole->ajouterAccessoires(new Camouflage());
    }
}

void BestioleBuilder::construireCapteurs(Bestiole* bestiole) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    if (dis(gen) < probCapteur) {
        bestiole->ajouterCapteurs(new Yeux());
    }
    if (dis(gen) < probCapteur) {
        bestiole->ajouterCapteurs(new Oreilles());
    }
}

void BestioleBuilder::ajusterVitesse(Bestiole* bestiole) const {
    for (const auto& accessoire : bestiole->getAccessoires()) {
        if (accessoire->getNom() == "Nageoire") {
            //bestiole->augmenterVitesse(1.5);
            std::cout << "const Bestiole (" << bestiole->getIdentite() << ") have Nageoire" << endl;
            break;
        }
    }
}