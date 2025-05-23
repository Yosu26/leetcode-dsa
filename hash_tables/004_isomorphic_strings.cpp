#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

class Solution{
    public:
    bool isIsomorphic(std::string s, std::string t){
        std::unordered_map<char, char> s_to_t;
        std::unordered_map<char, char> t_to_s;

        for(int i = 0; i < s.size(); ++i){
            char c1 = s[i];
            char c2 = t[i];

            if(s_to_t.find(c1) != s_to_t.end()){
                if(s_to_t[c1] != c2){
                    return false;
                }
            }else if(t_to_s.find(c2) != t_to_s.end()){
                return false;
            }
            s_to_t[c1] = c2;
            t_to_s[c2] = c1;
        }
        return true;
    }
};