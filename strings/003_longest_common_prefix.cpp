#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string res = "";
        if (strs.empty()) return res;

        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (const std::string& s : strs) {
                if (i == s.size() || s[i] != c) {
                    return res;
                }
            }
            res += c;
        }
        return res;
    }
};