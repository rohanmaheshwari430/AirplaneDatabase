#include <string>

#include "crewmember.h"

using namespace std;

class cabin: public crewmember {

    public: 
        void setPosition(string p);
        string getPosition();
        void printInfo();
        cabin(string m_name, int id, string m_type, string s, string p);
        void editCabin();


    protected: 
        string position;


};