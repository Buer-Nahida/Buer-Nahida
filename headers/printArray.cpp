#include "printArray.h"

void printArray(int *ArrName, int ArrWidth) {
  for (short Count = 0; Count <= ArrWidth - 1; Count++) {
    cout << ArrName[Count] << endl;
  }
}
