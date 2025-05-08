#include <iostream>
#include <vector>

class Solution{
    private:
        void reverseRange(std::vector<int>& nums, int left, int right){
            while(left < right){
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }

    public:
        void rotate(std::vector<int>& nums, int k){
            int n = nums.size();
            k = k % n;

            reverseRange(nums, 0, n-1); //Reverse whole array
            reverseRange(nums, 0, k-1); //Reverse first k-elements
            reverseRange(nums, k, n-1); //Reverse the rest
        }
};