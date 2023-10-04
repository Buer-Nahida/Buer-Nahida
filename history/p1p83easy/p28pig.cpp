#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    double A, B, C, Max0;
    char Max;
    string MaxS;
    cout << "小猪A的体重：";
    cin >> A;
    cout << "小猪B的体重：";
    cin >> B;
    cout << "小猪C的体重：";
    cin >> C;

    if (A == B && B == C)
        cout << "小猪们都一样重" << endl;

    else if ((A == B && A > C) || (B == C && B > A) || (A == C && A > B)) {
        if (A == B && A > C)
            MaxS = "小猪C最轻，A和B一样重";

        if (B == C && B > A)
            MaxS = "小猪A最轻，B和C一样重";

        if (A == C && A > B)
            MaxS = "小猪B最轻，A和C一样重";

        cout << MaxS << endl;
    }

    else {
        Max = (A > B) ? 'A' : 'B';
        Max0 = max(A, B);
        Max = (Max0 > C) ? Max : 'C';
        cout << "最重的小猪是:" << Max << endl;
    }

    return 0;
}
