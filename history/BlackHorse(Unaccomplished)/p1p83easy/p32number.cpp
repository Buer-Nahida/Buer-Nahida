#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int argc;
    cout << "欢迎来到猜数字游戏" << endl;
    cout << "正在生成数字中...\n" << endl;

    srand((unsigned long)time(NULL));
    argc = rand() % 100 + 1;

    cout << "生成完毕\n" << endl;

    short in;
    long long count = 1;

    cout << "游戏开始！" << endl;
    cout << "提示：这个数字在1-100之间（包括1和100）" << endl;

    while (1) {
        cout << "你已尝试" << count++ << "次\n"
             << "你猜这个数字是：";
        cin >> in;

        if (in == argc) {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n你猜对了" << endl;
            break;
        } else if (in > argc) {
            cout << "\n\n猜的大了" << endl;
        } else if (in < argc) {
            cout << "\n\n猜的小了" << endl;
        }
    }

    cout << "游戏结束" << endl;
    cout << "你一共试了" << count << "次\n" << endl;
    return 0;
}
