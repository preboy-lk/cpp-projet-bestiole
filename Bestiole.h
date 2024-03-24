#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include "Behavior.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"

#include "accessoires/Accessoires.h"
#include "capteurs/Capteurs.h"

#include <iostream>

#include <vector>
#include <memory>
#include <cstdlib>
#include <cmath>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const int        AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   double            size;

   int               ageLimite;
   bool              stillAlive = true;

   int               randBehavior; //id behavior
   Behavior        * behavior;

   std::vector<Accessoires*> accessoires;
   std::vector<Capteurs*> capteurs;
   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole(   int id_behavior, 
               int age, 
               std::vector<Accessoires*>&& accessoires,
               std::vector<Capteurs*>&& Capteurs); // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   int getId() {return identite;}

   int getIdBehavior() {return randBehavior;}
   Behavior* getBehavior(){return behavior;}
   int selectionComportement();
   void changeBehavior(Behavior* behavior);
   void setRandBehavior(int nbr){randBehavior=nbr;}

   int getAge() {return ageLimite;}
   void setAge(int age) {ageLimite = age;}

   int getVitesse() {return vitesse;}
   void setVitesse(int speed) {vitesse = speed;}

   void esperanceVie() { setAge(getAge()-1);} 
   const bool getVieStatut() const { return stillAlive;}

   bool collision( Bestiole & b );

   int getX() {return x;}
   void setCumulX(double cuX) {cumulX = cuX;}
   int getY() {return y;}

   double getOrientation() {return orientation;}
   void setOrientation(double newOrientation);

   const std::vector<Accessoires*>& getAccessoires() const;
   const std::vector<Capteurs*>& getCapteurs() const;

   const double getProtectionCapacite() ;
   const double getCamouflageCapacite() ;
   const double getOreillesDetectionCapacite() const;
   const double getYeuxDetectionCapacite() const;
   const double getVisionAngle() const;
   const double getVisionDistance() const;
   const double getAudibleDistance() const;
   const double getVitesseChangementFacteur();
   double getSize(){return size;}

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
   
};


#endif
