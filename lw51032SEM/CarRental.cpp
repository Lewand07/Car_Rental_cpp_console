#include "CarRental.h"


CarRental* CarRental::carRental = CarRental::getCarRental();

CarRental::Renting::~Renting(){
	;
}

void CarRental::Renting::getRenting() {
	std::cout << "\nBegin Date: " << begin << std::endl;
	std::cout << "End Date: " << end << std::endl;
}

void CarRental::Renting::setRenting(size_t vID, size_t pID) {
	size_t day{0}, month{0}, year{0}, hour{0}, minute{0};
	bool correct = false;
	
	vehicleID = vID;
	personID = pID;
	
	begin.currentTime();
	std::cout << "Enter the date of return: " << std::endl;

	do {
		std::cout << "Day ";
		std::cin >> day;
		std::cout  << "Month ";
		std::cin >> month;
		std::cout  << "Year ";
		std::cin >> year;
		std::cout  << "Hour ";
		std::cin >> hour;
		std::cout << "Minute ";
		std::cin >> minute;

		Date* temp = new Date(day, month, year, hour, minute);
		correct = temp->isValid(begin);
		delete temp;

		if (correct == false) {
			std::cout << "ERROR: Invalid Date, Try Again!"<<std::endl;
			system("pause");
		}

	} while (!correct);

	end.set(day, month, year, hour, minute);
	
}

CarRental::CarRental(CarRental& oldCR){ 
	if (rentings.getSize() == 1) {
		rentings = oldCR.rentings;
	}
	else {
		for (size_t i = 0; i < rentings.getSize(); i++) {
			rentings[i] = oldCR.rentings[i];
		}
	}

	for (size_t i = 0; i < peopleCounter; i++) {
		addPerson(oldCR.people[i]);
	}

	for (size_t i = 0; i < vehiclesCounter; i++) {
		addVehicle(oldCR.vehicles[i]);
	}

}

CarRental::~CarRental() {
	
	
	for (size_t i = 0; i < peopleCounter; i++) {
		delete people[i];
	}
	delete[] people;
	for (size_t i = 0; i < vehiclesCounter; i++) {
		delete vehicles[i];
	}
	delete[] vehicles;

	delete carRental;
}

void CarRental::addPerson(Person* newPerson){
	push(people, peopleCounter,newPerson);

}

void CarRental::deletePerson(size_t ind) {
	pop(people, peopleCounter, ind);
}

void CarRental::ini()
{
	//TESTING  DATA

	string brands[10]{ "Honda", "Mazda", "Toyota", "Nissan", "Mitsubishi","Lexus", "Suzuki", "Acura", "Daihatsu", "Subaru" };
	string models[10]{ "Accord", "RX-7", "Supra", "370z", "Lancer Evolution","is400", "Swift", "NSX", "Cuore", "Impreza" };
	for (size_t i = 0; i < 10; i++) {
		addVehicle(new Car(brands[i], models[i]));
	}

	string brandsM[3]{"Kawasaki","Yamaha","Honda"};
	string modelsM[3]{ "Ninja","R1M","CBR" };
	string users[3]{ "a","b","c" };
	for (size_t i = 0; i < 3; i++) {
		addVehicle(new Motorcycle(brandsM[i], modelsM[i]));
		addPerson(new User(users[i], users[i], users[i], users[i]));
	}
}

void CarRental::addVehicle(Vehicle* newVehicle) {
	push(vehicles, vehiclesCounter, newVehicle);
}

void CarRental::deleteVehicle(size_t ind) {
	pop(vehicles, vehiclesCounter, ind);
}

void CarRental::rentVehicle(size_t ind){
	bool free = false;
	size_t vIND{ 0 }, vID, op;
	do {
		if (CarRental::getCarRental()->vehicles == nullptr) {
			std::cout << "ERROR: Vehicles not found1" << std::endl;
			system("pause");
		}
		else {
			CarRental::printVehicles();
		}
		std::cout << "Enter vehicle index ";
		std::cin >> vIND;
		if (vIND > vehiclesCounter) {
			std::cout << "ERROR: Wrong index! Try again!" << std::endl;
			system("pause");
		}
		else if (vehicles[vIND]->getRented() == false) {
			free = true;
		}
		else {
			std::cout << "ERROR: This vehicle is already rented! Try again!" << std::endl;
			system("pause");
		}
	} while (!free);
	vID = vehicles[vIND]->getID();
	rentings.push(*(new Renting));
	rentings[rentings.getSize()-1].setRenting(vID, ind);
	vehicles[vIND]->renting();
	people[ind]->setRenting(true);
}

