#include "User.h"

void User::print(){
    std::cout << "\nUser: " << id << std::endl;
    std::cout << "\tFirst name: " << firstName << std::endl;
    std::cout << "\tLast name: " << lastName << std::endl;
    std::cout << "\tPESEL: " << pesel << std::endl;
    std::cout << "****************************************" << std::endl;

}
User::User() {
    Person::type_property = ObjType::User;
}

User::User(string nFirstName, string nLastName, string nLogin, string nPassword) : Person(nFirstName, nLastName, nLogin, nPassword) {
    type_property = ObjType::User;
}

User::~User(){
    ;
}
