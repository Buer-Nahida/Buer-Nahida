#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    short n;
    char  s[100], t[100];
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        if (s[i] < t[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << t << '\n';
    return 0;
}
