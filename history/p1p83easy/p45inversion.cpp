#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int Arr[] = {1, 3, 2, 5, 4};

  cout << "数组：" << endl;
  for (int End = sizeof(Arr) / sizeof(Arr[0]) - 1, Start = 0; Start <= End;
       Start++) {
    cout << Arr[Start] << ",";
  }

  int End = sizeof(Arr) / sizeof(Arr[0]) - 1;
  int Start = 0;
  int Temp;

  for (; Start <= End;) {
    Temp = Arr[Start];
    Arr[Start] = Arr[End];
    Arr[End] = Temp;
    Start += 1;
    End -= 1;
  }

  cout << endl << "逆置后：" << endl;
  for (Start = 0, End = sizeof(Arr) / sizeof(Arr[0]) - 1; Start <= End;
       Start++) {
    cout << Arr[Start] << ",";
  }

  cout << endl;

  return 0;
}
