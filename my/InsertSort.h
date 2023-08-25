#pragma once
#include <iostream>
using namespace std;

template <typename T> void InsertSort(T &arrName, bool ascendingSort) {
  unsigned long long count1, arrLenger = (sizeof arrName / sizeof arrName[0]);
  T arrTemp;
  for (int count0 = 0; count0 < arrLenger; count0++) {
    arrTemp[0] = arrName[count0];
    count1 = count0 - 1;
    while (count1 >= 0) {
      if (ascendingSort) {
        if (arrTemp[0] <= arrName[count1]) {
          arrName[count1 + 1] = arrName[count1];
          count1 -= 1;
        } else
          break;
      } else {
        if (arrTemp[0] >= arrName[count1]) {
          arrName[count1 + 1] = arrName[count1];
          count1 -= 1;
        } else
          break;
      }
    }
    arrName[count1 + 1] = arrTemp[0];
  }
}
