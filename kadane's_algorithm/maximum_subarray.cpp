#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maxSubarray(vector<int>& nums){
        int currentSum = nums[0];
        int maxSum = nums[0];

        //Traverse the array from the second element
        for(int i = 1; i < nums.size(); ++i){
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};