#include<iostream>
#include<vector>

class Solution{
    public:
    std::vector<int> singleNumber(std::vector<int>& nums){
        int xorALL = 0;
        for(int num : nums){
            xorALL ^= num;
        }
        int diffBit = xorALL & (-xorALL);
        int a = 0, b = 0;
        for(int num : nums){
            if(num & diffBit){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return {a, b};
    }
};