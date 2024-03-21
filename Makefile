main : main.cpp Aquarium.o Bestiole.o Peureuse.o Kamikaze.o Prevoyante.o Gregaire.o Behavior.o Creator.o Milieu.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Peureuse.o Prevoyante.o Kamikaze.o Gregaire.o Behavior.o Creator.o Milieu.o -I . -lX11 -lpthread

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
	
Creator.o : Creator.h Creator.cpp
	g++ -Wall -std=c++11  -c Creator.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

clean:
	rm -rf *.o main

