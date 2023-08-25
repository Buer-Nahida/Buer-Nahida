#include "headers/all.h"

int main(int argc, char *argv[]) {
  Circle c1;
  c1.setR(10);
  Point Center;
  Center.setX(10);
  Center.setY(0);
  c1.setCenter(Center);
  Point p1;
  p1.setX(10);
  p1.setY(10);
  cout << isInCircle(c1, p1) << endl;
  return 0;
}
