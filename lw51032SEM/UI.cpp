#include "UI.h"

UI* UI::ui = UI::getUI();

UI::UI() {
    startScreen();
}

UI::UI(UI& old_ui) {
    run = old_ui.run;
}

UI::~UI(){
    delete ui;
}

UI* UI::getUI() {
    if (!ui) {
        ui = new UI;
    }
    return ui;
}

UI& UI::operator=(const UI& UI){
    if (&UI != this) {
        run = UI.run;
    }

    return *this;
}

void UI::startScreen() {
    using std::cout;
    using std::cin;
    using std::endl;
    size_t option = NULL;

    do {
        system("cls");
        cout << "***************CAR RENTAL***************" << endl;
        cout << "\n\t\t1. Login\n\t\t2. Sign Up\n\t\t3. Exit\n" << endl;
        cout << "****************************************" << endl;
        cin >> option;
        switch (option) {
        case 1:
            login();
            break;
        case 2:
            signup();
            break;
        case 3:
            run = false;
            break;
        default:
            cout << "ERROR: Wrong option, try again!" << endl;
            system("pause");
            break;
        }
    } while (run);

    return;
}

void UI::signup() {
    using std::cout;
    using std::cin;
    using std::endl;
    system("cls");
    
    Person* user = new User;

    if (run) {
        std::string temp;
        bool check = true;
        cout << "CREATE NEW ACCOUNT" << endl;
        while (check) {
            cout << "Username :";
            cin >> temp;
            if (CarRental::getCarRental()->people == nullptr && temp != "admin") {
                user->setLogin(temp);
                check = false;
            }
            else if (temp == "admin") {
                cout << "ERROR: Username taken, try again!" << endl;
                continue;
            }
            else if (CarRental::getCarRental()->people != nullptr) {
                bool taken = true;
                for (size_t i = 0; i < CarRental::getCarRental()->peopleCounter; i++) {
                    if (CarRental::getCarRental()->people[i]->Person::getLogin() == temp) {
                        taken = false;
                        cout << "ERROR: Username taken, try again!" << endl;
                        break;
                    }
                }
                if (taken == true) {
                    user->setLogin(temp);
                    check = false;
                }
            }
        }

        cout << "Password: ";
        cin >> temp;
        user->setPassword(temp);
        cout << "First Name : ";
        cin >> temp;
        user->Person::setFristName(temp);
        cout << "Last Name : ";
        cin >> temp;
        user->Person::setLastName(temp);
        CarRental::getCarRental()->addPerson(user);
        user = nullptr;
    }
}

void UI::login() {
    using std::cout;
    using std::cin;
    using std::endl;
    system("cls");

    if (run) {
        cout << "LOG IN" << endl;
        std::string username, password;
        size_t ind = NULL, pass = 0;
        bool usrExist = false, logged = false;
        
        cout << "Username: ";
        cin >> username;
       
        if (username == "admin") {
            while (pass < 3) {
                cout << "Password: ";
                cin >> password;
                if (password == "admin") {
                    adminPanel();
                    return;
                }
                else {
                    cout << "ERROR: Wrong password, try again!" << endl;
                    pass++;
                }
            }

        }
        if (CarRental::getCarRental()->peopleCounter > 0) {
            for (size_t i = 0; i < CarRental::getCarRental()->peopleCounter; i++) {
                if (username == CarRental::getCarRental()->people[i]->getLogin()) {
                    ind = i;
                    usrExist = true;
                    break;
                }
            }
        }
        else if (CarRental::getCarRental()->people != nullptr) {
            usrExist = (username == CarRental::getCarRental()->people[0]->getLogin());
        }

        if (usrExist == false) {
            cout << "ERROR: User not found!" << endl;
            system("pause");
            return;
        }
        else {

            while (pass < 3) {
                cout << "Password: ";
                cin >> password;
                if (password == CarRental::getCarRental()->people[ind]->getPassword()) {
                    logged = true;
                    break;
                }
                else {
                    cout << "Wrong password, try again!" << endl;
                    pass++;
                }
            }
        }
        if (logged == true) {
            menu(ind);
            return;
        }
        else {
            return;
        }
    }
}

