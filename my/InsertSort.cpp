#include "InsertSort.h"

void InsertSort(int *Arr, bool AscendingSort, int ArrLenger) {
  int x, j;
  for (int i = 0; i < ArrLenger; i++) {
    x = Arr[i];
    j = i - 1;
    while (j >= 0) {
      if (AscendingSort == true) {

        if (x <= Arr[j]) {
          Arr[j + 1] = Arr[j];
          j -= 1;
        } else
          break;
      } else {
        if (x >= Arr[j]) {
          Arr[j + 1] = Arr[j];
          j -= 1;
        } else
          break;
      }
    }
    Arr[j + 1] = x;
  }
}
