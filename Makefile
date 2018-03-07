CXXFLAGS = -g -Wall

main: main.o RpgPerson.o Map.o Monster.o RpgCreature.o Job.o
	g++ $(CXXFLAGS) main.o RpgPerson.o Map.o Monster.o RpgCreature.o Job.o -o main

RpgCreature.o: RpgCreature.cpp RpgCreature.h
	g++ $(CXXFLAGS) -c RpgCreature.cpp

RpgPerson.o: RpgPerson.cpp RpgPerson.h RpgCreature.h
	g++ $(CXXFLAGS) -c RpgPerson.cpp

Map.o: Map.cpp Map.h RpgPerson.h
	g++ $(CXXFLAGS) -c Map.cpp

Monster.o: Monster.cpp Monster.h RpgCreature.h
	g++ $(CXXFLAGS) -c Monster.cpp

Job.o: Job.cpp Job.h RpgPerson.h RpgCreature.h
	g++ $(CXXFLASS) -c Job.cpp

main.o: main.cpp Map.h RpgCreature.h RpgPerson.h Monster.h Job.h
	g++ $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o
