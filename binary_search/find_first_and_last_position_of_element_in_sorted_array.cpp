#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findLeft(nums, target), findRight(nums, target)};
    }

    int findLeft(const vector<int>&nums, int target){
        int left = 0, right = nums.size() - 1, index = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if(nums[mid] == target) index = mid;
        }
        return index; 
    }

    int findRight(const vector<int>&nums, int target){
        int left = 0, right = nums.size() - 1, index = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if(nums[mid] == target) index = mid;
        }
        return index;
    }
};