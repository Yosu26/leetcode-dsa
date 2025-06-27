#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int maxLen = 0, start = 0;
        
        for(int end = 0; end < s.size(); ++end){
            char c = s[end];

            if(lastSeen.count(c) && lastSeen[c] >=start){
                start = lastSeen[c] + 1;
            }

            lastSeen[c] = end;
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};