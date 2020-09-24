    #include <string>
#include <vector>
#include <iterator>
#include "crewmember.h"

using namespace std;

class crewmembers { //this class holds all functionality for each crew member

    public:
        void addMember();
        void deleteMember();
        void searchMember();
        void findMemberToEdit();
        void printMember();
        void printAMember();
        void loaddata();
        void savedata();
        void setmembers(vector <crewmember*> m);
        vector <crewmember*> getmembers();
        //thes vectors contain the ids that will be used in range checking when creating a flight
        void setpilotID(vector <int> pID);
        vector <int> getpilotID();
        void setcopilotID(vector <int> coID);
        vector <int> getcopilotID();
        void setcabinID(vector <int> cID);
        vector <int> getcabinID();
        
        

    private:
        vector <crewmember*> members;
        vector <int> pilotID;
        vector <int> copilotID;
        vector <int> cabinID;
        int memberCount;


};