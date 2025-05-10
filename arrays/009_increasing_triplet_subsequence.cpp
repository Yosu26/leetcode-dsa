#include <iostream>
#include <limits>
#include <vector>

class Solution{
    public:
        bool increasingTriplet(std::vector<int>& nums){
            int first = std::numeric_limits<int>::max();
            int second = std::numeric_limits<int>::max();

            for (int num : nums){
                if(num <= first){
                    first = num;
                }
                else if(num <= second){
                    second = num;
                }else{
                    return true;
                }
            }
            return false;
        }
};