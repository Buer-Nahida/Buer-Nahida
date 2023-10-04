#include <string>
#include <unordered_map>
#include <utility>

class Solution {
public:
    int romanToInt(std::string s) {
        for (std::string::const_iterator it = s.cbegin(); it != s.cend();
             it++) {
            short i = hash.find(*it)->second;
            if (it + 1 == s.cend()) {
                sum += i;
                break;
            }
            short iNext = hash.find(*(it + 1))->second;
            if (i >= iNext) {
                sum += i;
            } else {
                sum -= i;
            }
        }
        return sum;
    }

private:
    std::unordered_map<char, short> hash{
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };
    int sum = 0;
};
