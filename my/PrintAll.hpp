#include <vector>
#define P_HEADERS
#ifdef P_HEADERS
#include <iostream>
#include <map>
#include <unordered_map>
#endif // Headers

namespace star {
template <typename T0, typename T1, typename T2>
void PrintAll(const std::unordered_map<T0, T1, T2> &mapName,
              const char *sepChar = " ") {
  for (auto &arrVar : mapName) {
    std::cout << arrVar.first << sepChar << arrVar.second << std::endl;
  }
}

template <typename T0, typename T1, typename T2>
void PrintAll(const std::map<T0, T1, T2> &mapName, const char *sepChar = " ") {
  for (auto &arrVar : mapName) {
    std::cout << arrVar.first << sepChar << arrVar.second << std::endl;
  }
}

template <typename T>
void PrintAll(const T &arrName, const char *sepChar = " ") {
  for (auto &arrVar : arrName) {
    std::cout << arrVar << sepChar;
  }
  std::cout << std::endl;
}

template <typename T>
void PrintAll(const std::vector<bool, T> &arrName, const char *sepChar = " ") {
  for (auto arrVar : arrName) {
    std::cout << arrVar << sepChar;
  }
  std::cout << std::endl;
}
} // namespace star

#undef P_HEADERS
