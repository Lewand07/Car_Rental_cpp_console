#pragma once
#include "Person.h"

class User : public Person{
	
public:
	User();
	User(string, string,string, string);
	~User();

	void print();
};