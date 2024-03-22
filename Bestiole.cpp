#include "Bestiole.h"
#include "Milieu.h"


const int         Bestiole::AFF_SIZE = 10;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 80.;

int               Bestiole::next = 0;


Bestiole::Bestiole( int id_behavior, int age, std::vector<Accessoires*> accessoire )
{
   identite = ++next;
   vitesse = static_cast<double>( rand() )/RAND_MAX *MAX_VITESSE;
   accessoires = accessoire;
   cout << "const Bestiole (" << identite << ") par defaut " << endl;
   for ( std::vector<Accessoires*>::iterator it = accessoires.begin() ; it != accessoires.end() ; ++it )
   {
      (*it)->info();
      //vitesse *= (*it)->getFacteur(); 
   }

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX *2.*M_PI; //radian
   
   size = rand() % AFF_SIZE + 3*AFF_SIZE/4;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   //AGE
   setAge(age);

   //CREATE BESTIOLE
   randBehavior = id_behavior; //Choose randomly a behavior for the bestiole create
   if(randBehavior==1)
      behavior = new Peureuse;
   else if(randBehavior==2)
      behavior = new Gregaire;
   else if(randBehavior==3)
      behavior = new Kamikaze;
   else if(randBehavior==4)
      behavior = new Prevoyante;
   behavior->info();
   int multipleRandom = rand() % 2; //Generate a random number between 1(true) and 0(false)
   behavior->setMultiple(multipleRandom); //Set randomly multiple behavior or not.
   changeBehavior(behavior);
}


Bestiole::Bestiole( const Bestiole & b )
{
   identite = ++next;

   accessoires = b.accessoires;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   size = b.size;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

   randBehavior = b.randBehavior;
   behavior = b.behavior->clone();

   ageLimite = b.ageLimite;
}


Bestiole::~Bestiole( void )
{

   delete[] couleur;
   delete behavior;

   cout << "dest Bestiole " <<identite << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny; //new position
   double         dx = cos( orientation )*vitesse; //distance dx parcouru
   double         dy = -sin( orientation )*vitesse; //distance dy parcouru
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx; //cx => distance accumulée selon x
   cy = static_cast<int>( cumulY ); cumulY -= cy; //cy => distance accumulée selon y

   nx = x + dx + cx; //new x
   ny = y + dy + cy; //new y

   if ( (nx < 0) || (nx > xLim - 1) ) { // si la nouvelle position est aux bords gauche et droite de l'ecran 
      orientation = M_PI - orientation; // la bestiole se dirige dans la direction opposée
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx ); // On etablit la nouvelle coordonnée x de la bestiole
      cumulX += nx - x; // La distance totale parcourue avant rebond selon x
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y; // La distance totale parcourue avant rebond selon x
   }

}


void Bestiole::action( Milieu & monMilieu )
{

   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}

void Bestiole::setOrientation(double newOrientation){
      //cout<<"Before =" <<orientation <<endl; 
      orientation = newOrientation;
      //cout<<" Now =" <<orientation <<endl;
      //cumulX = cumulY = 0.;
   }

void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*size/2.1;
   double         yt = y - sin( orientation )*size/2.1;


   support.draw_ellipse( x, y, size, size/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, size/2., couleur );
   
   for (const auto& accessoire : accessoires) {
      accessoire->draw(x,y,size,orientation,support,couleur);
   }

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

bool Bestiole::collision( Bestiole & b )
{
   double         dist;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   if(dist <= size){
      if(abs(cos(orientation)) < abs(sin(orientation)) ){
         orientation = M_PI+orientation;
         b.setOrientation(M_PI+b.orientation);
      }
      return true;
   }
   return false;
}

void Bestiole::changeBehavior(Behavior* behavior)
{
   int behaviorRandom = rand() % 4 + 1;
   if(behavior->getMultiple() == true)
   {
      //cout << "Bestiole " <<identite <<" comportement multiple => " <<behavior->getMultiple() << endl;
      if(behavior->getId() != behaviorRandom && behaviorRandom == 1){ 
         behavior = new Peureuse;
      //   cout <<"nbr = " <<behaviorRandom << " Bestiole "<<identite <<" maintenant Peureuse=> " << endl;
      }
      else if(behavior->getId() != behaviorRandom && behaviorRandom == 2){ 
         behavior = new Gregaire;
      //   cout <<"nbr = " <<behaviorRandom << " Bestiole "<<identite <<" maintenant Gregaire=> " << endl;
      }
      else if(behavior->getId() != behaviorRandom && behaviorRandom == 3){ 
         behavior = new Kamikaze;
      //   cout <<"nbr = " <<behaviorRandom << " Bestiole "<<identite <<" maintenant Kamikaze=> " << endl;
      }
      else if(behavior->getId() != behaviorRandom && behaviorRandom == 4){ 
         behavior = new Prevoyante;
      //   cout <<"nbr = " <<behaviorRandom << " Bestiole "<<identite <<" maintenant Prevoyante=> " << endl;
      }
   }
}


//ACCESSOIRES
const std::vector<Accessoires*>& Bestiole::getAccessoires() const {
    return accessoires;
}

const double Bestiole::getProtectionCapacite()
{
   double protection_capacite = 0.f;
   for (const auto& accessoire : accessoires) {
      protection_capacite += accessoire->getProtectionCapacite();
   }
   return protection_capacite;
}

const double Bestiole::getCamouflageCapacite()
{
   double camouflage_capacite = 0.f;
   for (const auto& accessoire : accessoires) {
      camouflage_capacite += accessoire->getCamouflageCapacite();
   }
   return camouflage_capacite;
}
