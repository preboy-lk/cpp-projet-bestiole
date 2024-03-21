#include "Milieu.h"

#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{
   double proba1 = 0.5; // Exemple de probabilité 1
   double proba2 = 0.7; // Exemple de probabilité 2
   // Créez un Director en lui passant les paramètres nécessaires
   Director director(proba1, proba2);
   
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      it->action( *this );
      it->draw( *this );
      director.construireBestiole(&(*it)); // Passer la probabilité au directeur

   } // for

}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}

// void Milieu::equiper()
// {
//    Director* director = new Director(0.5,0.5);
//    for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
//       director->construireBestiole(it); // Passer la probabilité au directeur
//       std::cout << it->afficher() << std::endl;

// }