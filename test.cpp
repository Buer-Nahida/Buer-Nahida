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
  string str;

  char a[] = "Hello world!";
  string strCharArr;
  /* strCharArr = a; */

  /* strCharArr.assign("Hello Cpp"); */
  /* strCharArr.assign(a); */

  /* strCharArr.assign(a, 4); */
  strCharArr.assign("Hello Cpp", 5);
  cout << strCharArr << endl;

  string strStr;
  /* strStr = strCharArr; */
  strStr.assign(strCharArr);
  cout << strStr << endl;

  string strChar;
  /* strChar = 'a'; */
  strChar.assign(2, 'a');
  cout << strChar << endl;
  return 0;
}
