#ifndef CRRS_INCLUDE_PAUSE_CPP_
#define CRRS_INCLUDE_PAUSE_CPP_

#include <cstdlib>
#include <iostream>

namespace crrs {
void pause_and_clear() {
#ifdef _WIN32
    std::system("pause");
    std::system("cls");
#else
    std::cout << "请按回车继续";
    std::cin.clear();
    std::cin.sync();
    std::cin.get();
    std::system("clear");
#endif
}
} // namespace crrs

#endif
