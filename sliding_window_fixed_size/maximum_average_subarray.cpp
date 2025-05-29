#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
    public:
    double findMaxAverage(std::vector<int>& nums, int k){
        double maxSum = 0;
        double windowSum = 0;

        for(int i = 0; i < k; ++i){
            windowSum += nums[i];
        }
        maxSum = windowSum;

        for(int i = k; i < nums.size(); ++i){
            windowSum += nums[i] - nums[i - k];
            maxSum = std::max(maxSum, windowSum);
        }
        return maxSum / k;
    }
};