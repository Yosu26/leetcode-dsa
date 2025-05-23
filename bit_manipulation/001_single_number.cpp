#include<iostream>
#include<vector>

class Solution{
    public:
    int singleNumber(std::vector<int>& nums){
        int result = 0;
        for(int i = 0; i < nums.size(); ++i){
            result = result ^ nums[i];
        }
        return result;
    }
};