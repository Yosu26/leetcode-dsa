// Definition of a binary tree code
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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return countPaths(root, targetSum) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);      
    }
private:
    int countPaths(TreeNode* node, long long sum){
        if(!node) return 0;
        int res = (node->val == sum) ? 1 : 0;
        res += countPaths(node->left, sum - node->val);
        res += countPaths(node->right, sum - node->val);
        return res;
    }
};