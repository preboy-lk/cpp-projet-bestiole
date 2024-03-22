#ifndef _BEHAVIOR_H_
#define _BEHAVIOR_H_

#include <iostream>

using namespace std;

class Behavior
{
private:	
	int id=0;
	bool multiple;
public:
	virtual void info();
	virtual void setMultiple(bool boolean);
	virtual bool getMultiple();
	virtual int getId();
	virtual Behavior* clone() const {return new Behavior(*this);}
	Behavior(void);
	Behavior( const Behavior & b );
	virtual ~Behavior(void);
};

#endif