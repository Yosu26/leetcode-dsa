#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

class Solution{
    public:
    int maxNumberOfBallons(std::string text){
        std::unordered_map<char, int> count;

        for(char c : text){
            if(c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n'){
                count[c]++;
            }
        }

        count['l'] /= 2;
        count['o'] /= 2;

        return std::min({count['b'], count['a'], count['l'], count['o'], count['n']});
    }
};