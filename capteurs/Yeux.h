#ifndef YEUX_H
#define YEUX_H

#include "Capteurs.h"

class Yeux : public Capteurs {
public:
    std::string getNom() const override;
};

#endif // YEUX_H
