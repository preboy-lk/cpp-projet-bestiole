/*
	Create a clone of the bestiole
*/

#ifndef _CLONAGE_H_
#define _CLONAGE_H_

#include "Bestiole.h"
using BestiolePtr = std::shared_ptr<Bestiole>;
class Clonage {

public:
	BestiolePtr createClone(BestiolePtr b);
};

#endif