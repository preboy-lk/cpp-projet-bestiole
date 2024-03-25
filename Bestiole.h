#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include "Behavior.h"
#include "Peureuse.h"
#include "Gregaire.h"

#include <iostream>

#include <cstdlib>
#include <cmath>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   int               ageLimite;

   int               randBehavior;
   Behavior        * behavior;

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( int id_behavior, int age );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   Behavior* getBehavior(){return behavior;};

   void changeBehavior(Behavior* behavior);

   void setRandBehavior(int nbr){randBehavior=nbr;};

   int getAge() {return ageLimite;};

   void setAge(int age) {ageLimite = age;};

   void esperanceVie() { setAge(getAge()-1);} ;

   bool collision( Bestiole & b );

   int getX() {return x;};

   void setCumulX(double cuX) {cumulX = cuX;};

   int getY() {return y;};

   double getOrientation() {return orientation;};

   double getSpeed() {return vitesse;};

   void setSpeed(double newSpeed);

   void setOrientation(double newOrientation);

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
