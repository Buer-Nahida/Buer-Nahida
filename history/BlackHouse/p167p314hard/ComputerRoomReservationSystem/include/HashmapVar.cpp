#ifndef CRRS_INCLUDE_HASHMAPVAR_CPP_
#define CRRS_INCLUDE_HASHMAPVAR_CPP_

#include "order.hpp"
#include <map>
#include <string>
#include <unordered_map>
#include <utility>

namespace crrs {
std::unordered_map<unsigned long long, std::pair<std::string, std::string>>
                                                 studentMap, teacherMap;
std::unordered_map<std::string, std::string>     administratorMap;
std::map<unsigned long long, unsigned long long> computerRoomMap;
std::unordered_map<std::string, crrs::order>     orderMap;
} // namespace crrs

#endif
