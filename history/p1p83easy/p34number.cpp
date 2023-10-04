#include <iostream>
using namespace std;

int main() {
    int argc, argc1 = 1, argc2 = 0, argc3 = 0, count = 0;

    do {
        argc = (argc1 * 100) + (argc2 * 10) + (argc3);

        if ((argc1 * argc1 * argc1 + argc2 * argc2 * argc2 +
             argc3 * argc3 * argc3) == argc) {
            count++;
            cout << argc << "是水仙花数" << endl;
        }

        if (argc3 < 9) {
            argc3++;
        } else if (argc3 == 9 && argc2 < 9) {
            argc2++;
            argc3 = 0;
        } else if (argc3 == 9 && argc2 == 9) {
            argc1++;
            argc2 = 0;
            argc3 = 0;
        } else if (argc2 == 9 && argc1 < 9) {
            argc1++;
            argc2 = 0;
        }

        if (argc == 999) {
            break;
        }
    } while (1);

    cout << "共有" << count << "个水仙花数" << endl;
    return 0;
}
