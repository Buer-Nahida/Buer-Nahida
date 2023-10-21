#pragma once
#include "../Other/Merge.hpp"
#include <iostream>
#include <type_traits>

namespace star {
template <typename Type> void MergeSort(Type iterStart, Type iterEnd) {
    if (++iterStart == iterEnd) {
        return;
    }
    --iterStart;
    unsigned long long lenger = 0;
    for (Type iterTemp = iterStart; iterTemp != iterEnd; ++iterTemp, ++lenger) {}
    Type iterMid = iterStart;
    if (lenger % 2 == 0) {
        std::remove_reference_t<decltype(*iterStart)> arr0[lenger / 2], arr1[lenger / 2];
        for (unsigned long long i = 0; i < lenger / 2; ++i, ++iterMid) {
            arr0[i] = *iterMid;
        }
        for (unsigned long long i = 0; i < lenger / 2; ++i, ++iterMid) {
            arr1[i] = *iterMid;
        }
        MergeSort(arr0, arr0 + lenger / 2), MergeSort(arr1, arr1 + lenger / 2);
        Merge(arr0, arr0 + lenger / 2, arr1, arr1 + lenger / 2, iterStart);
    } else {
        std::remove_reference_t<decltype(*iterStart)> arr0[lenger / 2], arr1[(lenger / 2) + 1];
        for (unsigned long long i = 0; i < lenger / 2; ++i, ++iterMid) {
            arr0[i] = *iterMid;
        }
        for (unsigned long long i = 0; i <= lenger / 2; ++i, ++iterMid) {
            arr1[i] = *iterMid;
        }
        MergeSort(arr0, arr0 + lenger / 2), MergeSort(arr1, arr1 + (lenger / 2) + 1);
        Merge(arr0, arr0 + lenger / 2, arr1, arr1 + (lenger / 2) + 1, iterStart);
    }
}
}