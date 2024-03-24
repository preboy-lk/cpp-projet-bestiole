#include "ComportementCopie.h"

comportementCopie::comportementCopie(Behavior* behavior) :  comportement(behavior) {}  
void comportementCopie::action() {
    if (comportement)
        {comportement->action();} // Delegate to the behavior being copied
    }