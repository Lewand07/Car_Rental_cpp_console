#include "Person.h"
size_t Person::checkNumber = 1;

Person::Person() : pesel{ randomPESEL() }, id { checkNumber++ } {
	;
}

Person::Person(string nFirstName, string nLastName, string nLogin, string nPassword) : firstName{ nFirstName }, lastName{ nLastName }, 
login{ nLogin }, password{ nPassword }, pesel{ randomPESEL() }, id{ checkNumber++ } {
	;
}

Person::Person(const Person& person) : pesel{ person.pesel }, id{ person.id } {
	firstName = person.firstName;
	lastName = person.lastName;
}

size_t Person::getID() const
{
	return id;
}

string Person::getFirstName() const{
	return firstName;
}

void Person::setFristName(string firstName){
	this->firstName = firstName;
}

string Person::getLastName() const{
	return lastName;
}

void Person::setLastName(string lastName){
	this->lastName = lastName;
}


string Person::getPesel() const{
	return pesel;
}


string Person::getLogin() const{
	return login;
}

void Person::setLogin(string login){
	this->login = login;
}


void Person::setPassword(string password){
	this->password = password;
}

string Person::getPassword() const {
	return password;
}

void Person::setRenting(bool renting) {
	this->renting = renting;
}



bool Person::getRenting() const
{
	return renting;
}

std::ostream& operator<<(std::ostream& output, Person& person){
	output << "\nID: " << person.id << std::endl
		<< "\tFirst name: " << person.firstName << std::endl
		<< "\tLast name: " << person.lastName << std::endl
		<< "\tPESEL: " << person.pesel << std::endl
		<< "****************************************" << std::endl;
	return output;
}
