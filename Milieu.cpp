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
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
 
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      (*it)->action( *this );
      (*it)->draw( *this );

      //changeBehavior
      (*it)->changeBehavior((*it)->getBehavior());
    
      //Collison
      for ( std::vector<Bestiole*>::iterator ito = listeBestioles.begin() ; ito != listeBestioles.end() ; ++ito )
      {
         if( ito != it ){
            bool collide = (*ito)->collision((**it));
         
            int prob = std::rand() % 100;
            if(prob <= 3 && collide){
               (*it)->setAge(1);
               cout<<"Mort par collision !" <<endl;
            }
         }
      }

      if(listeBestioles.size() > 1){
         
      //Mort naturel
         if((*it)->getAge() >= 1){ //Tant qu'il lui reste plus d'un an à vivre, l'esperance de vie diminue
            (*it)->esperanceVie();
            if((*it)->getAge() == 0) {
               delete (*it); // Bestiole meurt
               listeBestioles.erase(it);
               cout<<"Il reste " <<listeBestioles.size() <<" Bestioles dans l'aquarium\n\n" <<endl;
               break;
            }
         }      
      }

   } // for


}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;

   return nb;

}
