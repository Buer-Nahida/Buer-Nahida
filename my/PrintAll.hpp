#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

template <typename T0, typename T1, typename T2>
void PrintAll(const unordered_map<T0, T1, T2> &mapName,
              const char *sepChar = " ") {
  for (auto &arrVar : mapName) {
    cout << arrVar.first << sepChar << arrVar.second << endl;
  }
}

template <typename T0, typename T1, typename T2>
void PrintAll(const map<T0, T1, T2> &mapName, const char *sepChar = " ") {
  for (auto &arrVar : mapName) {
    cout << arrVar.first << sepChar << arrVar.second << endl;
  }
}

template <typename T>
void PrintAll(const T &arrName, const char *sepChar = " ") {
  for (auto &arrVar : arrName) {
    cout << arrVar << sepChar;
  }
  cout << endl;
}
