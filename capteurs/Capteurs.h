#ifndef CAPTEURS_H
#define CAPTEURS_H

#include <string>

class Capteurs {
public:
    virtual std::string getNom() const = 0;
};

#endif // CAPTEURS_H
