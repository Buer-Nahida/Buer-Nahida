#include "headers/array.hpp"

class o {
public:
  int O = 0;
};

int main(int argc, char *argv[]) {
  Array<o> a(6);
  o o0;
  for (int i = 0; i < a.Lenger(); i++) {
    a.Add(o0);
  }
  for (int i = 0; i < a.Num(); i++) {
    cout << a[i].O << " ";
  }
  cout << endl;
  return 0;
}
