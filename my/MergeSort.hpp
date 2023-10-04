#pragma once
#include <algorithm>
#include <array>

using ull = unsigned long long;

template <typename T, ull L> void MergeSort(std::array<T, L> &arr) {
    if (arr.max_size() == 1) {
        return;
    }
    if (L % 2 == 0) {
        std::array<T, L / 2> arr0, arr1;
        for (ull i = 0; i < arr0.max_size(); ++i) {
            arr0[i] = arr[i];
        }
        for (ull i = arr0.max_size(); i < L; ++i) {
            arr1[i - arr0.max_size()] = arr[i];
        }
        MergeSort<T, L / 2>(arr0), MergeSort<T, L / 2>(arr1);
        std::merge(arr0.begin(), arr0.end(), arr1.begin(), arr1.end(), arr.begin());
    } else {
        std::array<T, (L / 2) + 1> arr0;
        std::array<T, (L / 2)> arr1;
        for (ull i = 0; i < arr0.max_size(); ++i) {
            arr0[i] = arr[i];
        }
        for (ull i = 0; i < arr1.max_size(); ++i) {
            arr1[i] = arr[arr0.max_size() + i];
        }
        MergeSort<T, (L / 2) + 1>(arr0), MergeSort<T, L / 2>(arr1);
        std::merge(arr0.begin(), arr0.end(), arr1.begin(), arr1.end(), arr.begin());
    }
}
