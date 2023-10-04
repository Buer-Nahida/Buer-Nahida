#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs) {
        this->commonPrefix = strs.front();
        for (std::vector<std::string>::iterator it = strs.begin();
             it != strs.end(); it++) {
            if (it->size() < this->commonPrefix.size()) {
                this->commonPrefix = *it;
            }
        }
        for (int i = 0; i < this->commonPrefix.size(); i++) {
            for (auto &var : strs) {
                if (this->commonPrefix[i] != var[i]) {
                    commonPrefix.erase(this->commonPrefix.begin() + i,
                                       this->commonPrefix.end());
                    break;
                }
            }
        }
        return commonPrefix;
    }

private:
    std::string commonPrefix;
};
