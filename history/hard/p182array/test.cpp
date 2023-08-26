#include "headers/array.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  Array<int> a(6);
  a.Add(1);
  a.Add(1);
  a.Add(4);
  a.Add(5);
  a.Add(1);
  a.Add(4);
  for (int i = 0; i < a.Num(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << a.Lenger() << endl;
  cout << a[5] << endl;

  Array c(a);
  for (int i = 0; i < c.Num(); i++) {
    cout << c[i] << " ";
  }
  cout << endl;
  c.Delete();
  for (int i = 0; i < c.Num(); i++) {
    cout << c[i] << " ";
  }
  cout << endl;
  c = a;
  for (int i = 0; i < c.Num(); i++) {
    cout << c[i] << " ";
  }
  cout << endl;
  return 0;
}
