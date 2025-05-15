#include <iostream>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        std::string res = "";
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.size(); j += cycleLen) {
                res += s[j];

                // Add diagonal element for middle rows
                int secondIndex = j + cycleLen - 2 * i;
                if (i != 0 && i != numRows - 1 && secondIndex < s.size()) {
                    res += s[secondIndex];
                }
            }
        }

        return res;
    }
};
