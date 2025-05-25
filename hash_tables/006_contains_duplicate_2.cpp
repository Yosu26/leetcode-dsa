#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> last_index;
        for(int i = 0; i < nums.size(); ++i){
            if(last_index.find(nums[i]) != last_index.end()){
                if(i - last_index[nums[i]] <= k){
                    return true;
                }
            }
            last_index[nums[i]] = i;
        }
        return false;
    }
};