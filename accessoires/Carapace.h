#ifndef CARAPACE_H
#define CARAPACE_H

#include "Accessoires.h"

class Carapace : public Accessoires {
public:
    std::string getNom() const override;
};

#endif // CARAPACE_H
