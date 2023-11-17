#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    short  m;
    string n;
    cin >> m >> n;
    short l = n.size();
    cout << n[0] << '*' << m << '^' << l - 1;
    for (short i = 1; i < l; ++i) {
        if (n[i] == '0') continue;
        cout << '+' << n[i] << '*' << m << '^' << l - i - 1;
    }
    cout << '\n';
    return 0;
}
