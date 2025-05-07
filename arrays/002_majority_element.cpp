#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
    public:
        int majorityElement(std::vector<int>& nums){
            std::unordered_map<int, int> countMap;
            int n = nums.size();
            for(int i{}; i < n; ++i){
                countMap[nums[i]]++;
                if(countMap[nums[i]] > n/2){
                    return nums[i];
                }
            }
            return -1;
        }
};
