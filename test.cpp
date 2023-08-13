#include "my/star.h"

class Test {
public:
  int t_A;
  int t_B;
  Test operator+(Test &p) {
    Test temp;
    temp.t_A = this->t_A + p.t_A;
    temp.t_B = this->t_B + p.t_B;
    return temp;
  }

private:
};

int main(int argc, char *argv[]) {
  Test T0;
  T0.t_A = 10;
  T0.t_B = 20;
  Test T1;
  T1.t_A = 10;
  T1.t_B = 20;
  Test T2 = T0 + T1;
  std::cout << T2.t_A << " " << T2.t_B << std::endl;
  return 0;
}
