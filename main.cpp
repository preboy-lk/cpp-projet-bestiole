#include "Aquarium.h"
#include "Milieu.h"
#include "Creator.h"
#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30);
   Creator* creator = new Creator;

   for ( int i = 1; i <= 5; i++ ){
      ecosysteme.getMilieu().addMember( (creator->createBestiole()) );
   }
   ecosysteme.run();


   return 0;

}
