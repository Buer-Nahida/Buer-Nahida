#include <iostream>
using namespace std;

template <typename T> void PrintArray(T &arrName) {
  unsigned long long arrLenger = (sizeof arrName / sizeof arrName[0]);
  for (unsigned long long count = 0; count < arrLenger; count++)
    if (count == arrLenger - 1)
      cout << arrName[count] << endl;
    else
      cout << arrName[count] << " ";
}
