#include<iostream>
#include<string>
#include<unordered_map>

class Solution{
    public:
    bool canConstruct(std::string ransomNote, std::string magazine){
        std::unordered_map<char, int> count;
        for(char c : magazine){
            count[c]++;
        }

        for(char c : ransomNote){
            if(count[c] > 0){
                count[c]--;
            }else{
                return false;
            }
        }
        return true;
    }
};