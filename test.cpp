#include "my/star.h"

class Test {
public:
  Test(string name, int age) {
    m_Name = name;
    m_Age = age;
  }
  Test(Test &&) = default;
  Test(const Test &) = default;
  Test &operator=(Test &&) = default;
  Test &operator=(const Test &) = default;
  ~Test() = default;
  string m_Name;
  int m_Age;
};

ostream &operator<<(ostream &outPut, Test &testClass) {
  outPut << testClass.m_Age << " " << testClass.m_Name;
  return outPut;
}

int main(int argc, char *argv[]) {
  string strHello = "xello";
  PrintArray(strHello, strHello.length(), "");
  return 0;
}
