#include <vector>

class Solution {
public:
  int minCount(std::vector<int> &coins) {
    unsigned int ans = 0;
    for (int &var : coins) {
      for (;;) {
        if (var > 0) {
          var -= 2;
          ++ans;
        } else {
          break;
        }
      }
    }
    return ans;
  }
};
