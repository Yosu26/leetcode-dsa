#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Check if the input vector is valid.
        if (nums.empty()) return;

        //Initialize pointers for 0, 1, and 2.
        int red = 0, white = 0, blue = nums.size() - 1;

        //Using Dutch National Flag algorithm
        //Iterate through the array, moving 0s to the left and 2s to the right.
        while(white <= blue){
            if(nums[white] == 0){
                swap(nums[red], nums[white]);
                red++;
                white++;
            } else if (nums[white] == 1){
                white++;
            } else {
                swap(nums[white], nums[blue]);
                blue--;
            }
        }
    }
};
