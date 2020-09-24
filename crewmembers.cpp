#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <cmath>
#include <ctime>
#include <ios>
#include <iomanip>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <typeinfo>

#include "crewmembers.h"
#include "pilot.h"
#include "copilot.h"
#include "cabin.h"

using namespace std;

void crewmembers::addMember() { //reading in data and using mutators to establish the data
   
    int type;
    crewmember *temp;
    //prompting user to enter member details
    string m_name; int m_ID; string m_type; string s; string rcode; int fh; string p; int last_index;
    
    cout << "Enter 1 for pilot or 2 for copilot or 3 cabin member: ";
    cin >> type; cin.ignore();
    cout << "enter member name (first and last): "; getline(cin, m_name); 
    cout << "enter member ID: "; cin >> m_ID; cin.ignore();
    cout << "enter member type: "; getline(cin, m_type);
    cout << "enter status: "; getline(cin, s);

    if(type == 1) {
        cout << "enter rating code: "; getline(cin, rcode);

        while(rcode.size() != 5) {
            cout << "must be 5 characters. try again: "; getline(cin, rcode);
        }

        cout << "enter flight hours: "; cin >> fh;
    }
    else if(type == 2) {
         cout << "enter rating code: "; getline(cin, rcode);

        while(rcode.size() != 4) {
            cout << "must be 4 characters. try again: "; getline(cin, rcode);
        }

        cout << "enter flight hours: "; cin >> fh;
    }
    else if(type == 3) {
        cout << "enter cabin position (First Class, Business Class EconomyFront, EconomyRear, Lead): "; getline(cin, p);
    }
    //depending on type, allocating memory for that specific object 
    if (type == 1) {
        temp = new pilot(m_name, m_ID, m_type, s,rcode, fh);
        pilotID.push_back(m_ID); //also adding id to vector of ids for range checking when creating a flight
    }
    else if(type == 2) {
        temp = new copilot(m_name, m_ID, m_type, s,rcode, fh);
        copilotID.push_back(m_ID);
    }
    else if(type == 3) {
        temp = new cabin(m_name, m_ID, m_type, s, p); 
        cabinID.push_back(m_ID);
    }
    
    members.push_back(temp);
    
     //creating new element in crewmember list


}

void crewmembers::deleteMember() {
    int m_id; int i; bool memberFound = false;
    cout << "enter member id: "; cin >> m_id; 
    //searching for member and deleting if found
    for(i = 0; i < members.size(); i++) {
        if(members.at(i)->getMemberID() == m_id) {
            memberFound = true;
            break;
            
        }
    }
    if(memberFound == false) {
        cout << "member not found." << endl;
    }
    else { 
        cout << "member erased." << endl;
        members.erase(members.begin() + i);
    }

} 

void crewmembers::findMemberToEdit() {
    int m_id;  bool memberFound = false;
    cout << "enter the id of the member to edit: "; cin >> m_id; 

    for(int i = 0; i < members.size(); i++) {
        if(m_id == members.at(i)->getMemberID()) {
            memberFound = true;
        }
    }

    if(memberFound == false) {
        cout << "member not found" << endl;
        return;
    }
    else {

        vector <crewmember*>::iterator iter; 
        for(iter = members.begin(); iter != members.end(); iter++) {   //finding member to edit using iterator

            if(typeid(**iter) == typeid(pilot)) {
                
                pilot *temp = dynamic_cast<pilot*> (*iter); //upgrading iterator to access derive class functions

                temp->editPilot();  //calling the edit pilot associated with the derived class
                memberFound = true;

            }
            else if(typeid(**iter) == typeid(copilot)) {

                copilot *temp = dynamic_cast<copilot*> (*iter); 

                temp->editCopilot();
                memberFound = true;
            }
            else if(typeid(**iter) == typeid(cabin)) {

                cabin *temp = dynamic_cast<cabin*> (*iter);

                temp->editCabin();
                memberFound = true;

            }
            
        }
    }
}

