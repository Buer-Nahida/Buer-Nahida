#include "my/PrintAll.hpp"
#include "my/star.h"
#include <algorithm>
#include <bits/types/clock_t.h>
#include <ctime>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(int argc, char *argv[]) {
  long double delay;
  cin >> delay;
#ifdef DEBUG
  cout << delay << '\n';
#endif // DEBUG
  delay *= CLOCKS_PER_SEC;
#ifdef DEBUG
  cout << delay << '\n';
#endif // DEBUG
  clock_t start = clock();
#ifdef DEBUG
  cout << start << '\n';
#endif // DEBUG
  while (clock() - start < delay)
    ;
  return 0;
}
