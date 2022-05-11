#include "Motorcycle.h"

size_t Motorcycle::number = 300;

Motorcycle::Motorcycle() : VIN{ number++ }, engine{ randomNumber(49,600)} {
	type_property = ObjType::Motorcycle;
};

Motorcycle::Motorcycle(std::string nbrand, std::string nmodel) : Vehicle(nbrand, nmodel), VIN{ number++ }, engine{ randomNumber(49,600) } {
	type_property = ObjType::Motorcycle;
}

void Motorcycle::renting() {
	if (rented == true) {
		rented = false;
	}
	else {
		rented = true;
	}
}

void Motorcycle::print() {
	std::cout << "\nMotorcycle: " << id << std::endl;
	std::cout << "\tBrand: " << brand << std::endl;
	std::cout << "\tModel: " << model << std::endl;
	std::cout << "\tEngine: " << engine << "cc" << std::endl;
	std::cout << "\tStatus: " << (rented ? "Rented" : "Free") << std::endl;
	std::cout << "****************************************" << std::endl;
}

bool Motorcycle::getRented() const {
	return rented;
}