#pragma once
#include <iostream>
using namespace std;

template <typename T> void BubbleSort(T &arrName, bool AscendingSort = 0) {
  unsigned long long arrLenger = (sizeof arrName / sizeof arrName[0]);
  for (unsigned long long count = arrLenger - 1; count > 0; count--)
    for (unsigned long long count0 = 0, count1 = 1; count1 <= count;
         count0++, count1++)
      if (AscendingSort) {
        if (arrName[count0] > arrName[count1])
          swap(arrName[count0], arrName[count1]);
      } else {
        if (arrName[count0] < arrName[count1])
          swap(arrName[count0], arrName[count1]);
      }
}
