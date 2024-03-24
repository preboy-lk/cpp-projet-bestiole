#include "Clonage.h"

Bestiole* Clonage::createClone(Bestiole* b){
		cout<< "Bestiole " << b->getId() <<" SHADOW CLONE JUTSU !" <<endl;
		Bestiole* clone = new Bestiole((*b)); //Clonage

		int age = rand() % 1001 + 300;
		clone->setAge(age); //age different

		clone->setOrientation( static_cast<double>( rand() )/RAND_MAX *2.*M_PI ); //radian
		return clone;
	}
