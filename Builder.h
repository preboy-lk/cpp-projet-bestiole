#ifndef BUILDER_H
#define BUILDER_H

#include "Bestiole.h"

class Builder {
public:
    virtual void construireAccessoires(Bestiole* bestiole) const = 0;
    virtual void construireCapteurs(Bestiole* bestiole) const = 0;
    virtual ~Builder() {}
};

#endif // BUILDER_H