#include<iostream>
#include<string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string newString{};
        int n = s.size();
        for(int i = 0; i < n; ++i){
            if(isalnum(s[i])){
                newString += tolower(s[i]);
            }
        }
        int left = 0;
        int right = newString.size() - 1;
        while(left < right){
            if(newString[left] != newString[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};