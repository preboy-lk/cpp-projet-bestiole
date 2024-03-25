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

   //Mort par Collision
   listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(), [](Bestiole* b) { return !b->getVieStatut(); }), listeBestioles.end());
   
   auto currentTime = std::chrono::steady_clock::now();
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
            bool avoirCollision = (*ito)->collision((**it)) ;
            if(!(*ito)->getVieStatut() && avoirCollision )
            {
               std::cout <<"Une Bestiole " << (*ito)->getId() << " est mort" << std::endl;
            }
         }
      }
      // Vitesse de fuite à ajouter
      //PEUREUSE
      if((*it)->getIdBehavior() == 1 )//La bestiole est peureuse
      {     
         int nb = nbVoisins(**it);
         double nouvelleOrientation = 0;
         if ((*it)->getEnfui() && std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastReactionTime).count() >= 500)
         {
            // Si la bestiole est actuellement en fuite et que suffisamment de temps s'est écoulé depuis la dernière réaction
            // Cette section réduit de moitié la vitesse du poisson et réinitialise l'état de fuite
            (*it)->setVitesse(((*it)->getVitesse())/2);
            (*it)->setEnfui(false);
         }
         if( nb >= 2 && std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastReactionTime).count() >= 1000){
            // S'il y a 2 bestioles ou plus à proximité
            // elle fera demi-tour, doublant sa vitesse
            std::cout<<"SAUVE QUI PEUT!" << std::endl;
            nouvelleOrientation = M_PI + (*it)->getOrientation();
            nouvelleOrientation = fmod(nouvelleOrientation, 2*M_PI);
            (*it)->setOrientation(nouvelleOrientation); // Va dans la direction opposée
            (*it)->setEnfui(true);
            (*it)->setVitesse(2*((*it)->getVitesse()));
            lastReactionTime = std::chrono::steady_clock::now();
         }


      }

      
      //GREGAIRE
      if((*it)->getIdBehavior() == 2){
         double orientation = 0;
         std::vector<Bestiole*> voisins = bestioleEnvironnante(**it); //Vecteur contenant les voisins de la bestiole it
         if (voisins.size() >= 2 && std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - gregaireTime).count() >= 100)
         {
            for ( std::vector<Bestiole*>::iterator itv = voisins.begin() ; itv != voisins.end() ; ++itv )
            {
               orientation += (*itv)->getOrientation(); // Somme les directions des bestioles voisines
            }
            (*it)->setOrientation(orientation/voisins.size()); //Moyenne les directions
            gregaireTime = std::chrono::steady_clock::now();

         }
      }
      
      //KAMIKAZE
      if((*it)->getIdBehavior() == 3){
         if (nbVoisins(**it) >= 2){
            Bestiole* bestiolePlusProche = this->getPlusProche(**it);
            if (bestiolePlusProche != nullptr)
            {
               double orientation;
               double distance = std::sqrt((bestiolePlusProche->getX() - (*it)->getX())*(bestiolePlusProche->getX() - (*it)->getX())
                                          +(bestiolePlusProche->getY() - (*it)->getY())*(bestiolePlusProche->getY() - (*it)->getY()));
               
               double cosinusOrientation = (bestiolePlusProche->getX() - (*it)->getX())/distance;
               orientation = std::acos(cosinusOrientation);
               (*it)->setOrientation(orientation);
               //std::cout<< "KAMEHAMEHAAA" << std::endl;
            }
         }
      }

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
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;
   }

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

void Milieu::addMember(Bestiole* b)
{
   std::cout<< "Bestiole " << b->getId() << "est ne naturellement" << std::endl;
   listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height);
}

Bestiole* Milieu::getPlusProche(Bestiole & b)
{
   std::vector<Bestiole*> voisins = bestioleEnvironnante(b);
   double dist = 0;
   double dist_min = b.getVisionDistance() + 1 ;// Prenez la distance la plus éloignée que la bestiole puisse percevoir
   if (voisins.size() >=1 )
   {
      Bestiole* bestiolePlusProche;
      for ( std::vector<Bestiole*>::iterator it = voisins.begin() ; it != voisins.end() ; ++it )
         {
            dist = std::sqrt( (b.getX()-(*it)->getX())*(b.getX()-(*it)->getX()) + 
                              (b.getY()-(*it)->getY())*(b.getY()-(*it)->getY()) );
         
         if (dist < dist_min)
         {  
            dist_min = dist;
            bestiolePlusProche = *it;
         }
         }
   return bestiolePlusProche;
   }
   return nullptr;
}