void crewmembers::printMember() {
        //printing all members 
    
    
    for(int i = 0; i < members.size(); i++){   

        members.at(i)->printInfo();
        
    }   

}

void crewmembers::printAMember() {

    int m_id; int i; bool memberFound = false;
    cout << "enter the id of the member to print: "; cin >> m_id;
    //searching for member 
    for(i = 0; i < members.size(); i++) {
        if(m_id == members.at(i)->getMemberID()) {
            memberFound = true;
            break;
        }
    }
    //printing member if found
    if(memberFound == true) {
        members.at(i)->printInfo();
    }

    else if(memberFound == false) {
        cout << "member not found." << endl;
    }
    
}

void crewmembers::setmembers(vector <crewmember*> m) {
    members = m;
}

vector <crewmember*> crewmembers::getmembers() {
    return members;
}

void crewmembers::setpilotID(vector <int> pID) {
    pilotID = pID;
}

vector <int> crewmembers::getpilotID() {
    return pilotID;
}

void crewmembers::setcopilotID(vector <int> coID) {
    copilotID = coID;
}

vector <int> crewmembers::getcopilotID() {
    return copilotID;
}

void crewmembers::setcabinID(vector <int> cID) {
    cabinID = cID;
}

vector <int> crewmembers::getcabinID() {
    return cabinID;
}

void crewmembers::savedata() {

    ofstream fout;
    fout.open("crewmembers.out");

    int membercount = members.size();

    fout << membercount << endl;
    vector <crewmember*>::iterator it;
    crewmember *temp;
    for (it = members.begin(); it !=members.end(); ++it) {  //looping through each member and saving appropriate data 
        temp=*it;
        fout << temp->getName() << endl << temp->getMemberID() << endl << temp->getMemberType() << endl;
      
        if (typeid(**it) == typeid (pilot)) {
            pilot *temppilot = dynamic_cast<pilot*> (temp);
            fout << "1 " << temppilot->getRatingCode() << " " << temppilot->getFlightHours() << endl;
        }
        
       else if (typeid(**it) == typeid (copilot)) {
            copilot *tempcopilot = dynamic_cast<copilot *> (temp);
            fout << "2 " << tempcopilot->getRatingCode() << " " << tempcopilot->getFlightHours() << endl;
        }
        else if(typeid(**it) == typeid (cabin)) {
            cabin *tempcabin = dynamic_cast<cabin*>(temp);
            fout << "3 " << tempcabin->getPosition() << endl;
        }
    }
        
    fout.close();

}

void crewmembers::loaddata() { //loading data using labels to read in correct attributes for derived class type
    string m_name, m_last; int m_ID; string m_type; int membercount;
    string status, rcode, position; int flighthours;
    ifstream fin;
    int ctype;
    fin.open("crewmembers.out");

    fin >> membercount; //fin.ignore();
    crewmember *temp;
    
    for ( int i=0; i < membercount; i++)
    {
        
        fin >> m_name >> m_last >> m_ID >> m_type >> ctype;
        
        if (ctype == 1)
        {
            cout<< "pilot"<<endl;
            fin >> rcode >> flighthours;
            pilot * mymember  = new pilot(m_name +  " " + m_last, m_ID, m_type,status, rcode, flighthours);
            members.push_back(mymember);
        }
        
        else if (ctype == 2)
        {
        
            cout<< "copilot"<<endl;
            fin >> rcode >> flighthours;
            copilot * mymember  = new copilot(m_name +  " "+ m_last, m_ID, m_type, status, rcode, flighthours);
            members.push_back(mymember);
        }
        else if(ctype == 3) {

            cout<< "cabin"<<endl;
            fin >> position;
            cabin * mymember  = new cabin(m_name + " " +m_last, m_ID, m_type, status,position);
            members.push_back(mymember);
        }
    }

    fin.close();



}