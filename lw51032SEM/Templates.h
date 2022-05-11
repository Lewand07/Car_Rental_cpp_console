#pragma once
#include <iostream>

template<typename T>
void push(T*& t, size_t& size) {
	if (size == 0) {
		t = new T;
	}
	else if (size == 1) {
		auto temp = new T[1];
		temp[0] = *t;
		delete t;
		t = new T[size + 1];
		t[0] = *temp;
		delete[] temp;
	}
	else {
		auto temp = new T[size + 1];
		for (size_t i = 0; i < size; i++) {
			temp[i] = t[i];
		}
		delete[] t;
		t = temp;
	}
}

template<typename T>
void push(T**& t, size_t& size, T*nt) {
	if (size == 0) {
		t = new T * [size + 1];
		t[size] = nt;
		size++;
	}
	else {
		auto temp = new T * [size + 1];
		for (size_t i = 0; i < size; i++)
			temp[i] = t[i];
		temp[size] = nt;
		delete[] t;
		t = temp;
		size++;
	}
}

template<typename T>
void pop(T*& t, size_t& size, const size_t ind) {
	if (size < ind) {
		std::cout << "ERROR: Wrong index!" << std::endl;
	}
	else {
		if (size == 1) {
			delete t;
		}
		else if (size > 1) {
			auto temp = new T[size - 1];
			size_t j{ 0 };
			for (size_t i = 0; i < size; i++) {
				if (i != ind) {
					temp[j] = t[i];
					j++;
				}
			}
			delete[] t;
			t = temp;

		}
		size--;
	}
}

template<typename T>
void pop(T**& t, size_t& size, const size_t ind) {
	if (size < ind) {
		std::cout << "ERROR: Wrong index!" << std::endl;
	}
	else {
		auto temp = new T * [size - 1];
		size_t j{ 0 };
		for (size_t i = 0; i < size; i++) {
			if (i != ind) {
				temp[j] = t[i];
				j++;
			}
		}
		delete[] t;
		t = temp;
		size--;
	}
}