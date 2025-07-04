#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int i = 0, j = 0;
        int direction = 0; // 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP

        int up_wall = 0;
        int right_wall = n;
        int down_wall = m;
        int left_wall = -1;

        while(ans.size() != (m * n)){
            if(direction == 0){ // RIGHT
                while(j < right_wall){
                    ans.push_back(matrix[i][j++]);
                }
                i++;
                j--;
                right_wall--;
                direction = 1;
            } else if(direction == 1){ // DOWN
                while(i < down_wall){ 
                    ans.push_back(matrix[i++][j]);
                }
                i--;
                j--;
                down_wall--;
                direction = 2;
            } else if(direction == 2){ // LEFT
                while(j > left_wall){
                    ans.push_back(matrix[i][j--]);
                }
                i--;
                j++;
                left_wall++;
                direction = 3;
            } else { // UP
                while(i > up_wall){
                    ans.push_back(matrix[i--][j]);
                }
                i++;
                j++;
                up_wall++;
                direction = 0;
            }
        }
        return ans;
    }
};