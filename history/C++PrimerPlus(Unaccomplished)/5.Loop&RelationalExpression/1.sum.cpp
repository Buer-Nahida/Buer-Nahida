#include <iostream>
using ll = long long;
using ull = unsigned long long;

int main(int argc, char *argv[]) {
  ll x, y;
  std::cin >> x >> y;
  ll sum = 0;
  if (x < y) {
    for (; x <= y; ++x) {
      sum += x;
    }
  } else if (x > y) {
    for (; y <= x; ++y) {
      sum += y;
    }
  } else {
    sum = x;
  }
  std::cout << sum << '\n';
  return 0;
}
