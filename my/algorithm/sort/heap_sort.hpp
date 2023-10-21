#pragma once
#include <queue>
#include <type_traits>

namespace star {
template <typename Type> void heap_sort(Type start, Type end) {
    std::priority_queue<std::remove_reference_t<decltype(*start)>> heap(start, end);
    for (; start != end; ++start) {
        *start = heap.top();
        heap.pop();
    }
}

template <typename Type, typename CompareRule>
void heap_sort(Type start, Type end, CompareRule heapCompareRule) {
    std::priority_queue<std::remove_reference_t<decltype(*start)>,
                        std::vector<std::remove_reference_t<decltype(*start)>>, CompareRule>
        heap(start, end);
    for (; start != end; ++start) {
        *start = heap.top();
        heap.pop();
    }
}
}
