#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 1; i < heights.size(); ++i){
            int diff = heights[i] - heights[i - 1];

            if(diff <= 0)
                continue;
            
            minHeap.push(diff);

            if(minHeap.size() > ladders){
                bricks -= minHeap.top();
                minHeap.pop();
            }

            if(bricks < 0){
                return i - 1;
            }

        }
        return heights.size() - 1;
    }
};