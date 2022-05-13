#pragma once
#include <iostream>

template<typename T>
class MyVector {
	T* tVector{nullptr};
	size_t size{0};
public:
    MyVector(size_t size=0);
	MyVector(const T& rVector) = delete;
    ~MyVector();
	void push(T t);
    void pop();
	void pop(size_t ind);
	size_t getSize() const;
	T& operator[](size_t ind) const;
	friend std::ostream& operator<<(std::ostream& output, const MyVector<T>& rVector);
};

template<typename T>
MyVector<T>::MyVector(size_t size) : size{ size }, tVector{ nullptr } { }

template<typename T>
MyVector<T>::~MyVector() {
    if (!this) {
        delete[] tVector;
        tVector = nullptr;
        size = 0;
    }
}


template<typename T>
void MyVector<T>::push(T t)
{
    if (size == 0) {
        tVector = new T[size + 1];
        tVector[size] = t;
        size++;
    }
    else {
        auto temp = new T[size + 1];
        for (size_t i = 0; i < size; ++i)
            temp[i] = tVector[i];
        temp[size] = t;
        delete[] tVector;
        tVector = temp;
        size++;
    }
}

template<typename T>
void MyVector<T>::pop() {
    if (size > 1) {
        auto temp = new T[size - 1];
        for (size_t i = 0; i < size - 1; i++)
            temp[i] = tVector[i];
        delete[] tVector;
        tVector = temp;
        size--;
    }
    else
        if (size == 1) {
            delete[] tVector;
            size = 0;
        }
        else
            std::cout << "ERROR: Vector is empty! " << std::endl;
}

template<typename T>
void MyVector<T>::pop(size_t ind) {
    if (ind < size) {
        auto temp = new T[size - 1];
        size_t j{0};
        for (size_t i = 0; i < size; i++)
            if (i != ind) {
                temp[j] = tVector[i];
                j++;
            }
        delete[] tVector;
        tVector = temp;
        size--;
    }
    else
        std::cout << "ERROR: Wrong Index! " << std::endl;
}

template<typename T>
size_t MyVector<T>::getSize() const {
    return size; 
}

template<typename T>
T& MyVector<T>::operator[](size_t ind) const {
    return tVector[ind]; 
}

template<typename T>
std::ostream& operator<<(std::ostream& output, const MyVector<T>& rVector)
{
    for (size_t i = 0; i < rVector.size; i++)
        output << rVector.tVector[i] << std::endl;
    return output;
}