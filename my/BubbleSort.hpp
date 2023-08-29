#pragma once
#include <iostream>

template <typename T>
void BubbleSort(T &arrName, bool ascendingSort = 0,
                unsigned long long arrLenger = (sizeof arrName /
                                                sizeof arrName[0])) {
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
