#pragma once
#include "Global.h"
#include <string>

class Vehicle{
	static size_t checkNumber;
protected:
	const size_t id{};
	std::string brand;
	std::string model;
	ObjType objType;
public:
	inline ObjType get_type() { return objType; }
	void set_type(ObjType t) { objType = t; }
	__declspec(property(get = get_type, put = set_type)) ObjType type_property;
	Vehicle();
	Vehicle(std::string, std::string);
	virtual ~Vehicle();
	virtual void renting() = 0;
	virtual void print() = 0;
	virtual bool getRented() const = 0;
	
	void setBrand(std::string nBrand);
	std::string getBrand() const;

	void setModel(std::string nModel);
	std::string getModel() const;

	size_t getID() const;
	
};

