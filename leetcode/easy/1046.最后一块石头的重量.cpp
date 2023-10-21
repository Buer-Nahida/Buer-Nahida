#include <queue>
#include <vector>

class Solution {
public:
    int lastStoneWeight(std::vector<short> &stones) {
        std::priority_queue<short> heap(stones.begin(), stones.end());
        for (;;) {
            short y = heap.top();
            heap.pop();
            if (heap.empty()) {
                return y;
            }
            short x = heap.top();
            heap.pop();
            if (x != y) {
                heap.push(y - x);
            }
        }
    }
};
