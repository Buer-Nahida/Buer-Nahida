#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Calc {
public:
  double calculator(double Num0, string oper, double Num1) {
    c_Number0 = Num0;
    c_Number1 = Num1;
    return getResult(oper);
  }

  double c_Number0, c_Number1;

  double getResult(string h) {
    if (h == "+") {
      return c_Number0 + c_Number1;
    } else if (h == "-") {
      return c_Number0 - c_Number1;
    } else if (h == "*") {
      return c_Number0 * c_Number1;
    } else if (h == "/") {
      return c_Number0 / c_Number1;
    } else if (h == "^") {
      return pow(c_Number0, c_Number1);
    }
    return 0;
  }
};

int main(int argc, char *argv[]) {
  Calc C1;
  cout << C1.calculator(10, "+", 10) << endl;
  return 0;
}
