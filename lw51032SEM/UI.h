#pragma once
#include "Global.h"
#include "User.h"
#include "CarRental.h"

class UI {
	
	bool run = true;

	void startScreen();
	void login(); // login: admin password: admin  --> adminPanel()
	void signup();
	void menu(size_t&);
	void adminPanel();
	static UI* ui;

public:
	UI();
	UI(UI& old_ui);
	~UI();
	static UI* getUI();
	UI& operator=(const UI&);
};


