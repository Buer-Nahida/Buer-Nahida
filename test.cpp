#include <deque>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;
#define HELLOMAIN main
#define HELLODEFINE
#undef HELLOUNDEFINE

#ifndef HELLODEFINE
Hello ifndef
#endif // Hello comments
#ifdef HelloIfdef
#endif

    class helloClass {
public:
  helloClass(string hello) {}
  string helloString = "Hello World!";
};

struct helloStruct {
  helloStruct() { this->helloChar = '\n'; }
  char helloChar;
};

ostream &operator<<(ostream &helloOstream, helloClass &helloOperator) {
  helloOstream << helloOperator.helloString;
  return helloOstream;
}

template <typename T> void HelloTemplate(const T &helloReference) {
  for (auto helloAuto : helloReference) {
    cout << helloAuto;
  }
}

char helloFunc() { return '\n'; }

char helloFunc(helloStruct helloOverload) { return helloOverload.helloChar; }

int HELLOMAIN(int helloInt, char *helloCharArray[]) {
  helloClass helloWorld(*helloCharArray);
  vector<helloClass> helloVector{helloWorld};
  deque<helloClass> helloDeque, *helloPtr = &helloDeque;
  helloPtr->push_back(helloWorld);
  HelloTemplate(helloDeque);
  cout << helloFunc(helloStruct());
  return 0;
}
