#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

class Solution{
    public:
        int findMaxLength(vector<int>& nums){
            unordered_map<int, int> sumIndex;
            sumIndex[0] = -1;

            int sum = 0;
            int maxLen = 0;

            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] == 0){
                    sum += -1;
                }else{
                    sum += 1;
                }

                if(sumIndex.find(sum) != sumIndex.end()){
                    maxLen = max(maxLen, i - sumIndex[sum]);
                }else{
                    sumIndex[sum] = i;
                }
            }
            return maxLen;
        }
};