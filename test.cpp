#include <algorithm>
#include <any>
#include <array>
#include <cmath>
#include <ios>
#include <iostream>
#include <ostream>
#include <random>

#include "my/star.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define TEST1

#ifdef TEST1
template <typename T, ull L> ostream &operator<<(ostream &output, T (&arr)[L]) {
    output << '[';
    for (ull i = 0; i < L; ++i) {
        output << arr[i];
        if (i != L - 1) {
            output << ',' << ' ';
        }
    }
    output << ']';
    return output;
}

template <typename T, ull L> void SelectSort(T (&arr)[L]) {
    for (ull i = 0; i < L; ++i) {
        ull minValue = i;
        for (ull j = i + 1; j < L; ++j) {
            minValue = arr[minValue] > arr[j] ? j : minValue;
        }
        cout << arr << '\n';
        swap(arr[i], arr[minValue]);
    }
}

template <typename T, ull L> ll BinarySearch(T (&arr)[L], ll target) {
    ull left = 0, right = L - 1;
    while (left <= right) {
        ull mind = (left + right) / 2;
        if (arr[mind] == target) {
            return mind;
        } else if (arr[mind] < target) {
            left = mind + 1;
        } else {
            right = mind - 1;
        }
    }
    return -1;
}

ll GCD(ll num0, ll num1) {
    ll minNum = min(num0, num1), maxNum = max(num0, num1), MO = maxNum % minNum;
    if (!MO) {
        return minNum;
    }
    return GCD(minNum, MO);
}
#endif

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef TEST1
    int i[]{1, 1, 4, 5, 1, 4};
    SelectSort(i);
    cout << i << '\n';
    int index = BinarySearch(i, 5);
    cout << index << ' ' << i[index] << '\n';
    cout << GCD(252, 105) << '\n';
#endif
    return 0;
}
