#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            //Check if left half is sorted
            if (nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1; // target is in the left sorted part
                } else {
                    left = mid + 1; // target is in the right half
                }
            }
            // Otherwise, the right half must be sorted
            else{
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1; // target is in the right sorted part
                } else {
                    right = mid - 1; // target is in the left half
                }
            }
        }
        return -1;
    }
};