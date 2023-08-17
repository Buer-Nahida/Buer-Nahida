#include <iostream>
using namespace std;

class Cube {
  double c_H, c_L, c_W;

public:
  void setCube(double Height, double Length, double Width) {
    c_H = Height;
    c_L = Length;
    c_W = Width;
  }
  double calcS() { return 2 * (c_L * c_W + c_W * c_H + c_L * c_H); }
  double calcV() { return c_L * c_W * c_H; }
  double getCube(char getOpts) {
    if (getOpts == 'H')
      return c_H;
    if (getOpts == 'W')
      return c_W;
    return c_L;
  }
  bool cubeSame(Cube &cubeName2) {
    if (c_L == cubeName2.c_L && c_W == cubeName2.c_W && c_H == cubeName2.c_H) {
      return true;
    }
    return false;
  }
};

bool isSame(Cube &cubeName0, Cube &cubeName1) {
  if (cubeName0.getCube('H') == cubeName1.getCube('H') &&
      cubeName0.getCube('L') == cubeName1.getCube('L') &&
      cubeName0.getCube('W') == cubeName1.getCube('W')) {
    return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  Cube cubeOne;
  cubeOne.setCube(10, 10, 10);
  Cube cubeTwo;
  cubeTwo.setCube(100, 9, 1);
  cout << "S:" << cubeOne.calcS() << endl
       << "V:" << cubeOne.calcV() << endl
       << "T or F?(class):" << cubeOne.cubeSame(cubeTwo) << endl
       << "T | F?(function):" << isSame(cubeOne, cubeTwo) << endl;
  return 0;
}
