#include <string>
#include "Person.h"

using namespace std;

Person::Person() {
    fullName = "(anonymous)";
    phoneNumber = "0";
}
Person::Person(string phone, string name) {
    fullName = name;
    phoneNumber = phone;
}

Person::Person(const Person& other) {
    fullName = other.fullName;
    phoneNumber = other.phoneNumber;
}

string Person::getFullName() {
    return fullName;
}

string Person::getPhoneNumber() {
    return phoneNumber;
}
bool Person::setFullName(string name) {
	if (name == "") {
		return false;
	}
	char c = name[0];
	if (!(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return false;
	}
	fullName = name;
	return true;
}

bool Person::setPhoneNumber(string phone) {
	if (phone == "") {
		return false;
	}
	int n = phone.length();
	char c;
	bool found = false;
	for (int i = 0; i < n && found == false; i++) {
		c = phone.at(i);
		if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
			found = true;
		}
	}
	if (found) {
		return false;
	}
	phoneNumber = phone;
	return true;

}



