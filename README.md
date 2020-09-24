# AirplaneDatabase

This is a mock design for an Airplane Database using Object Oriented Programming in C++. 

The database has up to 20 functional operations,including adding, removing, and editing the following: 
Crewmembers
Planes
Flights

A flight can be created by adding a flight plan, assigning crewmembers and a plane, and ensuring that there is no
overlap with the crewmember and plane availability. The database also incorporates the Time class to maintain the
system in real time. 

Based on the type of flight (length, seats, etc.), the system will change the requirements to satisfy a safe flight
including number of crewmembers, type of plane required, etc.

The software also includes load and save functionality in case the database needs to be accessed at a later time. 

In order to run the software, ensure all files are in the same folder, enter the terminal, and follow the instructions:
1. Type make
2. Type make run
3. Type make clean (to delete the database and start a new one)




