#include "Clonage.h"

BestiolePtr Clonage::createClone(BestiolePtr b){
		cout<< "Bestiole (" << b->getId() <<") : SHADOW CLONE JUTSU !" <<endl;
		BestiolePtr clone = std::make_shared<Bestiole>(*b); //Clonage

		int age = rand() % 1001 + 300;
		clone->setAge(age); //age different

		clone->setOrientation( static_cast<double>( rand() )/RAND_MAX *2.*M_PI ); //radian
		return clone;
	}
