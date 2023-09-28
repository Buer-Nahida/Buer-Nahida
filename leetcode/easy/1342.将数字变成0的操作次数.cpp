#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Solution {
public:
  int numberOfSteps(int num) {
    if (num == 0)
      return this->count;
    ++this->count;
    if (num % 2 == 0)
      return this->numberOfSteps(num / 2);
    else
      return this->numberOfSteps(num - 1);
  }

private:
  unsigned long long count = 0;
};
