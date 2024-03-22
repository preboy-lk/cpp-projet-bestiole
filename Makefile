main : main.cpp Aquarium.o Bestiole.o Peureuse.o Kamikaze.o Prevoyante.o Gregaire.o Behavior.o Clonage.o Creator.o Milieu.o BestioleBuilder.o Camouflage.o Carapace.o Nageoire.o Yeux.o Oreilles.o
	g++ -Wall -std=c++11 -o main main.cpp *.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp 
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .
	
Peureuse.o : Peureuse.h Peureuse.cpp
	g++ -Wall -std=c++11   -c Peureuse.cpp -I .

Prevoyante.o : Prevoyante.h Prevoyante.cpp
	g++ -Wall -std=c++11   -c Prevoyante.cpp -I .
	
Kamikaze.o : Kamikaze.h Kamikaze.cpp
	g++ -Wall -std=c++11   -c Kamikaze.cpp -I .

Gregaire.o : Gregaire.h Gregaire.cpp
	g++ -Wall -std=c++11   -c Gregaire.cpp -I .

Behavior.o : Behavior.h Behavior.cpp
	g++ -Wall -std=c++11   -c Behavior.cpp -I .
	
Clonage.o : Clonage.h Clonage.cpp
	g++ -Wall -std=c++11  -c Clonage.cpp -I .

Creator.o : Creator.h Creator.cpp
	g++ -Wall -std=c++11  -c Creator.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

BestioleBuilder.o: BestioleBuilder.cpp Aquarium.h Bestiole.h accessoires/Accessoires.h accessoires/Camouflage.h accessoires/Carapace.h accessoires/Nageoire.h capteurs/Capteurs.h capteurs/Oreilles.h capteurs/Yeux.h
	g++ -Wall -std=c++17 -c BestioleBuilder.cpp -I .

Camouflage.o : accessoires/Camouflage.h accessoires/Camouflage.cpp accessoires/Accessoires.h 
	g++ -Wall -std=c++17 -c accessoires/Camouflage.cpp -I .

Carapace.o : accessoires/Carapace.h accessoires/Carapace.cpp accessoires/Accessoires.h
	g++ -Wall -std=c++17 -c accessoires/Carapace.cpp -I .

Nageoire.o : accessoires/Nageoire.h accessoires/Nageoire.cpp accessoires/Accessoires.h
	g++ -Wall -std=c++17 -c accessoires/Nageoire.cpp -I .

Yeux.o : capteurs/Yeux.h capteurs/Yeux.cpp capteurs/Capteurs.h
	g++ -Wall -std=c++17 -c capteurs/Yeux.cpp -I .

Oreilles.o : capteurs/Oreilles.h capteurs/Oreilles.cpp capteurs/Capteurs.h
	g++ -Wall -std=c++17 -c capteurs/Oreilles.cpp -I .
clean:
	rm -rf *.o main

