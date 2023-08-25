#include "my/star.h"

template <typename T> void Added(T a, T b) { cout << "m" << endl; }
void Added(int a, int b) { cout << "p" << endl; }

int main(int argc, char *argv[]) {
  Added('c', 'a');
  return 0;
}
