#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> map;
        for(string word : strs){
            string sorted = word;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(word);
        }
        vector<vector<string>> result;
        for(auto& pair : map){
            result.push_back(pair.second);
        }
        return result;
    } 
};