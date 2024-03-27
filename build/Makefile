test_comportements : ../test/test_comportements.cpp Aquarium.o Bestiole.o Peureuse.o Kamikaze.o Prevoyante.o Gregaire.o Behavior.o Clonage.o Creator.o Milieu.o BestioleBuilder.o Camouflage.o Carapace.o Nageoire.o Yeux.o Oreilles.o ConfigReader.o Configurations.o
	g++ -Wall -std=c++17 -o test_comportements ../test/test_comportements.cpp *.o -I.. -lX11 -lpthread

main : ../main.cpp Aquarium.o Bestiole.o Peureuse.o Kamikaze.o Prevoyante.o Gregaire.o Behavior.o Clonage.o Creator.o Milieu.o BestioleBuilder.o Camouflage.o Carapace.o Nageoire.o Yeux.o Oreilles.o ConfigReader.o Configurations.o
	g++ -Wall -std=c++17 -o main ../main.cpp *.o -I.. -lX11 -lpthread

Configurations.o : ../cfg/Configurations.h ../cfg/Configurations.cpp
	g++ -Wall -std=c++17 -c ../cfg/Configurations.cpp -I..

ConfigReader.o : ../cfg/ConfigReader.h ../cfg/ConfigReader.cpp ../cfg/json.hpp ../cfg/Configurations.h
	g++ -Wall -std=c++17 -c ../cfg/ConfigReader.cpp -I..

Aquarium.o : ../Aquarium.h ../Aquarium.cpp ../CImg.h ../cfg/Configurations.h 
	g++ -Wall -std=c++17  -c ../Aquarium.cpp -I..

Bestiole.o : ../Bestiole.h ../Bestiole.cpp ../cfg/Configurations.h
	g++ -Wall -std=c++17  -c ../Bestiole.cpp -I..
	
Peureuse.o : ../comportements/Peureuse.h ../comportements/Peureuse.cpp 
	g++ -Wall -std=c++17   -c ../comportements/Peureuse.cpp -I..

Prevoyante.o : ../comportements/Prevoyante.h ../comportements/Prevoyante.cpp 
	g++ -Wall -std=c++17   -c ../comportements/Prevoyante.cpp -I..
	
Kamikaze.o : ../comportements/Kamikaze.h ../comportements/Kamikaze.cpp 
	g++ -Wall -std=c++17   -c ../comportements/Kamikaze.cpp -I..

Gregaire.o : ../comportements/Gregaire.h ../comportements/Gregaire.cpp 
	g++ -Wall -std=c++17   -c ../comportements/Gregaire.cpp -I..

Behavior.o : ../comportements/Behavior.h ../comportements/Behavior.cpp 
	g++ -Wall -std=c++17   -c ../comportements/Behavior.cpp -I..
	
Clonage.o : ../Clonage.h ../Clonage.cpp 
	g++ -Wall -std=c++17  -c ../Clonage.cpp -I..

Creator.o : ../Creator.h ../Creator.cpp 
	g++ -Wall -std=c++17  -c ../Creator.cpp -I..

Milieu.o : ../Milieu.h ../Milieu.cpp 
	g++ -Wall -std=c++17  -c ../Milieu.cpp -I..

BestioleBuilder.o: ../BestioleBuilder.cpp ../Bestiole.h ../cfg/Configurations.h ../cfg/ConfigReader.h ../accessoires/Accessoires.h ../accessoires/Camouflage.h ../accessoires/Carapace.h ../accessoires/Nageoire.h ../capteurs/Capteurs.h ../capteurs/Oreilles.h ../capteurs/Yeux.h
	g++ -Wall -std=c++17 -c ../BestioleBuilder.cpp -I..

Camouflage.o : ../accessoires/Camouflage.h ../accessoires/Camouflage.cpp ../accessoires/Accessoires.h 
	g++ -Wall -std=c++17 -c ../accessoires/Camouflage.cpp -I..

Carapace.o : ../accessoires/Carapace.h ../accessoires/Carapace.cpp ../accessoires/Accessoires.h 
	g++ -Wall -std=c++17 -c ../accessoires/Carapace.cpp -I..

Nageoire.o : ../accessoires/Nageoire.h ../accessoires/Nageoire.cpp ../accessoires/Accessoires.h 
	g++ -Wall -std=c++17 -c ../accessoires/Nageoire.cpp -I..

Yeux.o : ../capteurs/Yeux.h ../capteurs/Yeux.cpp ../capteurs/Capteurs.h 
	g++ -Wall -std=c++17 -c ../capteurs/Yeux.cpp -I..

Oreilles.o : ../capteurs/Oreilles.h ../capteurs/Oreilles.cpp ../capteurs/Capteurs.h 
	g++ -Wall -std=c++17 -c ../capteurs/Oreilles.cpp -I..

clean:
	rm -rf *.o main
