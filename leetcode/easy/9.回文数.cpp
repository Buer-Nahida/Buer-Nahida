#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        unsigned long long n = 10;
        int y = x;
        std::string s;
        while (y > 0) {
            n *= 10;
            y /= 10;
        }
        if (n == 10) {
            return true;
        }
        for (unsigned long long i = 10; i < n; i *= 10) {
            s.push_back(((x % i) / (i / 10)) ^ 48);
        }
        if (s.size() == 2) {
            if (s.front() == s.back()) {
                return true;
            }
        }
        for (std::string::const_iterator itBegin = s.cbegin(),
                                         itEnd = --s.cend();
             itBegin < itEnd; itBegin++, itEnd--) {
            if (*itBegin != *itEnd) {
                return false;
            }
        }
        return true;
    }
};
