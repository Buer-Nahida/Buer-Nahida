#include <string>
#include <unordered_map>

class Solution {
public:
    std::string decodeMessage(std::string key, std::string message) {
        char ch = 'a';
        for (const char &chK : key) {
            if (this->m_MessageKey.empty() || !this->m_MessageKey.count(chK)) {
                if (chK != ' ') {
                    this->m_MessageKey.emplace(chK, ch);
                    ++ch;
                }
            }
        }
        for (char &var : message) {
            if (var != ' ') {
                var = this->m_MessageKey[var];
            }
        }
        return message;
    }

private:
    std::unordered_map<char, char> m_MessageKey;
};
