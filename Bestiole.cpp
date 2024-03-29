#include "Bestiole.h"
#include "Milieu.h"


const int         Bestiole::AFF_SIZE = 10;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 80.;

int               Bestiole::next = 0;


Bestiole::Bestiole(  int id_behavior, 
                     int age,
                     float opacity,
                     std::vector<AccessoiresPtr> accessoiresPourEquiper,
                     std::vector<CapteursPtr> capteursPourEquiper)
{
   identite = ++next;
   vitesse = static_cast<double>( rand() )/RAND_MAX *MAX_VITESSE;
   cout << "Bestiole (" << identite << ") nait par defaut " << endl;
   accessoires = std::move(accessoiresPourEquiper);
   capteurs = std::move(capteursPourEquiper);
   for ( std::vector<AccessoiresPtr>::iterator it = accessoires.begin() ; it != accessoires.end() ; ++it )
   {
      (*it)->info();
   }
   vitesse *= this->getVitesseChangementFacteur();
   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX *2.*M_PI; //radian
   
   size = rand() % AFF_SIZE + AFF_SIZE;

   //AGE
   setAge(age);

   //Couleur par comportements
   couleur = new T[ 3 ];

   //CREATE BESTIOLE
   randBehavior = id_behavior; //Choose randomly a behavior for the bestiole create
   if(randBehavior==1){
      behavior = new Peureuse; //BLEU
      couleur = setColor(randBehavior);
   }
   else if(randBehavior==2){
      behavior = new Gregaire;
      couleur = setColor(randBehavior);
   }
   else if(randBehavior==3){
      behavior = new Kamikaze;
      couleur = setColor(randBehavior);
   }
   else if(randBehavior==4){
      behavior = new Prevoyante;
      couleur = setColor(randBehavior);
   }
   behavior->info(); cout<<"\n" <<endl;
   bool multipleRandom = false; 
   if (static_cast<float> (rand())/RAND_MAX < Configurations::MULTIPLE_RATIO)
      multipleRandom = true;
   behavior->setMultiple(multipleRandom); //Set randomly multiple behavior or not.
   changeBehavior(behavior);

   //change the color opacity according to camouflage
   opacite = opacity;
}


Bestiole::Bestiole( const Bestiole & b )
{
   identite = ++next;

   accessoires = b.accessoires;
   capteurs = b.capteurs;
   
   cout << " Bestiole (" << identite << ") nait par clonage de Bestiole(" <<b.identite <<")\n" << endl;

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

   opacite = b.opacite;
}


Bestiole::~Bestiole( void )
{

   delete[] couleur;
   delete behavior;

   cout << "RIP Bestiole(" <<identite <<")" <<endl;

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

   for (const auto& capteur : capteurs) {
       //std::cout << "Drawing accesories..." << std::endl;
       capteur->draw(xt,yt,size,orientation,support,couleur, opacite );
   }
   
   support.draw_ellipse( x, y, size, size/5., -orientation/M_PI*180., couleur, opacite );
   support.draw_circle( xt, yt, size/2., couleur, opacite );
   
   for (const auto& accessoire : accessoires) {
       //std::cout << "Drawing accesories..." << std::endl;
       accessoire->draw(x,y,size,orientation,support,couleur, opacite );
   }
}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{
   double         dist;
   double         angle;
   bool           zoneAudible, zoneVisible;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   angle = std::asin((b.y-y)/dist);

   zoneAudible =  dist < this->getAudibleDistance();
   zoneVisible =  (dist < this->getVisionDistance()) 
                  && angle > (orientation - this->getVisionAngle()/2) 
                  && angle < (orientation + this->getVisionAngle()/2);
   if (zoneAudible && static_cast<double>( rand() )/RAND_MAX < this->getOreillesDetectionCapacite())
      return true;
   else if (zoneVisible && static_cast<double>( rand() )/RAND_MAX < this->getOreillesDetectionCapacite())
      return true;
   else
      return false;
}

