#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minEatingSpeed(vector<int>& piles, int h){
        int left = 1; // Minimum possible eating speed
        int right = *max_element(piles.begin(), piles.end()); // Maximum possible eating speed is the largest pile

        while(left < right){
            int mid = left + (right - left) / 2;
            int hours = 0;

            for(auto p : piles){
                hours += (p + mid - 1) / mid;
            }

            // If we can finish within h hours at this speed
            if(hours <= h){
                // Try to find a smaller valid speed
                right = mid;
            } else {
                // Too slow — try a higher speed
                left = mid + 1;
            }
        }
        return left;
    }
};