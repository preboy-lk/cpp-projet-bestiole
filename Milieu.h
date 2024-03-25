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


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole*>   listeBestioles;
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

   void addMember( Bestiole* b );
   Bestiole* getMember();
   int nbVoisins( const Bestiole & b );
   std::vector<Bestiole*> bestioleEnvironnante(const Bestiole & b);
   Bestiole* getPlusProche(Bestiole & b);
};


#endif
