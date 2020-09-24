
#include <string>
#include <iostream>

#include "copilot.h"
copilot::copilot(string m_name, int id, string m_type, string s, string rcode, int fh) {

    member_name = m_name;
    memberID = id;
    memberType = m_type;
    status = s;

    ratingcode = rcode;
    coflighthours = fh;
 
}

void copilot::setRatingCode(string rc) {
    ratingcode = rc;
 }

string copilot::getRatingCode() {
    return ratingcode;
}
        
void copilot::setFlightHours(int fh) {
    coflighthours = fh;
}
        
int copilot::getFlightHours() {
    return coflighthours;
}

void copilot::printInfo() {
    
    crewmember::printInfo();

    cout << "Rating code: " << ratingcode << endl;
    cout << "Flight hours: " << coflighthours << endl;
}

void copilot::editCopilot() {


        int choice;

    cout << "enter which pilot property to edit" << endl;
    cout << "1 - name" << endl;
    cout << "2 - member id" << endl;
    cout << "3 - type" << endl;
    cout << "4 - rating code" << endl;
    cout << "5 - flight hours" << endl;
    cout << "enter choice: "; cin >> choice; cin.ignore();

    while(choice < 1 || choice > 5) {
        cout << "invalid option. try again: "; cin >> choice;
    }

    if(choice == 1) {
        string n;
        cout << "enter new name: "; getline(cin, n);
        member_name = n;

    }
    else if(choice == 2) {
        int id;
        cout << "enter new member id: "; cin >> id;
        memberID = id;

    }
    else if(choice == 3) {
        string type;
        cout << "enter new member type: "; getline(cin, type);
        memberType = type;
    }
    else if(choice == 4) {
        string rcode;
        cout << "enter new rating code: "; getline(cin, rcode);
        while(rcode.size() != 4) {
                cout << "must be 4 characters. try again: "; getline(cin, rcode);
            }
        ratingcode = rcode;

    }
    else if(choice == 5) {
        int fh;
        cout << "enter new flight hours: "; cin >> fh;
        coflighthours = fh;

    }
}