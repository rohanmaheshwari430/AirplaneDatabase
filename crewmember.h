#include <string>

using namespace std;

#ifndef CREWMEMBER_H
#define CREWMEMBER_H


class crewmember { //this class holds all general information for a crew member

    public: 
        crewmember(string m_name, int id, string m_type, string s);
        crewmember();
        void setName(string n);
        string getName();
        void setMemberID(int m_id);
        int getMemberID();
        void setMemberType(string m_type);
        string getMemberType();
        void editMember();
        void setStatus(string s);
        string getStatus();
        virtual void printInfo(); //this printinfo is called for the base class object
    
    protected:
        string member_name;
        int memberID;
        string memberType;
        string status;
        
};

#endif





