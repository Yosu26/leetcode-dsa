#include<iostream>
#include<vector>

class Solution{
    public:
    std::vector<int> singleNumber(std::vector<int>& nums){
        int xorALL = 0;
        for(int num : nums){
            xorALL ^= num;
        }
        unsigned int uxor = static_cast<unsigned int>(xorALL);
        unsigned int diffBit = uxor & (-uxor);

        int a = 0, b = 0;
        for(int num : nums){
            if(static_cast<unsigned int>(num) & diffBit){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return {a, b};
    }
};