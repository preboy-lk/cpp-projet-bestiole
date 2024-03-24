#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

#include <iostream>
#include "Behavior.h"

using namespace std;

class Prevoyante : public Behavior
{
private:
	int id=4;
public:
	void info();
	Prevoyante(void);
	Prevoyante( const Prevoyante & b ); 
	~Prevoyante(void) ;
	Prevoyante* clone() const {return new Prevoyante(*this);} 
};

#endif