void Bestiole::updateLastTimeBehaviour(){
   lastTimeBehaviour = std::chrono::steady_clock::now();
}

bool Bestiole::ontheway(Bestiole & b, double epsilon)
{
   double         dist;
   double         angle;
   bool           ontheway;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   angle = std::asin((b.y-y)/dist);

   ontheway =  (dist < this->getVisionDistance()) 
                  && angle > (orientation - epsilon) 
                  && angle < (orientation + epsilon);
   if (ontheway)
      return true;
   else
      return false;
}

bool Bestiole::collision( Bestiole & b)
{
   double dist, nx, ny, p, w1x, w1y, w2x, w2y;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   double         v1x = vitesse*cos(orientation);
   double         v1y = -vitesse*sin(orientation);
   double         v2x = b.getVitesse()*cos(b.getOrientation());
   double         v2y = -b.getVitesse()*sin(b.getOrientation());
   double mortPossibilite = Configurations::MEURT_COLLISION_PROBABILITE/this->getProtectionCapacite();
   auto currentTime = std::chrono::steady_clock::now();
   double timeThresh = 250; //ms
   //std::cout << mortPossibilite << std::endl;
   if(dist < (size + b.size))
   { 
      if(std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTimeCollision).count() > timeThresh)
      {
         if (static_cast<double>(rand())/RAND_MAX < mortPossibilite) {
            stillAlive = false;
         }
         // Find the norm of the vector from the point of collision for the first creature and of the second creature
         nx = (b.x - x)/dist;
         ny = (b.y - y)/dist;
         // Calculate the p-value that takes into account the velocity of both creatures, to simplify, take m1 = m2 = 1
         p = nx*v1x + ny*v1y - (nx*v2x + ny*v2y);
         // Calculate new velocity vectors
         w1x = v1x - p*nx;
         w1y = v1y - p*ny;
         w2x = v2x + p*nx;
         w2y = v2y + p*ny;

         orientation = atan(-w1y/w1x);
         //vitesse = w1x/cos(orientation);

         b.setOrientation(M_PI + atan(-w2y/w2x));
         //b.setSpeed(w2x/cos(b.getOrientation()));

         //Update last time collision
         lastTimeCollision = std::chrono::steady_clock::now();

         return true;
      }
   }
   return false;
}


int Bestiole::selectionComportement()
{
   /*
   Fonction pour sélectionner un comportement pour une bestiole en fonction de ratios prédéfinis
   Renvoie un entier représentant le type de comportement sélectionné
   */
	std::vector<int> values = {1, 2, 3, 4};
	float pourcentageTotalSansPersonalitesMultiples = 1. - Configurations::MULTIPLE_RATIO;
   float tauxPeureuse = Configurations::PEUREUSE_RATIO/pourcentageTotalSansPersonalitesMultiples;
	float tauxGregaire = Configurations::GREGAIRE_RATIO/pourcentageTotalSansPersonalitesMultiples;
	float tauxKamikaze = Configurations::KAMIKAZE_RATIO/pourcentageTotalSansPersonalitesMultiples;
	float tauxPrevoyante = Configurations::PREVOYANTE_RATIO/pourcentageTotalSansPersonalitesMultiples;
	
	std::vector<float> probabilities = {tauxPeureuse, tauxGregaire, tauxKamikaze, tauxPrevoyante};

	// Generate a random probability
	double randNum = static_cast<float>(rand()) / RAND_MAX;

	// Determine the random variable based on probabilities
	double cumulativeProbability = 0.0;
	for (size_t i = 0; i < probabilities.size(); ++i) 
	{
		cumulativeProbability += probabilities[i];
		if (randNum < cumulativeProbability) {
         //std::cout << "Create type " << values[i] << std::endl;
			return values[i];
		}
	}
}

