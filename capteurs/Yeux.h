#ifndef YEUX_H
#define YEUX_H

#include "Capteurs.h"
#include "Bestiole.h"

class Yeux : public Capteurs {
private:
    double visionAngle = Aquarium::VISION_ANGLE_MIN + static_cast<double>(rand()) / RAND_MAX * (Aquarium::VISION_ANGLE_MAX - Aquarium::VISION_ANGLE_MIN);
    double visionDistance = Aquarium::VISION_DISTANCE_MIN + static_cast<double>(rand()) / RAND_MAX * (Aquarium::VISION_DISTANCE_MAX - Aquarium::VISION_DISTANCE_MIN);
    double yeuxDetectionCapacite = Aquarium::VISION_DETECTION_PROBABILITE_MIN + static_cast<double>(rand()) / RAND_MAX * (Aquarium::VISION_DETECTION_PROBABILITE_MAX - Aquarium::VISION_DETECTION_PROBABILITE_MIN);;
public:
    Yeux(Bestiole* bestiole);
    std::string getNom() const override;
    void draw() const override;
    double getDetectionCapacite() override;
};

#endif // YEUX_H
