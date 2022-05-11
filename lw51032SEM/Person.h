#pragma once
#include <string>
#include "Global.h"

using std::string;

class Person{
	static size_t checkNumber;
protected:
	const size_t id{};
	string firstName{};
	string lastName{};
	const string pesel{};
	string login{};
	string password{};
	bool renting{ false };
	ObjType objType;

public:
	Person();
	Person(string, string, string, string);
	Person(const Person&);
	virtual ~Person() {};

	virtual void print() = 0;

	inline ObjType get_type() { return objType; }
	void set_type(ObjType t) { objType = t; }
	__declspec(property(get = get_type, put = set_type)) ObjType type_property;

	size_t getID() const;

	string getFirstName() const;
	void setFristName(string firstName);

	string getLastName() const;
	void setLastName(string lastName);

	string getPesel() const;

	string getLogin() const;
	void setLogin(string login);

	string getPassword() const;
	void setPassword(string password);

	bool getRenting() const;
	void setRenting(bool renting);

	friend std::ostream& operator<<(std::ostream& output, Person& person);
};

std::ostream& operator<<(std::ostream& output, Person& person);
