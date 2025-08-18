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

class BSTIterator {
private:
    std::stack<TreeNode*> stack;
    
    // Helper function to push all left nodes
    void pushLeft(TreeNode* node) {
        while (node) {
            stack.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* current = stack.top();
        stack.pop();
        
        // Push all left nodes of the right subtree
        if (current->right) {
            pushLeft(current->right);
        }
        
        return current->val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
};