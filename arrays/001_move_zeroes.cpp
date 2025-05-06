#include <iostream>
#include <vector>

class Solution{
    public:
    void moveZeros(std::vector<int>& nums){
        int nonLastZeroIndex{};
        for(int i{}; i < nums.size(); ++i){
            if(nums[i] != 0){
                nums[nonLastZeroIndex++] = nums[i]; 
            }
        }
        for(int i = nonLastZeroIndex; i < nums.size(); ++i){
            nums[i] = 0;
        }
    }
};

