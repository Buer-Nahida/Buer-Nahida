#ifndef CRRS_INCLUDE_ORDER_HPP_
#define CRRS_INCLUDE_ORDER_HPP_

#include <string>

namespace crrs {
struct order {
    short              day;
    short              intervak;
    unsigned long long studentID;
    std::string        studentName;
    unsigned long long roomID;
    short              status;
};
} // namespace crrs

#endif
