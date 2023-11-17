#include <bits/stdc++.h>
using namespace std;
using u = unsigned;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (u i = 123, ii, iii, i1, i2, i3, j1, j2, j3, k1, k2, k3; i <= 329;
         ++i) {
        i1 = i % 10, i2 = i / 10 % 10, i3 = i / 100 % 10;
        ii = i * 2;
        j1 = ii % 10, j2 = ii / 10 % 10, j3 = ii / 100 % 10;
        iii = i * 3;
        k1 = iii % 10, k2 = iii / 10 % 10, k3 = iii / 100 % 10;
        if (i1 == 0 || i2 == 0 || i3 == 0 || k1 == 0 || k2 == 0 || k3 == 0 ||
            j1 == 0 || j2 == 0 || j3 == 0 || i1 == i2 || i1 == i3 || i2 == i3 ||
            j1 == j2 || j1 == j3 || j2 == j3 || j1 == i1 || j1 == i2 ||
            j1 == i3 || j2 == i1 || j2 == i2 || j2 == i3 || j3 == i1 ||
            j3 == i2 || j3 == i3 || k1 == k2 || k1 == k3 || k2 == k3 ||
            k1 == j1 || k1 == j2 || k1 == j3 || k2 == j1 || k2 == j2 ||
            k2 == j3 || k3 == j1 || k3 == j2 || k3 == j3 || k1 == i1 ||
            k1 == i2 || k1 == i3 || k2 == i1 || k2 == i2 || k2 == i3 ||
            k3 == i1 || k3 == i2 || k3 == i3) {
            continue;
        }
        cout << i << ' ' << ii << ' ' << iii << '\n';
    }
    return 0;
}
