#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <cmath>

class Configurations {
public: 
    //Taux de naissance
    static double TAUX_NAISSANCE;

    // Clonage Probabilité
    static double CLONAGE_PROBABILITE;

    // Pourcentage de bestioles possédant un comportement dynamique particulier
    static float GREGAIRE_RATIO;
    static float PEUREUSE_RATIO;
    static float KAMIKAZE_RATIO;
    static float PREVOYANTE_RATIO;
    static float MULTIPLE_RATIO;

    // probabilité de décès après une collision
    static float MEURT_COLLISION_PROBABILITE;

    // Paramètres pour les capteurs : yeux et oreilles
    static float VISION_ANGLE_MIN; // radian
    static float VISION_ANGLE_MAX; // radian
    static float VISION_DISTANCE_MIN;
    static float VISION_DISTANCE_MAX;
    static float VISION_DETECTION_PROBABILITE_MIN;
    static float VISION_DETECTION_PROBABILITE_MAX;
    static float AUDIBLE_DISTANCE_MIN;
    static float AUDIBLE_DISTANCE_MAX;
    static float AUDIBLE_DETECTION_PROBABILITE_MIN;
    static float AUDIBLE_DETECTION_PROBABILITE_MAX;

    // Paramètres pour les accessoires
    static float CAMOUFLAGE_CAPACITE_MIN;
    static float CAMOUFLAGE_CAPACITE_MAX;
    static float VITESSE_REDUCTION_COEFF;
    static float ACCELERATION_COEFF;
    static float MEURT_REDUCTION_COEFF;

    // Probabilité que la bestiole est équipée avec accessoires et capteurs
    static float YEUX_PROBABILITE;
    static float OREILLES_PROBABILITE;
    static float CAMOUFLAGE_PROBABILITE;
    static float CARAPACE_PROBABILITE;
    static float NAGEOIRE_PROBABILITE;

};

#endif // CONFIGURATIONS_H
