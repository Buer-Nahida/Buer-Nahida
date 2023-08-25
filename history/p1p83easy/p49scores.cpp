#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  int Scores[3][3] = {
      {100, 100, 100},
      {90, 50, 100},
      {60, 70, 80},
  };
  int Sum;
  string Name[3] = {"张三", "李四", "王五"};

  for (short H = 0; H < sizeof(Scores) / sizeof(Scores[0]); H++) {
    Sum = 0;

    for (short W = 0; W < sizeof(Scores[0]) / sizeof(Scores[0][0]); W++) {
      Sum += Scores[H][W];
    }

    cout << Name[H] << "的总成绩是" << Sum << endl;
  }
  return 0;
}