void UI::menu(size_t& ind){
    using std::cout;
    using std::cin;
    using std::endl;

    do {
        system("cls");
        cout << "***************CAR RENTAL***************" << endl;
        cout << "\n\t\t1. Profile Data\n\t\t2. Delete Acc\n\t\t3. Rental\n\t\t4. Back\n\t\t5. Exit\n" << endl;
        cout << "****************************************" << endl;
        size_t option = NULL;
        cin >> option;
        switch (option) {
        case 1:
            CarRental::getCarRental()->people[ind]->print();
            system("pause");
            break;

        case 2:
            CarRental::getCarRental()->deletePerson(ind);
            return;
            break;
        case 3:
            if (CarRental::getCarRental()->people[ind]->getRenting() == false) {
                CarRental::getCarRental()->rentVehicle(ind);
            }
            else {
                CarRental::getCarRental()->returnVehicle(ind);
            }
            break;
        case 4:
            return;
            break;
        case 5:
            run = false;
            break;

        default:
            cout << "Error: Wrong option, try again!" << endl;
            system("pause");
            break;
        }
    } while (run);
}

void UI::adminPanel()
{
    using std::cout;
    using std::cin;
    using std::endl;
    do {
        system("cls");
        cout << "*****************ADMIN******************" << endl;
        cout << "\n\t\t1. Users list\n\t\t2. Delete User\n\t\t3. Vehicles list\n\t\t4. Add Car\n\t\t5. Add Motorcycle\n\t\t6. Delete Vehicle\n\t\t7. Rentings List\n\t\t8. Back\n\t\t9. Exit\n" << endl;
        cout << "****************************************" << endl;
        size_t option = NULL, ind = NULL, op = NULL;
        string brand, model;
        cin >> option;
        switch (option) {
        case 1:
            if (CarRental::getCarRental()->people == nullptr) {
                cout << "ERROR: Users not found!" << endl;
            }
            else {
                CarRental::getCarRental()->printPeople();
            }
            system("pause");
            break;
        case 2:
            if (CarRental::getCarRental()->people == nullptr) {
                cout << "ERROR: Users not found!" << endl;
                system("pause");
            }
            else {
                CarRental::getCarRental()->printPeople();
                cout << "Type in user's number" << endl;
                cin >> ind;
                CarRental::getCarRental()->deletePerson(ind);
            }
            break;
        case 3:
            if (CarRental::getCarRental()->vehicles == nullptr) {
                cout << "ERROR: Vehicles not found1" << endl;
                
            }
            else {
                CarRental::getCarRental()->printVehicles();
                
            }
            system("pause");
            break;
        case 4:
            cout << "Type in brand" << endl;
            cin >> brand;
            cout << "Type in model" << endl;
            cin >> model;
            CarRental::getCarRental()->addVehicle(new Car(brand,model));
            break;
        case 5:
            cout << "Type in brand" << endl;
            cin >> brand;
            cout << "Type in model" << endl;
            cin >> model;
            CarRental::getCarRental()->addVehicle(new Motorcycle(brand, model));
            break;
        case 6:
            CarRental::getCarRental()->printVehicles();
            cout << "Type in Car ID" << endl;
            cin >> ind;
            CarRental::getCarRental()->deleteVehicle(ind);
            break;
        case 7:
            if (CarRental::getCarRental()->rentings.getSize() <1) {
                cout << "ERROR: Vehicles not found1" << endl;
                system("pause");
            }
            else {
                CarRental::getCarRental()->printRentings();
                system("pause");
            }
            break;
        case 8:
            return;
            break;
        case 9:
            run = false;
            break;
        default:
            cout << "Error: Wrong option, try again!" << endl;
            system("pause");
            break;
        }
    } while (run);
}
