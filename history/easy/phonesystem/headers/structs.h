#include "headers.h"
#define MAX 1000

struct Person {
  string Name;
  int Sex;
  int Age;
  string PhoneNum;
  string Addr;
};

struct Addressbooks {
  Person personArr[MAX];
  int Size;
};
