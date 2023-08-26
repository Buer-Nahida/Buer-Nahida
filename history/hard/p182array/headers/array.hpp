#pragma once
#include <cstdlib>
#include <string>
using namespace std;

template <class Type> class Array {
public:
  Array(unsigned long long lenger) {
    this->m_Lenger = lenger;
    this->m_Array = new Type *[lenger];
  }
  template <typename T> Array(Array<T> &array) {
    this->m_Array = new T *[array.m_Lenger];
    for (unsigned long long count = 0; count < array.Num(); count++) {
      this->m_Array[count] = new T(*array.m_Array[count]);
    }
  }
  template <typename T> Array(const Array<T> &array) {
    this->m_Array = new T *[array.m_Lenger];
    for (unsigned long long count = 0; count < array.Num(); count++) {
      this->m_Array[count] = new T(*array.m_Array[count]);
    }
  }
  template <typename T> void operator=(Array<T> &array0) {
    for (unsigned long long count = 0; count < array0.Num(); count++) {
      delete this->m_Array[count];
      this->m_Array[count] = NULL;
    }
    delete this->m_Array;
    this->m_Array = NULL;
    this->m_Array = new T *[array0.m_Lenger];
    for (unsigned long long count = 0; count < array0.Num(); count++) {
      this->m_Array[count] = new T(*array0.m_Array[count]);
    }
    this->m_Lenger = array0.m_Lenger;
  }
  template <typename T> void operator=(const Array<T> &array0) {
    for (unsigned long long count = 0; count < array0.Num(); count++) {
      delete this->m_Array[count];
      this->m_Array[count] = NULL;
    }
    delete this->m_Array;
    this->m_Array = NULL;
    this->m_Array = new T *[array0.m_Lenger];
    for (unsigned long long count = 0; count < array0.Num(); count++) {
      this->m_Array[count] = new T(*array0.m_Array[count]);
    }
    this->m_Lenger = array0.m_Lenger;
  }
  Type operator[](unsigned long long index) {
    if (index >= this->Num()) {
      return random();
    }
    return *this->m_Array[index];
  }
  ~Array() {
    if (this->Num() != 0) {
      for (unsigned long long count = 0; count < this->Num(); count++) {
        delete this->m_Array[count];
      }
      delete this->m_Array;
    }
  }

  template <typename T> void Add(T num) {
    this->m_Array[this->Num()] = new T(num);
  }
  void Delete() {
    if (this->Num() != 0) {
      delete this->m_Array[this->Num() - 1];
      this->m_Array[this->Num() - 1] = NULL;
    }
  }
  unsigned long long Lenger() { return m_Lenger; }
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
