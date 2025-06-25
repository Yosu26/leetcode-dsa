#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    bool checkInclusion(string s1, string s2){
        int len1 = s1.size(), len2 = s2.size();
        if(len1 > len2) return false;

        vector<int> count1(26, 0), count2(26, 0);

        //Count character in s1
        for(char c : s1)
            count1[c - 'a']++;

        //Count first window in s2
        for(int i = 0; i < len1; ++i){
            count2[s2[i] - 'a']++;
        }

        //Check if the first window is a match
        if(count1 == count2) return true;

        //Slide the window
        for(int i = len1; i < len2; ++i){
            count2[s2[i] - 'a']++;          //Add new char
            count2[s2[i - len1] - 'a']--;   //Remove new char

            if (count1 == count2) return true;
        }

        return false;
    }
};