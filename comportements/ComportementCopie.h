#ifndef _COMPORTEMENT_COPIE_H_
#define _COMPORTEMENT_COPIE_H_

#include "Behavior.h"

// Classe de comportement pour copier le comportement d'un autre poisson
class comportementCopie : public Behavior {
private:
    Behavior* comportement; // Référence au comportement à copier
public:
    comportementCopie(Behavior* behavior);
    void setMultiple() override;
};

#endif