#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include <iostream>
#include "Behavior.h"

using namespace std;

class Peureuse: public Behavior
{
private:
	int id=1;
public:
	void info();
	Peureuse(void) ;
	~Peureuse(void) ;
	Peureuse( const Peureuse & b ) ;
	Peureuse* clone() const {return new Peureuse(*this);} 
};

#endif