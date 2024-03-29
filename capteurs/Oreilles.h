#ifndef OREILLES_H
#define OREILLES_H

#include "Capteurs.h"
#include "Bestiole.h"

class Oreilles : public Capteurs {
private:
    double audibleDistance = Configurations::AUDIBLE_DISTANCE_MIN + static_cast<double>(rand()) / RAND_MAX * (Configurations::AUDIBLE_DISTANCE_MAX - Configurations::AUDIBLE_DISTANCE_MIN);
    double oreillesDetectionCapacite = Configurations::AUDIBLE_DETECTION_PROBABILITE_MIN + static_cast<double>(rand()) / RAND_MAX * (Configurations::AUDIBLE_DETECTION_PROBABILITE_MAX - Configurations::AUDIBLE_DETECTION_PROBABILITE_MIN);;
public:
    Oreilles(void){};
    std::string getNom() const override;
    void draw(int x,int y, double size,double orientation,UImg & support, T* couleur, float opacite ) const override;
    double getAudibleDistance() override;
    double getOreillesDetectionCapacite() override;
    double getVisionAngle() override;   
    double getVisionDistance() override;
    double getYeuxDetectionCapacite() override;
};
#endif // OREILLES_H
