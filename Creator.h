/*
	Create a bestiole with different behavior
*/
#ifndef _CREATOR_H_
#define _CREATOR_H_

#include<memory>
#include "Bestiole.h"
#include "BestioleBuilder.h"

class Creator {

public:
	Bestiole* createBestiole();
};

#endif