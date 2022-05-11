#pragma once
#include <iostream>
#include <random>
#include <string>


size_t randomNumber(size_t begin, size_t end);
std::string randomPESEL();

enum class ObjType {Vehicle, Car, Motorcycle, Person, User };

struct Date {

	size_t day;
	size_t month;
	size_t year;
	size_t hour;
	size_t minute;
	
	Date();
	Date(size_t, size_t, size_t, size_t, size_t);
	bool isValid(const Date);
	void currentTime();
	void set(size_t, size_t, size_t, size_t, size_t);

	friend std::ostream& operator<<(std::ostream& output, Date*& date);
	friend std::ostream& operator<<(std::ostream& output, Date& date);
	
};

std::ostream& operator<<(std::ostream& output, Date*& date);
std::ostream& operator<<(std::ostream& output, Date& date);




