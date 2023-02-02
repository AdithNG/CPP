CXX = g++
CXXFLAGS = -Wall

proj4: Game.o Area.o Entity.o Terran.o Marine.o Ghost.o Battlecruiser.o Zerg.o Zergling.o Hydralisk.o Mutalisk.o proj4.cpp
	$(CXX) $(CXXFLAGS) Game.o Area.o Entity.o Terran.o Marine.o Ghost.o Battlecruiser.o Zerg.o Zergling.o Hydralisk.o Mutalisk.o proj4.cpp -o proj4

Game.o: Area.o Entity.o Terran.o Marine.o Ghost.o Battlecruiser.o Zerg.o Zergling.o Hydralisk.o Mutalisk.o Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Entity.o: Terran.o Marine.o Ghost.o Battlecruiser.o Zerg.o Zergling.o Hydralisk.o Mutalisk.o Entity.h Entity.cpp
	$(CXX) $(CXXFLAGS) -c Entity.cpp

Zerg.o: Zerg.h Zerg.cpp
	$(CXX) $(CXXFLAGS) -c Zerg.cpp

Zergling.o: Zergling.h Zergling.cpp Zerg.o 
	$(CXX) $(CXXFLAGS) -c Zergling.cpp

Mutalisk.o: Mutalisk.h Mutalisk.cpp Zerg.o
	$(CXX) $(CXXFLAGS) -c Mutalisk.cpp

Hydralisk.o: Hydralisk.h Hydralisk.cpp Zerg.o
	$(CXX) $(CXXFLAGS) -c Hydralisk.cpp

Terran.o: Terran.h Terran.cpp 
	$(CXX) $(CXXFLAGS) -c Terran.cpp

Marine.o: Terran.o Marine.h Marine.cpp
	$(CXX) $(CXXFLAGS) -c Marine.cpp

Ghost.o: Terran.o Ghost.h Ghost.cpp
	$(CXX) $(CXXFLAGS) -c Ghost.cpp

Battlecruiser.o: Terran.o Battlecruiser.h Battlecruiser.cpp
	$(CXX) $(CXXFLAGS) -c Battlecruiser.cpp

run1:
	./proj4 proj4_map1.txt

run2:
	./proj4 proj4_map2.txt

val1:
	valgrind ./proj4 proj4_map1.txt

val2:
	valgrind ./proj4 proj4_map2.txt

clean:
	rm *.o
	rm *~



