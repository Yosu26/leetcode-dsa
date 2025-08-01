#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = matrix.size() - 1;
        while(left < right){
            for(int i = 0; i < (right - left); ++i){
                int top = left, bottom = right;

                // Store the topLeft
                int topLeft = matrix[top][left + i];

                // move bottomLeft into topLeft
                matrix[top][left + i] = matrix[bottom - i][left];

                // move bottomRight into bottomLeft
                matrix[bottom - i][left] = matrix[bottom][right - i];

                // move topRight into bottomRight
                matrix[bottom][right - i] = matrix[top + i][right];

                // move topLeft into topRight
                matrix[top + i][right] = topLeft;
            }
            right--;
            left++;
        }
    }
};