void CarRental::returnVehicle(size_t ind){
	size_t op{0}, rID{0};

	for (size_t i = 0; i < rentings.getSize(); i++) {
		if (ind == rentings[i].personID) {
			rID = i;
			break;
		}
	}

	std::cout << "You're already renting. Your renting: "; 
	rentings[rID].getRenting();
	for (size_t i = 0; i < vehiclesCounter; i++) {
		if (rentings[rID].vehicleID == vehicles[i]->getID()) {
			vehicles[i]->print();
			break;
		}
	}
	std::cout << "Do you want to return it now?  1. YES\t2.NO" << std::endl;
	std::cin >> op;
	switch (op) {
	case 1:
		people[ind]->setRenting(false);
		for (size_t i = 0; i < vehiclesCounter; i++) {
			if (rentings[rID].vehicleID == vehicles[i]->getID()) {
				vehicles[i]->renting();
				break;
			}
		}
		rentings.pop(rID);
		break;
	case 2:
		break;
	default:
		std::cout << "ERROR: Wrong option!" << std::endl;
		break;
	}
}


void CarRental::printRentings()
{
	std::cout << "*************** RENTINGS ***************" << std::endl;
	if (rentings.getSize() == 1) {
		std::cout << std::endl << "IND: " << 0 << std::endl;
		std::cout << "Person id: " << rentings[0].personID << std::endl;
		std::cout << "Vehicle id: " << rentings[0].vehicleID << std::endl;
		rentings[0].getRenting();
	}
	else {
		for (size_t i = 0; i < rentings.getSize(); i++) {
			std::cout << std::endl << "IND: " << i << std::endl;
			std::cout << "Person id: " << rentings[i].personID << std::endl;
			std::cout << "Vehicle id: " << rentings[i].vehicleID << std::endl;
			rentings[i].getRenting();
		}
	}
	std::cout << "*****************************************" << std::endl;
}

void CarRental::printPeople(){
	size_t op{};
	ObjType objtype{};
	bool go = true;
	do {
		std::cout << "\t\t1. All People\n\t\t2. Users\n\t\t3. Back" << std::endl;
		std::cin >> op;
		switch (op) {
		case 1:
			objtype = ObjType::Person;
			go = false;
			break;
		case 2:
			objtype = ObjType::User;
			go = false;
			break;
		case 3:
			return;
			break;
		default:
			std::cout << "Error: Wrong option!" << std::endl;
			system("pause");
			break;
		}
	} while (go);

	print(vehicles, vehiclesCounter, objtype);
}

void CarRental::printVehicles() {
	size_t op{};
	ObjType objtype{};
	bool go = true;
	do {
		std::cout << "\t\t1. All Vehicles\n\t\t2. Cars\n\t\t3. Motorcycles\n\n\t4. Back" << std::endl;
		std::cin >> op;
		switch (op) {
		case 1:
			objtype = ObjType::Vehicle;
			go = false;
			break;
		case 2:
			objtype = ObjType::Car;
			go = false;
			break;
		case 3:
			objtype = ObjType::Motorcycle;
			go = false;

			break;
		case 4:
			return;
			break;
		default:
			std::cout << "Error: Wrong option!" << std::endl;
			system("pause");
			break;
		}
	} while (go);
	
	print(vehicles, vehiclesCounter, objtype);

}

CarRental* CarRental::getCarRental(){
	if (!carRental) {
		carRental = new CarRental;
	}
	return carRental;
}

CarRental& CarRental::operator=(const CarRental& carRental) {
	if (&carRental != this) {
		peopleCounter = carRental.peopleCounter;
		vehiclesCounter = carRental.vehiclesCounter;
		

		if (rentings.getSize() == 1) {
			rentings = carRental.rentings;
		}
		else {
			for (size_t i = 0; i < rentings.getSize(); i++) {
				rentings[i] = carRental.rentings[i];
			}
		}
		

		for (size_t i = 0; i < peopleCounter; i++) {
			delete people[i];
		}
		delete[] people;
		for (size_t i = 0; i < peopleCounter; i++) {
			addPerson(carRental.people[i]);
		}

		for (size_t i = 0; i < vehiclesCounter; i++) {
			delete vehicles[i];
		}
		delete[] vehicles;
		for (size_t i = 0; i < vehiclesCounter; i++) {
			addVehicle(carRental.vehicles[i]);
		}
	}
	return *this;
}

//void push(CarRental::Renting*& rentings, size_t& size) {
//	if (size == 0) {
//		rentings = new CarRental::Renting;
//	}
//	else if (size == 1) {
//		auto temp = new CarRental::Renting[1];
//		temp[0] = *rentings;
//		delete rentings;
//		rentings = new CarRental::Renting[size + 1];
//		rentings[0] = *temp;
//		delete[] temp;
//	}
//	else {
//		auto temp = new CarRental::Renting[size + 1];
//		for (size_t i = 0; i < size; i++) {
//			temp[i] = rentings[i];
//		}
//		delete[] rentings;
//		rentings = temp;
//	}
//}

