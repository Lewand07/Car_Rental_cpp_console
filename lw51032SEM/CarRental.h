#pragma once
#include <string>
#include "Global.h"
#include "User.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include <time.h>

class CarRental
{
	friend class UI;

	class Renting{
		friend class CarRental;
		
		Date begin{};
		Date end{};
		size_t vehicleID{};
		size_t personID{};

	public:
		~Renting();
		void getRenting();
		void setRenting(size_t vID, size_t pID);
		//Renting& operator=(const Renting& renting);

		friend void print(CarRental::Renting*& rentings, const size_t size);
	};
	
	Renting* rentings{ nullptr };
	Person** people{ nullptr };
	Vehicle** vehicles{ nullptr };

	size_t rentingsCounter = 0;
	size_t peopleCounter = 0;
	size_t vehiclesCounter = 0;

	static CarRental* carRental;
public:
	CarRental() { ini(); };
	CarRental(CarRental&);
	~CarRental();

	void addPerson(Person* newPerson);
	void deletePerson(size_t ind);
	
	void ini(); //testing data
	void addVehicle(Vehicle* newVehicle);
	void deleteVehicle(size_t ind);

	void rentVehicle(size_t ind);
	void returnVehicle(size_t ind);
	
	void printRentings();
	void printPeople();
	void printVehicles();
	

	friend void push(CarRental::Renting*& rentings, size_t& size);
	friend void pop(CarRental::Renting*& rentings, size_t& size, const size_t ind);
	friend void print(CarRental::Renting*& rentings, const size_t size);

	static CarRental* getCarRental();
	CarRental& operator=(const CarRental& carRental);
};

void push(CarRental::Renting*& rentings, size_t& size);
void push(Person**& people, size_t& size);
void push(Vehicle**& vehicles, size_t& size);

void pop(CarRental::Renting*& rentings, size_t& size, const size_t ind);
void pop(Person**& people, size_t& size, const size_t ind);
void pop(Vehicle**& vehicles, size_t& size, const size_t ind);

void print(CarRental::Renting*& rentings, const size_t size);
void print(Person**& people, const size_t size, ObjType& objtype);
void print(Vehicle**& vehicles, const size_t size, ObjType& objtype);
