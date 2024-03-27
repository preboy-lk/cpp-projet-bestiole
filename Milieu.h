#ifndef _MILIEU_H_
#define _MILIEU_H_

#include <ctime>
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <memory>
#include <random>

#include "UImg.h"
#include "Bestiole.h"

using namespace std;

using BestiolePtr = std::shared_ptr<Bestiole>;

class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<BestiolePtr>   listeBestioles;
   std::chrono::time_point<std::chrono::steady_clock> lastReactionTime;
   std::chrono::time_point<std::chrono::steady_clock> speedUpTime;
   std::chrono::time_point<std::chrono::steady_clock> collisionTime;
   std::chrono::time_point<std::chrono::steady_clock> gregaireTime;
   bool enfui = false;
   double originalVitesse;
public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( BestiolePtr b );
   BestiolePtr getMember();
   int nbVoisins( const Bestiole & b );
   std::vector<BestiolePtr> bestioleEnvironnante(const Bestiole & b);
   BestiolePtr getPlusProche(Bestiole & b);
};


#endif
