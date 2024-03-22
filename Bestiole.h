#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include "accessoires/Accessoires.h"
#include "capteurs/Capteurs.h"
#include <vector>
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
   T               * couleur;
   std::vector<Accessoires*> accessoires;
   std::vector<Capteurs*> capteurs;
private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
   void ajouterAccessoires(Accessoires* accessoire);
   void ajouterCapteurs(Capteurs* capteur);
   void augmenterVitesse(double facteur);
   const std::vector<Accessoires*>& getAccessoires() const;
   const int getIdentite();
};


#endif
