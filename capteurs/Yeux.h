#ifndef YEUX_H
#define YEUX_H

#include "Capteurs.h"

class Yeux : public Capteurs {
private:
    double visionAngle = VISION_ANGLE_MIN + static_cast<double>(rand()) / RAND_MAX * (VISION_ANGLE_MAX - VISION_ANGLE_MIN);
    double visionDistance = VISION_DISTANCE_MIN + static_cast<double>(rand()) / RAND_MAX * (VISION_DISTANCE_MAX - VISION_DISTANCE_MIN);
    double yeuxDetectionCapacite = VISION_DETECTION_PROBABILITE_MIN + static_cast<double>(rand()) / RAND_MAX * (VISION_DETECTION_PROBABILITE_MAX - VISION_DETECTION_PROBABILITE_MIN);;
public:
    Yeux(void) {};
    std::string getNom() const override;
    void draw(int x,int y, double size,double orientation,UImg & support, T* couleur, float opacite ) const override;
    double getAudibleDistance() override;
    double getOreillesDetectionCapacite() override;
    double getVisionAngle() override;   
    double getVisionDistance() override;
    double getYeuxDetectionCapacite() override;
};

#endif // YEUX_H
