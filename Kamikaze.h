#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include <iostream>
#include "Behavior.h"

using namespace std;

class Kamikaze : public Behavior
{
private:
	int id=3;
public:
	void info();
	Kamikaze(void);
	Kamikaze( const Kamikaze & b ); 
	~Kamikaze(void) ;
	Kamikaze* clone() const {return new Kamikaze(*this);} 
};

#endif