#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums){
            int n = nums.size();
            std::vector<int> result(n, 1); // Initialize a vector of size n with all elements set to 1
            int prefix = 1;
            for(int i = 0; i < n; ++i){
                result[i] = prefix;
                prefix *= nums[i];
            }
            int postfix = 1;
            for(int i = n - 1; i >= 0; --i){
                result[i] *= postfix;
                postfix *= nums[i];
            }
            return result;
        }
};