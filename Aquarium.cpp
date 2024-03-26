#include "Aquarium.h"



Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}


void Aquarium::run( void )
{
   std::unique_ptr<Clonage> cloneur; //Crée un cloneur
   std::unique_ptr<Creator> creator;

   cout <<  "******************************************************\n"
        <<  "*******************running Aquarium*******************\n"
        <<  "******************************************************\n" << endl;
   int frameCount = 0;
   while ( ! is_closed() )
   {
      ++frameCount;
      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }

      if (frameCount % 30 == 0) // Ralentissez le taux de natalité et clonez
      {
      //Add clone
      if(static_cast<double>( rand() )/RAND_MAX <  CLONAGE_PROBABILITE){
         flotte->addMember( cloneur->createClone(flotte->getMember()) );
      }

      //Naissance naturellement 
      if (static_cast<double>( rand() )/RAND_MAX < TAUX_NAISSANCE)
         {flotte->addMember( (creator->createBestiole()) );}
      }
      flotte->step();
      display( *flotte );
      //std::this_thread::sleep_for(std::chrono::seconds(1));
      wait( delay );

   } // while

}
