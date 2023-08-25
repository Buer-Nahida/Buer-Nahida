#include "my/star.h"

#ifdef Lenger
template <typename T, unsigned M> int len(T (&t)[M]) {
  return sizeof(t) / sizeof(*t);
}
#endif

int main(int argc, char *argv[]) {
  double a[] = {1.1, 1.9, 4.1, 5.9, 1.8, 4.1};
  PrintArray(a);
  SelectSort(a, 0);
  PrintArray(a);
  double b[] = {1.1, 1.9, 4.1, 5.9, 1.8, 4.1};
  PrintArray(b);
  BubbleSort(b, 0);
  PrintArray(b);
  return 0;
}
