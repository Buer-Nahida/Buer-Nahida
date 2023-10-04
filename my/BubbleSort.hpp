#pragma once
#include <array>
#include <iostream>

namespace star {
template <typename T, unsigned long long arrLenger>
void BubbleSort(std::array<T, arrLenger> &arrName, bool ascendingSort = 0) {
    for (unsigned long long count0 = arrLenger - 1; count0 > 0; count0--)
        for (unsigned long long count1 = 0; count1 < count0; count1++)
            if (ascendingSort) {
                if (arrName[count1] > arrName[count1 + 1])
                    std::swap(arrName[count1], arrName[count1 + 1]);
            } else {
                if (arrName[count1] < arrName[count1 + 1])
                    std::swap(arrName[count1], arrName[count1 + 1]);
            }
}
} // namespace star
