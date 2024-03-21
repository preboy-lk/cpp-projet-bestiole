main : main.cpp Aquarium.o Bestiole.o Milieu.o Director.o Builder.o BestioleBuilder.o Accessoires.o Capteurs.o Camouflage.o Carapace.o Nageoires.o Yeux.o Oreilles.o 
	g++ -Wall -std=c++11 -o main main.cpp *.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp accessoires/Accessoires.h capteurs/Capteurs.h
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp Bestiole.h Builder.h Director.h
	g++ -Wall -std=c++17  -c Milieu.cpp -I .

Director.o: Director.cpp Builder.h Bestiole.h BestioleBuilder.h
	g++ -Wall -std=c++17 -c Director.cpp -I .

Builder.o: Builder.h Bestiole.h
	g++ -Wall -std=c++17 -c Builder.h -I .

BestioleBuilder.o: BestioleBuilder.cpp Bestiole.h Builder.h accessoires/Accessoires.h accessoires/Camouflage.h accessoires/Carapace.h accessoires/Nageoire.h capteurs/Capteurs.h capteurs/Oreilles.h capteurs/Yeux.h
	g++ -Wall -std=c++17 -c BestioleBuilder.cpp -I .

Accessoires.o : accessoires/Accessoires.h accessoires/Accessoires.cpp
	g++ -Wall -std=c++17 -c accessoires/Accessoires.cpp -I .

Capteurs.o : capteurs/Capteurs.h capteurs/Capteurs.cpp
	g++ -Wall -std=c++17 -c capteurs/Capteurs.cpp -I .

Camouflage.o : accessoires/Camouflage.h accessoires/Camouflage.cpp accessoires/Accessoires.h
	g++ -Wall -std=c++17 -c accessoires/Camouflage.cpp -I .

Carapace.o : accessoires/Carapace.h accessoires/Carapace.cpp accessoires/Accessoires.h
	g++ -Wall -std=c++17 -c accessoires/Carapace.cpp -I .

Nageoires.o : accessoires/Nageoire.h accessoires/Nageoire.cpp accessoires/Accessoires.h
	g++ -Wall -std=c++17 -c accessoires/Nageoire.cpp -I .

Yeux.o : capteurs/Yeux.h capteurs/Yeux.cpp capteurs/Capteurs.h
	g++ -Wall -std=c++17 -c capteurs/Yeux.cpp -I .

Oreilles.o : capteurs/Oreilles.h capteurs/Oreilles.cpp capteurs/Capteurs.h
	g++ -Wall -std=c++17 -c capteurs/Oreilles.cpp -I .

clean:
	rm -rf *.o main

