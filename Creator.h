/*
	Create a bestiole with different behavior
*/
#ifndef _CREATOR_H_
#define _CREATOR_H_

#include <memory>
#include <random>
#include "Bestiole.h"
#include "BestioleBuilder.h"

using BestiolePtr = std::shared_ptr<Bestiole>;

class Creator {

public:
	BestiolePtr createBestiole();
};

#endif