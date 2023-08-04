#include <bits/stdc++.h>
using namespace std;

struct Heros {
  string Name;
  int Age;
  string Sex;
};

void bubbleSort(Heros *ArrName, bool AscendingSort, int ArrWidth) {
  for (int Count = ArrWidth - 1; Count > 0; Count--) {
    for (int Count0 = 0, Count1 = 1; Count1 <= Count; Count0++, Count1++) {
      if (AscendingSort == false) {
        if (ArrName[Count0].Age < ArrName[Count1].Age) {
          swap(ArrName[Count0], ArrName[Count1]);
        }
      } else {
        if (ArrName[Count0].Age > ArrName[Count1].Age) {
          swap(ArrName[Count0], ArrName[Count1]);
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  Heros Heros[5] = {
      {"刘备", 23, "男"}, {"关羽", 22, "男"}, {"张飞", 20, "男"},
      {"赵云", 21, "男"}, {"貂蝉", 19, "女"},
  };
  bubbleSort(Heros, true, 5);
  for (int I = 0; I < 5; I++) {
    cout << "Name:" << Heros[I].Name << " Age:" << Heros[I].Age
         << " Sex:" << Heros[I].Sex << endl;
  }
  return 0;
}
