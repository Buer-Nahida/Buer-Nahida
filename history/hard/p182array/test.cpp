#include "headers/array.hpp"

int main(int argc, char *argv[]) {
  Array<string> a(6);
  a.Add("hello worlda");
  a.Add("hello worldb");
  a.Add("hello worldc");
  a.Add("hello worldd");
  a.Add("hello worlde");
  a.Add("hello worldf");
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
