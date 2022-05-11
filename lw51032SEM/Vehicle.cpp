#include "Vehicle.h"
#include "Global.h"

size_t Vehicle::checkNumber = 1;

Vehicle::Vehicle() : id{ checkNumber++} {
	
}

Vehicle::Vehicle(std::string nBrand, std::string nModel) :  brand{ nBrand },model { nModel },  id{ checkNumber++ }{
	;
}


Vehicle::~Vehicle(){
	;
}

void Vehicle::setBrand(std::string nBrand){
	brand = nBrand;
}

std::string Vehicle::getBrand() const
{
	return brand;
}

void Vehicle::setModel(std::string nModel){
	model = nModel;
}

std::string Vehicle::getModel() const
{
	return model;
}

size_t Vehicle::getID() const {
	return id;
}
