#pragma once
#include "Vehicle.h"
#include <iostream>

class Car : public Vehicle {
	static size_t number;
	const size_t VIN{};
	bool rented = false;

public:
	Car();
	Car(std::string, std::string);
	~Car() {};
	void renting();
	void print();
	bool getRented() const;
};

