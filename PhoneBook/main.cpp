#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Person.h"
#include "PhoneBook.h"

using namespace std;

PhoneBook* myBook;

void readFromFile(string fname) {
    int n = 0, i;
    string name, phone, nstr;
    ifstream fin(fname.c_str());

    getline(fin, nstr);
    n = atoi(nstr.c_str());

    for (i = 0; i < n; i++) {
        getline(fin, name);
        getline(fin, phone);

        myBook->addPerson(name, phone);
    }

    fin.close();
}
int main(int argc, char** argv) {
    myBook = new PhoneBook();

    readFromFile("people.txt");

    list<Person> search;
    search = myBook->searchByName("Jo");
    cout << "Search by name containing 'Jo'" << endl;
    list<Person>::iterator it;
    for (it = search.begin(); it != search.end(); it++) {
        cout << ((Person)(*it)).getFullName() << " -- " << ((Person)(*it)).getPhoneNumber() << endl;
    }

    cout << endl;
    search = myBook->searchByPhoneNumber("23");
    cout << "Search by phone number containing '23'" << endl;
    for (it = search.begin(); it != search.end(); it++) {
        cout << ((Person)(*it)).getFullName() << " -- " << ((Person)(*it)).getPhoneNumber() << endl;
    }

    cout << endl;
    cout << "All people in my phone book:" << endl << endl;
    myBook->listAllPeople();

    return 0;
}