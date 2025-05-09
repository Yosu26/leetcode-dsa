#include <iostream>
#include <vector>

class Solution{
    public:
        long long zeroFilledSubarray(std::vector<int>& nums){
            long long res = 0;
            int count = 0;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] == 0){
                    count +=1;
                }else{
                    count = 0;
                }
                res += count;
            }
            return res;
        }
};