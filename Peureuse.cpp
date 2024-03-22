#include "Peureuse.h"

void Peureuse::info()
{
	cout << "Bestiole Peureuse" << endl;
}
Peureuse::Peureuse(void) {}
Peureuse::~Peureuse(void) {
	cout << "Destruct Peureuse" << endl;
}
Peureuse::Peureuse( const Peureuse & b ) {
	setMultiple(this->getMultiple());
}