#include <iostream>
#include <vector>

class Solution{
    public:
        int removeDuplicates(std::vector<int>& nums){
            int n = nums.size();
            if(n < 2){
                return n;
            }else{
                int write_index = 0;
                for(int i{}; i < n; ++i){
                    if(nums[i] != nums[write_index]){
                        write_index++;
                        nums[write_index] = nums[i];
                    }
                }
                return write_index+1;
            }
        }
};