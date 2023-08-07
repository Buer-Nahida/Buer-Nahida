#include "bubbleSort.h"

void bubbleSort(int *ArrName, bool AscendingSort, int ArrWidth) {
  for (int Count = ArrWidth - 1; Count > 0; Count--) {
    for (int Count0 = 0, Count1 = 1; Count1 <= Count; Count0++, Count1++) {
      if (AscendingSort == false) {
        if (ArrName[Count0] < ArrName[Count1]) {
          swap(ArrName[Count0], ArrName[Count1]);
        }
      } else {
        if (ArrName[Count0] > ArrName[Count1]) {
          swap(ArrName[Count0], ArrName[Count1]);
        }
      }
    }
  }
}
