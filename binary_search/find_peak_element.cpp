#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + ((right - left) / 2);

            if(mid > 0 && nums[mid] < nums[mid - 1]){ // Check if left neighbor greater
                right = mid - 1;
            } else if(mid < nums.size() - 1 && nums[mid] < nums[mid + 1]){ // Check if right neighbor greater
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};