#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMin = nums[0], currentMax = nums[0];
        int maxSum = nums[0];

        //Traverse from the second element in the array
        for(int i = 1; i < nums.size(); ++i){
            int tmp = currentMax * nums[i];
            currentMax = std::max(nums[i], std::max((currentMax * nums[i]), (currentMin * nums[i])));
            currentMin = std::min(nums[i], std::min(tmp, (currentMin * nums[i])));
            maxSum = std::max(maxSum, currentMax);
        }
        return maxSum;
    }
};