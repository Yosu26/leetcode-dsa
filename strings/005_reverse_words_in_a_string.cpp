#include<iostream>
#include<vector>
#include<sstream>
#include<string>

class Solution{
    public:
    std::string reverseWords(std::string s){
        std::istringstream iss(s);
        std::vector<std::string> words;
        std::string word;

        while(iss >> word){
            words.push_back(word);
        }

        std::string res;
        for(int i = words.size(); i >= 0; --i){
            res += words[i];
            if(i != 0){
                res += " ";
            }
        }
        return res;
    }
};