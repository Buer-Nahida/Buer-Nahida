#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  for (argc = 1; argc <= 100; argc++) {

    if ((argc % 10 == 7) || (argc / 10 == 7) || (argc % 7 == 0)) {
      cout << "砰～" << endl;
    } else {
      cout << argc << endl;
    }
  }

  return 0;
}
