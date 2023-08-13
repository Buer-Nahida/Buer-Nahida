#include "my/star.h"

class Test {
public:
  int t_A;
  int t_B;
  Test operator++() {
    ++this->t_A;
    ++this->t_B;
    return *this;
  }

private:
};

int main(int argc, char *argv[]) {
  Test T0;
  T0.t_A = 10;
  T0.t_B = 20;
  ++T0;
  std::cout << T0.t_A << " " << T0.t_B << std::endl;
  return 0;
}
