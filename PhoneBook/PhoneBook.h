#ifndef PHONEBOOK_H
#define	PHONEBOOK_H

#include <string>
#include <list>
#include "Person.h"
using namespace std;

class PhoneBook {
    int nr;
    list<Person> people;
public:
    PhoneBook();

    bool addPerson(string, string);
    bool addPerson(Person&);

    list<Person> searchByName(string);
    list<Person> searchByPhoneNumber(string);

    void listAllPeople();
};

#endif/* PHONEBOOK_H */
