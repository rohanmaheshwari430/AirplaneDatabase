#include <string>
#include <iostream>

#include "cabin.h"

cabin::cabin(string m_name, int id, string m_type, string s, string p) {

    member_name = m_name;
    memberID = id;
    memberType = m_type;
    status = s;

    position = p;


}

void cabin::setPosition(string p) {
    position = p;

}
string cabin::getPosition() {
    return position;

}
void cabin::printInfo() {
    
    crewmember::printInfo();

    cout << "Position: " << position << endl;

}

void cabin::editCabin() {

        int choice;

    cout << "enter which pilot property to edit" << endl;
    cout << "1 - name" << endl;
    cout << "2 - member id" << endl;
    cout << "3 - type" << endl;
    cout << "4 - position" << endl;
    cout << "enter choice: "; cin >> choice; cin.ignore();

    while(choice < 1 || choice > 5) {
        cout << "invalid option. try again: "; cin >> choice; cin.ignore();
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
        string p;
        cout << "enter new rating code: "; getline(cin, p);

        position = p;

    }

}
