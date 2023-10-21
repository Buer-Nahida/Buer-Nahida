#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        for (auto var : s) {
            if (pairs.count(var)) {
                if (stk.empty() || stk.top() != pairs[var]) {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(var);
            }
        }
        return stk.empty();
    }

private:
    std::unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    std::stack<char> stk;
};
