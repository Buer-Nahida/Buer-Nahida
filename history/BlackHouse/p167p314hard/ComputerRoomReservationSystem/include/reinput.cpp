#ifndef CRRS_INCLUDE_REINPUT_CPP_
#define CRRS_INCLUDE_REINPUT_CPP_
#include <ios>
#include <iostream>
#include <limits>

namespace crrs {
void reinput() {
    std::cerr << "ERROR: 无效选择，请重新输入\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
} // namespace crrs
#endif
