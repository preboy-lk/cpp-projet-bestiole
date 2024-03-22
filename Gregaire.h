#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include <iostream>
#include "Behavior.h"

using namespace std;

class Gregaire : public Behavior
{
private:
	int id=2;
public:
	void info();
	Gregaire(void);
	Gregaire( const Gregaire & b ); 
	~Gregaire(void) ;
	Gregaire* clone() const {return new Gregaire(*this);} 
};

#endif