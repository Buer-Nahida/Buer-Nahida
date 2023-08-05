#include "headers/star.h"

void func() {
  int *Arr = new int[10];
  for (int i = 0; i < 10; i++) {
    Arr[i] = i + 100;
  }
  for (int i = 0; i < 10; i++) {
    cout << Arr[i] << endl;
  }
}

int main(int argc, char *argv[]) {
  func();
  return 0;
}
