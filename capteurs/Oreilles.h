#ifndef OREILLES_H
#define OREILLES_H

#include "Capteurs.h"
#include "Bestiole.h"

class Oreilles : public Capteurs {
private:
    double audibleDistance = Aquarium::AUDIBLE_DISTANCE_MIN + static_cast<double>(rand()) / RAND_MAX * (Aquarium::AUDIBLE_DISTANCE_MAX - Aquarium::AUDIBLE_DISTANCE_MIN);
    double oreillesDetectionCapacite = Aquarium::AUDIBLE_DETECTION_PROBABILITE_MIN + static_cast<double>(rand()) / RAND_MAX * (Aquarium::AUDIBLE_DETECTION_PROBABILITE_MAX - Aquarium::AUDIBLE_DETECTION_PROBABILITE_MIN);;
public:
    Oreilles(Bestiole* bestiole);
    std::string getNom() const override;
    void draw() const override;
    double getDetectionCapacite() override;
};
#endif // OREILLES_H
