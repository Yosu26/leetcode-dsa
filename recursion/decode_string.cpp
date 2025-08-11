#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
private:
    string decode(const string& s, int& i) {
        string result;
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int k = 0;
                while (i < s.size() && isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                i++; // skip '['
                string decoded = decode(s, i);
                i++; // skip ']'
                while (k-- > 0) result += decoded;
            } else {
                result += s[i++];
            }
        }
        return result;
    }
};