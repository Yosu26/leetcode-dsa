#include <climits>

// Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    bool isValidBST(TreeNode *root){
        return isValid(root, LONG_MIN, LONG_MAX);
    }
private:
    bool isValid(TreeNode *node, long min, long max){
        if (!node) return true;

        //Check if current node's value is within valid range
        if (node->val <= min || node->val >= max) return false;
        return isValid(node->left, min, node->val) && isValid(node->right, node->val, max);
    }
};