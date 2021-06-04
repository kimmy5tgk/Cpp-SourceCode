#ifndef PERSON_H
#define PERSON_H

#include<string>

using namespace std;

class Person {
	string fullName;
	string phoneNumber;

public: 
	  Person(); // no parameters
	  Person(string, string);  // name and phone number as parametes
	  Person(const Person&);  // copy constructor

	  string getFullName();
	  string getPhoneNumber();
	  bool setFullName(string);
	  bool setPhoneNumber(string);

};




#endif // !PERSON_H

