#define P_HEADERS
#ifdef P_HEADERS
#include <iostream>
#include <map>
#include <unordered_map>
#endif // Headers

namespace star {
template <typename UnMapKey1, typename UnMapKey2, typename UnMapKey3>
void PrintAll(
    const std::unordered_map<UnMapKey1, UnMapKey2, UnMapKey3> &mapName,
    const char *sepChar = " ") {
  for (const auto &arrVar : mapName) {
    std::cout << arrVar.first << sepChar << arrVar.second << std::endl;
  }
}

template <typename MapKey1, typename MapKey2, typename MapKey3>
void PrintAll(const std::map<MapKey1, MapKey2, MapKey3> &mapName,
              const char *sepChar = " ") {
  for (const auto &arrVar : mapName) {
    std::cout << arrVar.first << sepChar << arrVar.second << std::endl;
  }
}

template <typename ArrType>
void PrintAll(const ArrType &arrName, const char *sepChar = " ") {
  for (const auto &arrVar : arrName) {
    std::cout << arrVar << sepChar;
  }
  std::cout << std::endl;
}
} // namespace star

#undef P_HEADERS
