#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        diameterOfBinaryTreeHelper(root);
        return maxDiameter;
    }
private:
    int maxDiameter = 0;

    int diameterOfBinaryTreeHelper(TreeNode* node){
        if (!node) return 0;
        int left = diameterOfBinaryTreeHelper(node->left);
        int right = diameterOfBinaryTreeHelper(node->right);

        maxDiameter = max(maxDiameter, left + right);
        return 1 + max(left, right);
    }
};