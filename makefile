runprog.exe: flights.o flight.o main.o plane.o planes.o	crewmember.o crewmembers.o pilot.o copilot.o cabin.o
	g++	-g -o runprog.exe flights.o flight.o main.o plane.o crewmember.o crewmembers.o planes.o pilot.o copilot.o cabin.o

flights.o: flights.cpp flight.h flights.h
	g++	-Wall -c flights.cpp

flight.o: flight.cpp flight.h
	g++	-Wall -c flight.cpp

main.o: crewmember.h flights.h main.cpp planes.h plane.h flight.h 
	g++	-Wall -c main.cpp

plane.o:  plane.h plane.cpp
	g++	-Wall -c plane.cpp

planes.o:  plane.h planes.h planes.cpp
	g++	-Wall -c planes.cpp

crewmember.o:  crewmember.h crewmember.cpp
	g++	-Wall -c crewmember.cpp

crewmembers.o:  crewmember.h crewmember.cpp crewmembers.cpp
	g++	-Wall -c crewmembers.cpp

pilot.o:  crewmember.h pilot.h pilot.cpp
	g++ -Wall -c pilot.cpp

copilot.o:  crewmember.h copilot.h copilot.cpp
	g++ -Wall -c copilot.cpp

cabin.o:  crewmember.h cabin.h copilot.cpp
	g++ -Wall -c cabin.cpp

clean:
	rm *.o