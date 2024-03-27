#include "Aquarium.h"
#include "Milieu.h"
#include "Creator.h"
#include <iostream>
#include <cfg/ConfigReader.h>

using namespace std;


int main()
{
   std::string fileName = "../cfg/config.json";
   
   if(!std::filesystem::exists(fileName)){
      std::cout << "Le fichier spécifié \"" << fileName << "\" est introuvable" << std::endl;
      return 1;
   }
   ConfigReader config(fileName);
   config.setGlobalConfig();
   Aquarium       ecosysteme( 640, 480, 30);
   Creator* creator = new Creator;

   for ( int i = 1; i <= 5; i++ ){
      ecosysteme.getMilieu().addMember( (creator->createBestiole()) );
   }

   ecosysteme.run();


   return 0;

}
