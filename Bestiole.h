#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include "comportements/Behavior.h"
#include "comportements/Gregaire.h"
#include "comportements/Peureuse.h"
#include "comportements/Kamikaze.h"
#include "comportements/Prevoyante.h"

#include "accessoires/Accessoires.h"
#include "capteurs/Capteurs.h"

#include <iostream>

#include <vector>
#include <memory>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <chrono>

using namespace std;


using AccessoiresPtr = std::shared_ptr<Accessoires>;
using CapteursPtr = std::shared_ptr<Capteurs>;

class Milieu;


class Bestiole
{
using BestiolePtr = std::shared_ptr<Bestiole>;
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
   bool              enfui = false;

   float               opacite = 1.f;

   int               randBehavior; //id behavior
   Behavior        * behavior;

   std::chrono::time_point<std::chrono::steady_clock>  lastTimeCollision = std::chrono::steady_clock::now();
   std::chrono::time_point<std::chrono::steady_clock>  lastTimeBehaviour = std::chrono::steady_clock::now();

   std::vector<AccessoiresPtr> accessoires;
   std::vector<CapteursPtr> capteurs;
   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole(   int id_behavior, 
               int age,
               float opacity,
               std::vector<AccessoiresPtr> accessoires,
               std::vector<CapteursPtr> Capteurs); // Constructeur par defaut
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
   
   bool getEnfui() {return enfui;}
   void setEnfui(bool b) {enfui = b;}

   int getX() const {return x;}
   void setCumulX(double cuX) {cumulX = cuX;}
   int getY() const {return y;}
   void setX(double _x) { x = _x;}
   void setY(double _y) { y = _y;}

   double getOrientation() {return orientation;}
   void setOrientation(double newOrientation);

   T* setColor(int id);

   const double getProtectionCapacite() ;
   const double getCamouflageCapacite() ;
   const double getOreillesDetectionCapacite() const;
   const double getYeuxDetectionCapacite() const;
   const double getVisionAngle() const;
   const double getVisionDistance() const;
   const double getAudibleDistance() const;
   const double getVitesseChangementFacteur();
   double getSize(){return size;}
   auto getLastTimeBehaviour(){return lastTimeBehaviour;};
   void updateLastTimeBehaviour();
   bool ontheway( Bestiole & b , double epsilon);

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
   
};


#endif
