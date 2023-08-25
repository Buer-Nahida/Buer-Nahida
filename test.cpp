#include "my/star.h"

int main(int argc, char *argv[]) {
  double b[] = {1.1, 1.9, 4.1, 5.9, 1.8, 4.1};
  PrintArray(b);
  BubbleSort(b, 0);
  PrintArray(b);
  double a[] = {1.1, 1.9, 4.1, 5.9, 1.8, 4.1};
  PrintArray(a);
  SelectSort(a, 0);
  PrintArray(a);
  return 0;
}
