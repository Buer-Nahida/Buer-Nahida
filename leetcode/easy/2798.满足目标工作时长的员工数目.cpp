#include <vector>

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(std::vector<int> &hours, int target) {
        int count = 0;
        for (const auto &var : hours) {
            if (var >= target) {
                ++count;
            }
        }
        return count;
    }
};
