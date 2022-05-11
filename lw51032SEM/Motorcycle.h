#pragma once
#include "Vehicle.h"
#include "Global.h"
#include <iostream>

class Motorcycle : public Vehicle{
	static size_t number;
	
	const size_t VIN{};
	const size_t engine{};
	bool rented = false;
public:
	Motorcycle();
	Motorcycle(std::string, std::string);
	~Motorcycle() {};

	void renting();
	void print();
	bool getRented() const;
};

