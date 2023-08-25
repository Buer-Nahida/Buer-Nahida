#pragma once
#include <iostream>
using namespace std;

template <typename T> void SelectSort(T &arrName, bool ascendingSort) {
  unsigned long long arrLenger = (sizeof arrName / sizeof arrName[0]);
  for (unsigned long long count0 = 0; count0 < arrLenger; count0++) {
    unsigned long long minOrMax = count0;
    for (unsigned long long count1 = count0; count1 < arrLenger; count1++)
      if (ascendingSort)
        minOrMax = (arrName[minOrMax] > arrName[count1]) ? count1 : minOrMax;
      else
        minOrMax = (arrName[minOrMax] < arrName[count1]) ? count1 : minOrMax;
    swap(arrName[minOrMax], arrName[count0]);
  }
}
