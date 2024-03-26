#include "Prevoyante.h"

void Prevoyante::info()
{
	cout << " Prevoyante" << endl;
}
Prevoyante::Prevoyante(void) {}
Prevoyante::~Prevoyante(void) {
	//cout << "Destruct Prevoyante" << endl;
}
Prevoyante::Prevoyante( const Prevoyante & b ){
	setMultiple(this->getMultiple());
}