void Bestiole::changeBehavior(Behavior* behavior)
{
   int behaviorRandom = this->selectionComportement();
   if(behavior->getMultiple() == true)
   {
      cout << "Bestiole (" <<identite <<") est" ; behavior->info();
      if(behavior->getId() != behaviorRandom && behaviorRandom == 1){ 
         behavior = new Peureuse; //BLEU
         couleur = setColor(behaviorRandom);
         cout <<" Bestiole ("<<identite <<") maintenant Peureuse\n" << endl;
      }
      else if(behavior->getId() != behaviorRandom && behaviorRandom == 2){ 
         behavior = new Gregaire; //VERT
         couleur = setColor(behaviorRandom);
         cout <<" Bestiole ("<<identite <<") maintenant Gregaire\n" << endl;
      }
      else if(behavior->getId() != behaviorRandom && behaviorRandom == 3){ 
         behavior = new Kamikaze; //ROUGE
         couleur = setColor(behaviorRandom);
         cout <<" Bestiole ("<<identite <<") maintenant Kamikaze\n" << endl;
      }
      else if(behavior->getId() != behaviorRandom && behaviorRandom == 4){ 
         behavior = new Prevoyante; //VIOLET
         couleur = setColor(behaviorRandom);
         cout <<" Bestiole ("<<identite <<") maintenant Prevoyante\n" << endl;
      }
   }
}

T* Bestiole::setColor(int id)
{
   T* color = new T[3];
   if (id ==1 )
   {
      color[ 0 ] = 230. ;
      color[ 1 ] = 0.   ;
      color[ 2 ] = 0.   ;
   }
   else if (id == 2)
   {
      color[ 0 ] = 0. ;
      color[ 1 ] = 0.   ;
      color[ 2 ] = 230.   ;
   }
   else if (id == 3 )
   {
      color[ 0 ] = 0. ;
      color[ 1 ] = 230.   ;
      color[ 2 ] = 0.   ;
   }

   else if (id == 4 )
   {
      color[ 0 ] = 230. ;
      color[ 1 ] = 0.   ;
      color[ 2 ] = 230.   ;
   }
   return color;
}

const double Bestiole::getProtectionCapacite()
{
   double protection_capacite = 1.f;
   for (const auto& accessoire : accessoires) {
      protection_capacite *= accessoire->getProtectionCapacite();
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

const double Bestiole::getOreillesDetectionCapacite() const
{
   double oreilles_capacite = 0.f;
   for (const auto& capteur : capteurs) {
      oreilles_capacite += capteur->getOreillesDetectionCapacite();
   }
   return oreilles_capacite;
}
const double Bestiole::getYeuxDetectionCapacite() const
{
   double yeux_capacite = 0.f;
   for (const auto& capteur : capteurs) {
      yeux_capacite += capteur->getYeuxDetectionCapacite();
   }
   return yeux_capacite;
}

const double Bestiole::getVisionAngle() const
{
   double vision_angle = 0.f;
   for (const auto& capteur : capteurs) {
      if (capteur->getVisionAngle() > vision_angle){
         vision_angle= capteur->getVisionAngle();}
   }
   return vision_angle;
}

const double Bestiole::getVisionDistance() const
{
   double vision_distance = 0.f;
   for (const auto& capteur : capteurs) {
      if (capteur->getVisionDistance() > vision_distance){
         vision_distance= capteur->getVisionDistance();}
   }
   return vision_distance;
}

const double Bestiole::getAudibleDistance() const
{
   double audio_distance = 0.f;
   for (const auto& capteur : capteurs) {
      if (capteur->getAudibleDistance() > audio_distance){
         audio_distance= capteur->getAudibleDistance();}
   }
   return audio_distance;}

const double Bestiole::getVitesseChangementFacteur()
{
   double facteur = 1.f;
   for (const auto& accessoire : accessoires) {
      facteur *= accessoire->getFacteur();
   }
   return facteur;
}
