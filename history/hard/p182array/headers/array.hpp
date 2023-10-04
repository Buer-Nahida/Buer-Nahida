#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class Type> class Array {
public:
    Array(unsigned long long lenger) {
        this->m_Lenger = lenger;
        this->m_Array = new Type *[lenger];
    }
    Array(Array &array) {
        this->m_Array = new Type *[array.m_Lenger];
        for (unsigned long long count = 0; count < array.Num(); count++) {
            this->m_Array[count] = new Type(*array.m_Array[count]);
        }
    }
    Array &operator=(Array &array0) {
        for (unsigned long long count = 0; count < array0.Num(); count++) {
            delete this->m_Array[count];
            this->m_Array[count] = NULL;
        }
        delete this->m_Array;
        this->m_Array = NULL;
        this->m_Array = new Type *[array0.m_Lenger];
        for (unsigned long long count = 0; count < array0.Num(); count++) {
            this->m_Array[count] = new Type(*array0.m_Array[count]);
        }
        this->m_Lenger = array0.m_Lenger;
        return *this;
    }
    Type &operator[](unsigned long long index) { return *this->m_Array[index]; }
    ~Array() {
        for (unsigned long long count = 0; count < this->Num(); count++) {
            delete this->m_Array[count];
        }
        delete this->m_Array;
    }

    void Add(Type num) { this->m_Array[this->Num()] = new Type(num); }
    void Delete() {
        delete this->m_Array[this->Num() - 1];
        this->m_Array[this->Num() - 1] = NULL;
    }
    unsigned long long Lenger() { return this->m_Lenger; }
    unsigned long long Num() {
        unsigned long long count = 0;
        while (count < this->m_Lenger) {
            if (this->m_Array[count] != NULL) {
                count++;
            } else {
                return count;
            }
        }
        return count;
    }

private:
    Type **m_Array;
    unsigned long long m_Lenger;
};
