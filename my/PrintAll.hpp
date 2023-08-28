#include <iostream>
using namespace std;

template <typename T> void PrintAll(T &arrName, const char *sepChar = " ") {
  for (auto &arrVar : arrName) {
    cout << arrVar << sepChar;
  }
  cout << endl;
}
