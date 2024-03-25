#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <cmath>

namespace Configurations {
    //Taux de naissance
    static constexpr double TAUX_NAISSANCE = 0.2f;

    // Clonage Probabilité
    static constexpr double CLONAGE_PROBABILITE = 0.2f;

    // Pourcentage de bestioles possédant un comportement dynamique particulier
    static constexpr float GREGAIRE_RATIO = 0.0f;
    static constexpr float PEUREUSE_RATIO = 0.f;
    static constexpr float KAMIKAZE_RATIO = 0.f;
    static constexpr float PREVOYANTE_RATIO = 1.f;
    static constexpr float MULTIPLE_RATIO = 0.f;

    // probabilité de décès après une collision
    static constexpr float MEURT_COLLISION_PROBABILITE = 0.01f;

    // Paramètres pour les capteurs : yeux et oreilles
    static constexpr float VISION_ANGLE_MIN = 0.0f; // radian
    static constexpr float VISION_ANGLE_MAX = M_PI/3; // radian
    static constexpr float VISION_DISTANCE_MIN = 120.0f;
    static constexpr float VISION_DISTANCE_MAX = 140.0f;
    static constexpr float VISION_DETECTION_PROBABILITE_MIN = 0.8f;
    static constexpr float VISION_DETECTION_PROBABILITE_MAX = 0.9f;
    static constexpr float AUDIBLE_DISTANCE_MIN = 60.0f;
    static constexpr float AUDIBLE_DISTANCE_MAX = 70.0f;
    static constexpr float AUDIBLE_DETECTION_PROBABILITE_MIN = 0.8f;
    static constexpr float AUDIBLE_DETECTION_PROBABILITE_MAX = 0.9f;

    // Paramètres pour les accessoires
    static constexpr float CAMOUFLAGE_CAPACITE_MIN = 0.f;
    static constexpr float CAMOUFLAGE_CAPACITE_MAX = 1.f;
    static constexpr float VITESSE_REDUCTION_COEFF = 1.2f;
    static constexpr float ACCELERATION_COEFF = 2.f;
    static constexpr float MEURT_REDUCTION_COEFF = 1.1f;

    // Probabilité que la bestiole est équipée avec accessoires et capteurs
    static constexpr float YEUX_PROBABILITE = 0.7f;
    static constexpr float OREILLES_PROBABILITE = 0.6f;
    static constexpr float CAMOUFLAGE_PROBABILITE = 0.5f;
    static constexpr float CARAPACE_PROBABILITE = 0.8f;
    static constexpr float NAGEOIRE_PROBABILITE = 0.2f;

}

#endif // CONFIGURATIONS_H
