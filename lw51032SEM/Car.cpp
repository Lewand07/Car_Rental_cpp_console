#include "Car.h"

size_t Car::number = 100;

Car::Car() : VIN{ number++ } {
	type_property = ObjType::Car ;
};

Car::Car(std::string nbrand, std::string nmodel) : Vehicle(nbrand, nmodel), VIN{ number++ } {
	type_property = ObjType::Car;
}

void Car::renting(){
	if (rented == true) {
		rented = false;
	}
	else {
		rented = true;
	}
}

void Car::print(){
	std::cout << "\nCar: " << id << std::endl;
	std::cout << "\tVIN: " << VIN << std::endl;
	std::cout << "\tBrand: " << brand << std::endl;
	std::cout << "\tModel: " << model << std::endl;
	std::cout << "\tStatus: " << (rented ? "Rented" : "Free") << std::endl;
	std::cout << "****************************************" << std::endl;
}

bool Car::getRented() const {
	return rented;
}
