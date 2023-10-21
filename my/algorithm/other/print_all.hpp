#pragma once
#include <iostream>
#include <map>
#include <unordered_map>

namespace star {
template <typename Key, typename Type, typename Compare>
void print_all(const std::unordered_map<Key, Type, Compare> &mapName, const char *sepChar = " ") {
    for (const auto &[var0, var1] : mapName) {
        std::cout << var0 << sepChar << var1 << std::endl;
    }
}

template <typename Key, typename Type, typename Compare>
void print_all(const std::map<Key, Type, Compare> &mapName, const char *sepChar = " ") {
    for (const auto &[var0, var1] : mapName) {
        std::cout << var0 << sepChar << var1 << std::endl;
    }
}

template <typename Type> void print_all(const Type &name, const char *sepChar = " ") {
    for (const auto &arrVar : name) {
        std::cout << arrVar << sepChar;
    }
    std::cout << std::endl;
}
}
