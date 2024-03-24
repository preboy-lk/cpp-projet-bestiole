#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_

#include <iostream>
#include <CImg.h>
#include <memory>
#include <chrono>
#include <thread>

#include "Milieu.h"
#include "Clonage.h"
#include "Creator.h"

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{
private :
   Milieu       * flotte;

   int            delay;

public :

   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );

   Milieu & getMilieu( void ) { return *flotte; }

   void run( void );

};


#endif
