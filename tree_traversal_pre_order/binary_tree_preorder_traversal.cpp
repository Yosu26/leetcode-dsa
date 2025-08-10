#include <vector>
#include <stack>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // Recursive helper function
    void preorderHelper(TreeNode* root, std::vector<int>& result) {
        if (!root) return;
        
        result.push_back(root->val);    // Visit node
        preorderHelper(root->left, result);   // Traverse left
        preorderHelper(root->right, result);  // Traverse right
    }

public:
    // Recursive solution
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        preorderHelper(root, result);
        return result;
    }

    // Iterative solution using stack
    std::vector<int> preorderTraversalIterative(TreeNode* root) {
        std::vector<int> result;
        if (!root) return result;
        
        std::stack<TreeNode*> stack;
        stack.push(root);
        
        while (!stack.empty()) {
            TreeNode* current = stack.top();
            stack.pop();
            
            result.push_back(current->val);  // Visit node
            
            // Push right first (so it's processed after left)
            if (current->right) {
                stack.push(current->right);
            }
            if (current->left) {
                stack.push(current->left);
            }
        }
        
        return result;
    }
};