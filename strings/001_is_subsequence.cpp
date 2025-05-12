#include <iostream>
#include <string>

class Solution{
    public:
        bool isSequence(std::string s, std::string t){
            int i = 0, j = 0;
            while(i < s.size() && j < t.size()){
                if(s[i] == t[j]){
                    i++;
                }
                j++;
            }
            if(i == s.size()){
                return true;
            }
            return false;
        }
};