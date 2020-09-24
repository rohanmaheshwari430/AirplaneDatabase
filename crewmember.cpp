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

#include "crewmember.h"

using namespace std;

crewmember::crewmember(string m_name, int id, string m_type, string s) {

member_name = m_name;
memberID = id;
memberType = m_type;
status = s;

}

crewmember::crewmember() {
    member_name = " ";
    memberID = 0;
    memberType = " ";
    status = " ";
}

void crewmember::editMember() {

    int userChoice; string name, membertype;
    
    // prompting user for member property to edit
    cout << "What property would you like to edit?" << endl;
    cout << "1 - member name" << endl;
    cout << "2 - member type (cabin or pilot)" << endl;
    cout << "Enter option: "; cin >> userChoice;

    //range checking for proper input
    while(userChoice != 1 && userChoice != 2) {
        cout << "Invalid option. Try again." << endl;
        cin >> userChoice;
    }
    
    //prompting for desired property to edit
    if(userChoice == 1) {
        cin.ignore(); cout << "Enter new member name: "; getline(cin, name);
        member_name = name;
    }
    else if(userChoice == 2) {
        cin.ignore(); cout << "Enter new member type: "; getline(cin, membertype);
        memberType = membertype;
    }
    
}

void crewmember::setName(string n) {
    member_name = n;
}

string crewmember::getName() {
    return member_name;
}

void crewmember::setMemberType(string m_type) {
    memberType = m_type;
}

string crewmember::getMemberType() {
    return memberType;
}

void crewmember::setMemberID(int m_id) {
    memberID = m_id;
}

int crewmember::getMemberID() {
    return memberID;
}

void crewmember::printInfo() {

    cout << "Name: " << member_name << endl;
    cout << "Member ID:" << memberID << endl;
    cout << "Member Type: " << memberType << endl;
    

}














