#include "selectSort.h"

void selectSort(int *ArrName, bool AscendingSort, int ArrLenger) {
  int Index = 0;
  for (int Count0 = 0; Count0 < ArrWidth; Count0++) {
    int Min = Count0;
    for (int Count1 = Index; Count1 < ArrWidth; Count1++) {
      if (AscendingSort == true) {
        Min = (ArrName[Min] > ArrName[Count1]) ? Count1 : Min;
      } else {
        Min = (ArrName[Min] < ArrName[Count1]) ? Count1 : Min;
      }
    }
    swap(ArrName[Min], ArrName[Count0]);
    Index++;
  }
}
