#pragma once

namespace star {
template <typename Type> void bubble_sort(Type iterStart, Type iterEnd) {
    for (Type bounds = iterEnd; bounds != iterStart; --bounds) {
        for (Type iter = iterStart; iter != iterEnd;) {
            Type tempIter = iter;
            if (*tempIter > *++iter) {
                *tempIter ^= *iter ^= *tempIter;
            }
        }
    }
}

template <typename Type, typename CompareRule>
void bubble_sort(Type iterStart, Type iterEnd, CompareRule rule) {
    for (Type bounds = iterEnd; bounds != iterStart; --bounds) {
        for (Type iter = iterStart; iter != iterEnd;) {
            Type tempIter = iter;
            if (rule(*++iter, *tempIter)) {
                *tempIter ^= *iter ^= *tempIter;
            }
        }
    }
}
}