//void push(Person**& people, size_t& size) {
//	if (size == 0) {
//		people = new Person * [size + 1];
//		size++;
//	}
//	else {
//		Person** temp = new Person * [size + 1];
//		for (size_t i = 0; i < size; i++)
//			temp[i] = people[i];
//		delete[] people;
//		people = temp;
//		size++;
//	}
//}
//
//void push(Vehicle**& vehicles, size_t& size)
//{
//	if (size == 0) {
//		vehicles = new Vehicle * [size + 1];
//		size++;
//	}
//	else {
//		Vehicle** temp = new Vehicle * [size + 1];
//		for (size_t i = 0; i < size; i++)
//			temp[i] = vehicles[i];
//		delete[] vehicles;
//		vehicles = temp;
//		size++;
//	}
//}

//void pop(CarRental::Renting*& rentings, size_t& size, const size_t ind)
//{
//	if (size < ind) {
//		std::cout << "ERROR: Wrong index!" << std::endl;
//	}
//	else {
//		if (size == 1) {
//			delete rentings;
//		}
//		else if (size > 1) {
//			auto temp = new CarRental::Renting[size - 1];
//			size_t j{ 0 };
//			for (size_t i = 0; i < size; i++) {
//				if (i != ind) {
//					temp[j] = rentings[i];
//					j++;
//				}
//			}
//			delete[] rentings;
//			rentings = temp;
//
//		}
//		size--;
//	}
//}

//void pop(Person**& people, size_t& size, const size_t ind)
//{
//	if (size < ind) {
//		std::cout << "ERROR: Wrong index!" << std::endl;
//	}
//	else {
//		Person** temp = new Person * [size - 1];
//		size_t j{ 0 };
//		for (size_t i = 0; i < size; i++) {
//			if (i != ind) {
//				temp[j] = people[i];
//				j++;
//			}
//		}
//		delete[] people;
//		people = temp;
//		size--;
//	}
//}
//
//void pop(Vehicle**& vehicles, size_t& size, const size_t ind)
//{
//	if (size < ind) {
//		std::cout << "ERROR: Wrong index!" << std::endl;
//	}
//	else {
//		auto temp = new Vehicle * [size - 1];
//		size_t j{ 0 };
//		for (size_t i = 0; i < size; i++) {
//			if (i != ind) {
//				temp[j] = vehicles[i];
//				j++;
//			}
//		}
//		delete[] vehicles;
//		vehicles = temp;
//		size--;
//	}
//}

void print(CarRental::Renting*& rentings, const size_t size)
{
	std::cout << "*************** RENTINGS ***************" << std::endl;
	if (size == 1) {
		std::cout << std::endl << "IND: " << 0 << std::endl;
		std::cout << "Person id: " << rentings->personID << std::endl;
		std::cout << "Vehicle id: " << rentings->vehicleID << std::endl;
		rentings->getRenting();
	}
	else {
		for (size_t i = 0; i < size; i++) {
			std::cout << std::endl << "IND: " << i << std::endl;
			std::cout << "Person id: " << rentings[i].personID << std::endl;
			std::cout << "Vehicle id: " << rentings[i].vehicleID << std::endl;
			rentings[i].getRenting();
		}
	}
	std::cout << "*****************************************" << std::endl;
}

void print(Person**& people, const size_t size, ObjType& objtype)
{
	if (objtype == ObjType::Person) {
		std::cout << "*************** CUSTOMERS ***************" << std::endl;
		for (size_t i = 0; i < size; i++) {
			std::cout << std::endl << "IND: " << i;
			people[i]->print();
		}
		std::cout << "*****************************************" << std::endl;
	}
	else {
		std::cout << "*************** CUSTOMERS ***************" << std::endl;
		for (size_t i = 0; i < size; i++) {
			if (people[i]->type_property == objtype) {
				std::cout << std::endl << "IND: " << i;
				people[i]->print();
			}
		}
		std::cout << "*****************************************" << std::endl;
	}
}

void print(Vehicle**& vehicles, const size_t size, ObjType& objtype)
{
	if (objtype == ObjType::Vehicle) {
		std::cout << "****************************************" << std::endl;
		for (size_t i = 0; i < size; i++) {
			std::cout << std::endl << "IND: " << i;
			vehicles[i]->print();
		}
	}
	else {
		std::cout << "****************************************" << std::endl;
		for (size_t i = 0; i < size; i++) {
			if (vehicles[i]->type_property == objtype) {
				std::cout << std::endl << "IND: " << i;
				vehicles[i]->print();
			}
		}
	}
}
