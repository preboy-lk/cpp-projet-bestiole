#ifndef YEUX_H
#define YEUX_H

#include "Capteurs.h"

class Yeux : public Capteurs {
private:
    double visionAngle = Configurations::VISION_ANGLE_MIN + static_cast<double>(rand()) / RAND_MAX * (Configurations::VISION_ANGLE_MAX - Configurations::VISION_ANGLE_MIN);
    double visionDistance = Configurations::VISION_DISTANCE_MIN + static_cast<double>(rand()) / RAND_MAX * (Configurations::VISION_DISTANCE_MAX - Configurations::VISION_DISTANCE_MIN);
    double yeuxDetectionCapacite = Configurations::VISION_DETECTION_PROBABILITE_MIN + static_cast<double>(rand()) / RAND_MAX * (Configurations::VISION_DETECTION_PROBABILITE_MAX - Configurations::VISION_DETECTION_PROBABILITE_MIN);;
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
