#include <string>
#include <vector>
#include <ctime>
#include "flight.h"


using namespace std;

class flights { //this class contains all functions to access each indivdual flight

    public: 
        void addFlight();
        void deleteFlight();
        void searchFlight();
        void printFlights();
        void printAFlight();
        void editFlight();
        int flightCount();
        void updateflightstatus();
        void loaddata();
        void savedata();
        void printAPlaneSchedule();
        void printAMemberSchedule();
        void deleteExpiredFlights();
        void setflightlist(vector <flight> flist);
        vector <flight> getflightlist();
       

    private: 
        vector <flight> flight_list;
        
    
};