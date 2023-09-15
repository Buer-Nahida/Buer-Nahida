#include "my/star.h"
#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <vector>
namespace o {
class Te {
public:
  Te(std::string str, int age) {
    this->m_Str = str;
    this->m_Age = age;
  }
  Te(Te &&) = default;
  Te(const Te &) = default;
  Te &operator=(Te &&) = default;
  Te &operator=(const Te &) = default;
  ~Te() = default;
  bool operator==(const Te &a) const {
    if (this->m_Str == a.m_Str) {
      return this->m_Age == a.m_Age;
    }
    return false;
  }
  std::string m_Str;
  int m_Age;
};
} // namespace o

bool gr(const std::vector<int> &arrName) {
  for (int i = 0; i < arrName.size(); i++) {
    if (arrName[i] > arrName[i + 1]) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
#ifdef LAST
  std::vector<int> v{1, 2, 3, 4, 5}, v1{3, 1, 4, 5, 6, 7}, vsum;
  std::sort(v.begin(), v.end());
  std::sort(v1.begin(), v1.end());
  vsum.resize(std::max(v.size(), v1.size()));
  std::for_each(vsum.begin(),
                std::set_difference(v.begin(), v.end(), v1.begin(), v1.end(),
                                    vsum.begin()),
                [&](const int &var) { std::cout << var << ' '; });
  std::cout << std::endl;
  vsum.clear();
  vsum.resize(std::max(v.size(), v1.size()));
  std::for_each(vsum.begin(),
                std::set_difference(v1.begin(), v1.end(), v.begin(), v.end(),
                                    vsum.begin()),
                [&](const int &var) { std::cout << var << ' '; });
  std::cout << std::endl;
#endif
#ifndef FIRST
  std::array<int, 13> a;
#endif
  return 0;
}
