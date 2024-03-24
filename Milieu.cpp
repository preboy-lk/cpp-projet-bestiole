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

Bestiole* Milieu::getMember()
{
   int nMember = std::rand() % listeBestioles.size();
   return listeBestioles.at(nMember);
}

void Milieu::step( void )
{
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(), [](Bestiole* b) { return !b->getVieStatut(); }), listeBestioles.end());
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
            (*ito)->collision((**it)) ;
            int prob = std::rand() % 100;
            if(!(*ito)->getVieStatut() && (*ito)->collision((**it))){
               std::cout <<"Une Bestiole " << (*ito)->getId() << " est mort" << std::endl;
            }
         }
      }

      /* Vitesse de fuite à ajouter
      //PEUREUSE
      if((*it)->getIdBehavior() == 1){ //La bestiole est peureuse
         if( nbVoisins(**it) >= 2){
            cout<<"SAUVE QUI PEUT !" <<endl;
            (*it)->setOrientation(M_PI +(*it)->getOrientation()); // Va dans la direction opposée
         }
      }
      */

      /*
      //GREGAIRE
      if((*it)->getIdBehavior() == 2){
         std::vector<Bestiole*> voisins = bestioleEnvironnante(**it); //Vecteur contenant les voisins de la bestiole it
         for ( std::vector<Bestiole*>::iterator itv = voisins.begin() ; itv != voisins.end() ; ++itv ){
            (*it)->setOrientation( ((*it)->getOrientation() + (*itv)->getOrientation()) ); // Somme les directions des bestioles voisines
            (*it)->setOrientation( (*it)->getOrientation() / nbVoisins(**it)); //Moyenne les directions
         }
      }
      */
      /*
      //KAMIKAZE
      if((*it)->getIdBehavior() == 3 && nbVoisins(**it) >= 1){
         std::vector<Bestiole*> voisins = bestioleEnvironnante(**it); //Vecteur contenant les voisins de la bestiole it
         double         dist = std::sqrt( ((*it)->getX()-(*voisins.begin())->getX())*((*it)->getX()-(*voisins.begin())->getX()) + 
                                          ((*it)->getY()-(*voisins.begin())->getY())*((*it)->getY()-(*voisins.begin())->getY()) );
         
         for ( std::vector<Bestiole*>::iterator itv = voisins.begin() ; itv != voisins.end() ; ++itv ){
           double dist1 = std::sqrt( ((*it)->getX()-(*itv)->getX())*((*it)->getX()-(*itv)->getX()) + 
                                     ((*it)->getY()-(*itv)->getY())*((*it)->getY()-(*itv)->getY()) );
              
            if(dist >= dist1){
               dist = dist1;
               (*it)->setOrientation( M_PI/2 + (*itv)->getOrientation() ); //le bestiole sera perpandiculaire à la plus proche

            }
         }
      }
      */
      /*
      //PREVOYANTE
      if((*it)->getIdBehavior() == 4){
         std::vector<Bestiole*> voisins = bestioleEnvironnante(**it); //Vecteur contenant les voisins de la bestiole it
         for ( std::vector<Bestiole*>::iterator itv = voisins.begin() ; itv != voisins.end() ; ++itv ){
            (*it)->setOrientation( ((*it)->getOrientation() + (*itv)->getOrientation()) ); // Somme les directions des bestioles voisines
            (*it)->setOrientation( M_PI + (*it)->getOrientation() / nbVoisins(**it)); // Va dans la direction opposée à la moyenne
         }
      }
      */
      
      // //Mort naturel
      // if(listeBestioles.size() > 1){   // Il y'a au moins une bestiole deans l'aquarium
      //    if((*it)->getAge() >= 1){ //Tant qu'il lui reste plus d'un an à vivre, l'esperance de vie diminue
      //       (*it)->esperanceVie(); //vie diminue d'1
      //       if((*it)->getAge() == 0) { //Si vie à 0
      //          delete (*it); // Bestiole meurt
      //          listeBestioles.erase(it); //Libere case memoire vector
      //          cout<<"Il reste " <<listeBestioles.size() <<" Bestioles dans l'aquarium\n\n" <<endl;
      //          break;
      //       }
      //    }      
      // }
      
   } // for
}

int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it ){
      b.jeTeVois(**it);
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;}

   return nb;

}

std::vector<Bestiole*> Milieu::bestioleEnvironnante(const Bestiole & b)
{
   std::vector<Bestiole*>   voisins;
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == **it) && b.jeTeVois(**it) )
         voisins.push_back(*it);
   return voisins;
}