#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int n1 = 1, n2 = 1;
    for (; n2 < 9 && n1 < 9;) {

        for (; n2 <= 9;) {

            if (n1 == n2) {
                cout << n1 << "x" << n2 << "=" << n1 * n2 << endl;
                n2++;
                n1 = 1;
            } else {
                cout << n1 << "x" << n2 << "=" << n1 * n2 << "\t";
                n1++;
            }
        }
        cout << endl;
    }

    return 0;
}
/*#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {
  for (int num1 = 1; num1 <= 9; num1++) {
    for (int num2 = 1; num2 <= num1; num2++) {
      std::cout << num1 << "x" << num2 << "=" << num1 * num2 << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}*/
