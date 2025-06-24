#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.size() < p.size()) return result;

        vector<int> pCount(26, 0), sCount(26, 0);
        int pLen = p.size();

        //Count frequency of characters in p
        for (char c : p){
            pCount[c - 'a']++;
        }

        //First window
        for(int i = 0; i < pLen; ++i){
            sCount[s[i] - 'a']++;
        }

        if(sCount == pCount){
            result.push_back(0);
        }

        //Sliding the window
        for(int i = pLen; i < s.size(); ++i){
            //Remove leftmost character of previous window
            sCount[s[i - pLen] - 'a']--;
            //Add new rightmost character
            sCount[s[i] - 'a']++;

            if(sCount == pCount){
                result.push_back(i - pLen + 1);
            }
        }
        return result;

    }
};