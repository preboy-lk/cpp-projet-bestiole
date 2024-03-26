#include "Behavior.h"

using namespace std;


void Behavior::info(){
	cout << "Bestiole sans comportement" << endl;
}
Behavior::Behavior(void){
	setMultiple(false);
}
Behavior::Behavior( const Behavior & b ){
	setMultiple(this->getMultiple());
}
Behavior::~Behavior(void){
	//cout << "Destruct Behavior" << endl;
}
void Behavior::setMultiple(bool boolean){
	multiple = boolean;
}
bool Behavior::getMultiple(){
	return multiple;
}
int Behavior::getId(){
	return id;
}

