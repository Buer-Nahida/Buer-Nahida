#define P_HEADERS
#ifdef P_HEADERS
#include <iostream>
#include <map>
#include <unordered_map>
#endif // Headers

namespace star {
template <typename UD_MapKey1, typename UD_MapKey2, typename UD_MapKey3>
void PrintAll(
    const std::unordered_map<UD_MapKey1, UD_MapKey2, UD_MapKey3> &mapName,
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
