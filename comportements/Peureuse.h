#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include <iostream>
#include "Behavior.h"

using namespace std;

class Peureuse: public Behavior
{
private:
	int id=1;
	static const int FUIR_PENDANT;
	static const double MULTIPLICATEUR_VITESSE;
	int stepsRestants;
	double vitesseOriginale;
public:
	void info();
	Peureuse() ;
	//void action(Milieu & m, Bestiole & b);
	~Peureuse(void) ;
	Peureuse( const Peureuse & b ) ;
	Peureuse* clone() const {return new Peureuse(*this);} 
};

#endif