#include "Milieu.h"

#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };
int etape =0;

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

BestiolePtr Milieu::getMember()
{
   int nMember = std::rand() % listeBestioles.size();
   return listeBestioles.at(nMember);
}

void Milieu::step( void )
{
   etape += 1;
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   //Mort par Collision
   listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(), [](BestiolePtr b) { return !b->getVieStatut(); }), listeBestioles.end());
   
   auto currentTime = std::chrono::steady_clock::now();
   for ( std::vector<BestiolePtr>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      (*it)->action( *this );
      (*it)->draw( *this );

      //changeBehavior
      if(etape == 50){
         etape =0;
         (*it)->changeBehavior((*it)->getBehavior());
      }
      //Collison
      for ( std::vector<BestiolePtr>::iterator ito = listeBestioles.begin() ; ito != listeBestioles.end() ; ++ito )
      {
         if( ito != it ){
            bool avoirCollision = (*ito)->collision((**it)) ;
            if(!(*ito)->getVieStatut() && avoirCollision )
            {
               cout<<"Collision entre la bestiole(" <<(*it)->getId() <<") et la bestiole(" <<(*ito)->getId() <<")" <<endl;
               cout <<"Bestiole (" << (*ito)->getId() << ") est morte de la collision\n" << std::endl;
            }
         }
      }

      //PEUREUSE
      if((*it)->getIdBehavior() == 1 )//La bestiole est peureuse
      {     
         int nb = nbVoisins(**it);
         double nouvelleOrientation = 0;
         if ((*it)->getEnfui() && std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastReactionTime).count() >= 500)
         {
            // Si la bestiole est actuellement en fuite et que suffisamment de temps s'est écoulé depuis la dernière réaction
            // Cette section réduit de moitié la vitesse de la bestiole et réinitialise l'état de fuite
            (*it)->setVitesse(((*it)->getVitesse())/2);
            (*it)->setEnfui(false);
         }
         if( nb >= 2 && std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastReactionTime).count() >= 1000){
            // S'il y a 2 bestioles ou plus à proximité
            // elle fera demi-tour, doublant sa vitesse
            std::cout<<"Bestiole (" <<(*it)->getId() <<") a PEUR et FUIT !\n" << std::endl;
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
         std::vector<BestiolePtr> voisins = bestioleEnvironnante(**it); //Vecteur contenant les voisins de la bestiole it
         if (voisins.size() >= 2 && std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - gregaireTime).count() >= 100)
         {
            for ( std::vector<BestiolePtr>::iterator itv = voisins.begin() ; itv != voisins.end() ; ++itv )
            {
               orientation += (*itv)->getOrientation(); // Somme les directions des bestioles voisines
            }
            (*it)->setOrientation(orientation/voisins.size()); //Moyenne les directions
            // Mettre à jour le timestamp de la dernière mise à jour du comportement grégaire
            // Pour éviter que les bestioles ne changent constamment de direction,
            // prévoyez une période de repos pour eux.
            gregaireTime = std::chrono::steady_clock::now();

         }
      }
      
      //KAMIKAZE
      if((*it)->getIdBehavior() == 3){
         // Identifiez la bestiole le plus proche dans le region de reconnaissance.
         // puis ajustez la direction de cette bestiole pour qu'il pointe toujours vers celui le plus proche de lui
         if (nbVoisins(**it) >= 2){
            BestiolePtr bestiolePlusProche = this->getPlusProche(**it);
            if (bestiolePlusProche != nullptr)
            {
               double orientation;

               // Calculer la distance entre 2 bestioles
               double distance = std::sqrt((bestiolePlusProche->getX() - (*it)->getX())*(bestiolePlusProche->getX() - (*it)->getX())
                                          +(bestiolePlusProche->getY() - (*it)->getY())*(bestiolePlusProche->getY() - (*it)->getY()));
               
               // Calculez l'angle créé par l'axe x et la direction dans laquelle il doit être ajusté
               // On a toujours cos(a,b) = vecteur(a)*vecteur(b)/ norme(a)*norm(b)
               // vecteur(b) = (1,0) (l'axe x)
               double cosinusOrientation = (bestiolePlusProche->getX() - (*it)->getX())/distance;
               orientation = std::acos(cosinusOrientation);
               (*it)->setOrientation(orientation);
               //std::cout<< "KAMEHAMEHAAA" << std::endl;
            }
         }
      }

      
      //PREVOYANTE
      if((*it)->getIdBehavior() == 4){
      // Étant donné la bestiole A, trouvez la bestiole le plus proche (appelé B)
      // déterminez l'orientation de B, ajustez l'orientation de A 
      // pour qu'elle soit perpendiculaire à l'orientation de B.
   
         if (nbVoisins(**it) >= 1){
            BestiolePtr bestiolePlusProche = this->getPlusProche(**it);
            if (bestiolePlusProche != nullptr && std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - (*it)->getLastTimeBehaviour()).count() >= 100)
            {
               double orientation;
               double epsilon = 0.2;
               if((*it)->ontheway(*bestiolePlusProche, epsilon))
               {
                  orientation = (static_cast<double>(std::rand())/RAND_MAX)*(M_PI-2*epsilon)+epsilon;
                  (*it)->setOrientation(orientation);
                  (*it)->updateLastTimeBehaviour();
               }
               
               //std::cout<< "PEACE" << std::endl;
            }
         }
      }
      
      
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
   for ( std::vector<BestiolePtr>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;
   }

   return nb;

}

std::vector<BestiolePtr> Milieu::bestioleEnvironnante(const Bestiole & b)
{
   std::vector<BestiolePtr>   voisins;
   for ( std::vector<BestiolePtr>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == **it) && b.jeTeVois(**it) )
         voisins.push_back(*it);
   return voisins;
}

void Milieu::addMember(BestiolePtr b)
{
   listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height);
}

BestiolePtr Milieu::getPlusProche(Bestiole & b)
{
   std::vector<BestiolePtr> voisins = bestioleEnvironnante(b);
   double dist = 0;
   double dist_min = b.getVisionDistance() + 1 ;// Prenez la distance la plus éloignée que la bestiole puisse percevoir
   if (voisins.size() >=1 )
   {
      BestiolePtr bestiolePlusProche;
      for ( std::vector<BestiolePtr>::iterator it = voisins.begin() ; it != voisins.end() ; ++it )
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