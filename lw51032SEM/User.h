#pragma once
#include "Person.h"
#include <vector>

class User : public Person{
	
	std::vector<size_t> history;

public:
	User();
	User(string, string,string, string);
	~User();

	std::vector<size_t> getHistory() const;
	void rent(size_t rID);
	void print();
};