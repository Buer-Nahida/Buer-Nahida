#include "my/star.h"
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    array<int, 3> j{4, 5, 1};
    array<int, 6> i{5, 1, 3, 6, 3, 8};
    array<int, 9> x{};
    merge(i.begin(), i.end(), j.begin(), j.end(), x.begin());
    star::PrintAll(x);
    MergeSort<int, 9>(x);
    star::PrintAll(x);
    return 0;
}
