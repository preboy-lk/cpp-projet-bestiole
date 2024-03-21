#include "Gregaire.h"

void Gregaire::info()
{
	cout << "Bestiole Gregaire" << endl;
}
Gregaire::Gregaire(void) {}
Gregaire::~Gregaire(void) {
	cout << "Destruct Gregaire" << endl;
}
Gregaire::Gregaire( const Gregaire & b ){
	setMultiple(this->getMultiple());
}