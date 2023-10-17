#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    int Arr[5] = {300, 350, 200, 400, 250};
    /*
      for (int count = 0; count <= 4; count++) {
        cout << "第" << ++count << "只小猪的体重是：";
        cin >> Arr[--count];
      }
    */

    int Max = 0;
    double Max0;
    for (int count = 0; count < 5; count++) {
        Max = (Arr[Max] > Arr[Max + 1]) ? (Max) : (Max + 1);
        Max0 = (Arr[Max] > Arr[Max + 1]) ? (Arr[Max]) : (Arr[Max + 1]);
    }

    cout << "第" << ++Max << "只小猪最重，"
         << "它的体重是" << Max0 << endl;

    return 0;
}
