#pragma once
#include <string>
#include "Templates.h"
#include "MyVector.h"
#include "Global.h"
#include "User.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include <time.h>


class CarRental
{
	friend class UI;

	class Renting {
		friend class CarRental;
		static size_t nr;
		Date begin{};
		Date end{};
		size_t rentingID{};
		size_t vehicleID{};
		size_t personID{};

	public:
		Renting() : rentingID{ nr++ } {};
		~Renting();
		size_t getPersonID() const;
		size_t getVehicleID() const;
		void getRenting();
		size_t getRentingID() const;
		void setRenting(size_t vID, size_t pID);

		friend void print(CarRental::Renting*& rentings, const size_t size);
	};
	MyVector<Renting> rentings;
	MyVector<Person*> people;
	Vehicle** vehicles{ nullptr };

	size_t rentingsCounter = 0;
	size_t peopleCounter = 0;
	size_t vehiclesCounter = 0;

	void ini(); //testing data
	static CarRental* carRental;
public:
	CarRental() { ini(); };
	CarRental(CarRental&);
	~CarRental();
	
	
	//INTERFACE
	void addPerson(Person* newPerson);
	void deletePerson(size_t ind);
	
	void addVehicle(Vehicle* newVehicle);
	void deleteVehicle(size_t ind);

	void rentVehicle(size_t ind);
	void returnVehicle(size_t ind);
	
	void printRentings();
	void printRentingsHistory(size_t ind);
	void printPeople();
	void printVehicles();
	

	//friend void push(CarRental::Renting*& rentings, size_t& size);
	//friend void pop(CarRental::Renting*& rentings, size_t& size, const size_t ind);
	friend void print(MyVector<CarRental::Renting> rentings, const size_t size);
	friend class MyVector<Renting>;
	friend void print(std::vector<size_t> history, MyVector<CarRental::Renting> rentings);

	static CarRental* getCarRental();
	CarRental& operator=(const CarRental& carRental);
};

//template
//void push(CarRental::Renting*& rentings, size_t& size);
//void push(Person**& people, size_t& size);
//void push(Vehicle**& vehicles, size_t& size);

//void pop(CarRental::Renting*& rentings, size_t& size, const size_t ind);
//void pop(Person**& people, size_t& size, const size_t ind);
//void pop(Vehicle**& vehicles, size_t& size, const size_t ind);
void print(std::vector<size_t> history, MyVector<CarRental::Renting> rentings);
void print(MyVector<CarRental::Renting> rentings, const size_t size);
void print(MyVector<Person*>people, const size_t size, ObjType& objtype);
void print(Vehicle**& vehicles, const size_t size, ObjType& objtype);
