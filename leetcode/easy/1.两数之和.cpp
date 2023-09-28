#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++)
      for (int j = 0; j < nums.size(); j++)
        if (nums[i] + nums[j] == target)
          if (i != j)
            return {i, j};
    return {};
  }
};
